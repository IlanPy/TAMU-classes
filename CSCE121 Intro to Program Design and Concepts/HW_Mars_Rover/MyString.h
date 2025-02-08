// TODO: Implement this header file
# ifndef MYSTRING_H
# define MYSTRING_H

#include <iostream>

class MyString {
    int stringSize;
    int stringCapacity;
    char* string;
    public:
        //constructors
        MyString();
        MyString(const MyString& str);
        MyString(const char* s);
        ~MyString(); //deconstructor
        void resize(size_t n); //resize
        size_t capacity() const; //capacity
        size_t size() const; //size
        size_t length() const noexcept; //length
        const char* data() const noexcept; //data
        bool empty() const; //empty
        const char& front() const; //front
        const char& at (size_t pos) const; //at
        void clear(); //clear
        MyString& operator=(const MyString& str);
        MyString& operator+=(const MyString& str);
        size_t find(const MyString& str, size_t pos = 0) const;
};

std::ostream& operator<<(std::ostream& os, const MyString& str); //operator<<
bool operator==(const MyString& lhs, const MyString& rhs);
MyString operator+(const MyString& lhs, const MyString& rhs);

# endif