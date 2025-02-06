
#include "MyString.h"
#include <iostream>
#include <cstring> // For strlen, strcpy, memcpy
#include <algorithm> // For std::swap

// Default Constructor - Initializes an empty string
MyString::MyString() {
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// Parameterized Constructor - Initializes with a C-style string
MyString::MyString(const char *str) {
    length = strlen(str);
    data = new char[length + 1];
    std::memcpy(data, str, length + 1); // strcpy(data, str);
}

// Copy Constructor - Creates a deep copy of another MyString object
MyString::MyString(const MyString &other) {
    length = other.length;
    data = new char[length + 1];
    std::memcpy(data, other.data, length + 1); // strcpy(data, other.data);
}

// Destructor - Releases dynamically allocated memory
MyString::~MyString() {
    delete[] data;
}

// Returns the length of the string
int MyString::size() const {
    return length;
}

// Checks if the string is empty
bool MyString::empty() const {
    return length == 0;
}

// Converts all characters to uppercase
void MyString::toUpper() {
    for (int i = 0; i < length; ++i) {
        data[i] = toupper(data[i]);
    }
}

// Converts all characters to lowercase
void MyString::toLower() {
    for (int i = 0; i < length; ++i) {
        data[i] = tolower(data[i]);
    }
}

// Removes the last character from the string
void MyString::pop_back() {
    if (length > 0) {
        data[--length] = '\0';
    }
}

// Adds a character to the end of the string
void MyString::push_back(char ch) {
    char* newData = new char[length + 2];
    std::memcpy(newData, data, length); // strcpy(newData, data);
    newData[length] = ch;
    newData[length + 1] = '\0';
    delete[] data;
    data = newData;
    ++length;
}

// Finds the first occurrence of a substring
int MyString::find(const MyString &substr) const {
    if (substr.length > length) {
        return -1;
    }
    for (int i = 0; i <= length - substr.length; i++) {
        if (std::strncmp(data + i, substr.data, substr.length) == 0) {
            return i;
        }
    }
    return -1;
}

// Returns a C-style string representation
const char* MyString::c_str() const {
    return data;
}

// Returns a substring from the given start index and length
MyString MyString::substr(size_t start, size_t len) const {
    if (start >= length) {
        return MyString("");
    }
    if (start + len > length) {
        len = length - start;
    }
    char* sub = new char[len + 1];
    std::strncpy(sub, data + start, len);
    sub[len] = '\0';
    MyString result(sub);
    delete[] sub;
    return result;
}

// Appends another MyString to the current string
void MyString::append(const MyString &other) {
    *this += other;
}

// Erases a portion of the string
void MyString::erase(size_t pos, size_t len) {
    if (pos >= length) {
        throw std::out_of_range("Position out of range");
    }
    if (len > length - pos) {
        len = length - pos;
    }
    char *newData = new char[length - len + 1];
    std::strncpy(newData, data, pos);
    std::strcpy(newData + pos, data + pos + len);
    delete[] data;
    data = newData;
    length -= len;
}

// Reverses the string
void MyString::reverse() {
    std::reverse(data, data + length);
}

// Assignment operator for deep copying another MyString object
MyString &MyString::operator=(const MyString &other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    length = other.length;
    data = new char[length + 1];
    std::memcpy(data, other.data, length + 1); // strcpy(data, other.data);
    return *this;
}

// Concatenation operator (+=) for appending another MyString
MyString &MyString::operator+=(const MyString &other) {
    char *newData = new char[length + other.length + 1];
    std::memcpy(newData, data, length); // strcpy(newData, data);
    std::memcpy(newData + length, other.data, other.length + 1); // strcat(newData, other.data);
    delete[] data;
    data = newData;
    length += other.length;
    return *this;
}

// Accesses a character at a given index (Read-only)
char MyString::operator[](int index) const {
    if (index >= length) {
        return '\0';
    }
    return data[index];
}

// Overloaded output stream operator for printing MyString
std::ostream &operator<<(std::ostream &os, const MyString &str) {
    os << str.c_str();
    return os;
}