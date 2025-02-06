#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char *data;  // Pointer to character array storing the string
    int length;  // Length of the string

public:
    // Default Constructor - Initializes an empty string
    MyString();

    // Parameterized Constructor - Initializes with a C-style string
    MyString(const char *str);

    // Copy Constructor - Creates a deep copy of another MyString object
    MyString(const MyString &other);

    // Destructor - Releases dynamically allocated memory
    ~MyString();

    // Returns the length of the string
    int size() const;

    // Checks if the string is empty
    bool empty() const;

    // Converts all characters to uppercase
    void toUpper();

    // Converts all characters to lowercase
    void toLower();

    // Removes the last character from the string
    void pop_back();

    // Adds a character to the end of the string
    void push_back(char a);

    // Finds the first occurrence of a substring within the string
    int find(const MyString &substr) const;

    // Returns a C-style string representation
    const char *c_str() const;

    // Returns a substring from the given start index and length
    MyString substr(size_t start, size_t len) const;

    // Appends another MyString to the current string
    void append(const MyString &other);

    // Erases a portion of the string starting from a given position and length
    void erase(size_t pos, size_t len);

    // Reverses the string
    void reverse();

    // Assignment operator for deep copying another MyString object
    MyString &operator=(const MyString &other);

    // Concatenation operator (+=) for appending another MyString
    MyString &operator+=(const MyString &other);

    // Accesses a character at a given index (Read-only)
    char operator[](int index) const;

    // Overloaded output stream operator for printing MyString
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif // MYSTRING_H
