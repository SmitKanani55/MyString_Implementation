#include <iostream>
#include <chrono> // For benchmarking time
#include <string> // For std::string
#include "MyString.h"

#ifdef __unix__
#include <sys/resource.h>
#endif

using namespace std;
using namespace std::chrono;

#ifdef __unix__
size_t getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}
#endif

void testMyString() {
    auto start = high_resolution_clock::now();
    size_t initialMemory = 0, finalMemory = 0;
    
    MyString s("Code Help");
    MyString t = "smit";

#ifdef __unix__
    initialMemory = getMemoryUsage();
#endif
    
    cout << "Original: " << s << endl;
    s.reverse();
    cout << "Reversed: " << s << endl;
    s.push_back('k');
    cout << "Push Back: " << s << endl;
    s.pop_back();
    cout << "Pop Back: " << s << endl;
    cout << "First Char: " << s[0] << endl;
    cout << "Find 'Help': " << s.find("Help") << endl;
    s += t;
    cout << "Concatenation: " << s << endl;
    s.erase(5, 4);
    cout << "Erase: " << s << endl;

#ifdef __unix__
    finalMemory = getMemoryUsage();
#endif

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "MyString Execution Time: " << duration.count() << " microseconds" << endl;

#ifdef __unix__
    cout << "MyString Memory Usage: " << (finalMemory - initialMemory) << " KB" << endl;
#endif
}

void testStdString() {
    auto start = high_resolution_clock::now();
    size_t initialMemory = 0, finalMemory = 0;

    string s_std("Code Help");
    string t_std = "smit";

#ifdef __unix__
    initialMemory = getMemoryUsage();
#endif

    cout << "Original: " << s_std << endl;
    reverse(s_std.begin(), s_std.end());
    cout << "Reversed: " << s_std << endl;
    s_std.push_back('k');
    cout << "Push Back: " << s_std << endl;
    s_std.pop_back();
    cout << "Pop Back: " << s_std << endl;
    cout << "First Char: " << s_std[0] << endl;
    cout << "Find 'Help': " << s_std.find("Help") << endl;
    s_std += t_std;
    cout << "Concatenation: " << s_std << endl;
    s_std.erase(5, 4);
    cout << "Erase: " << s_std << endl;

#ifdef __unix__
    finalMemory = getMemoryUsage();
#endif

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "std::string Execution Time: " << duration.count() << " microseconds" << endl;

#ifdef __unix__
    cout << "std::string Memory Usage: " << (finalMemory - initialMemory) << " KB" << endl;
#endif
}

int main() {
    cout << "Testing MyString" << endl;
    testMyString();
    cout << "\nTesting std::string" << endl;
    testStdString();
    return 0;
}
