// TODO: Implement this source file
//#include <iostream>
#include <fstream>
#include <tuple>
#include <stdexcept>
#include "MyString.h"

//constructors
MyString::MyString() : stringSize(0), stringCapacity(1), string(nullptr) {
    string = new char[1];
    string[0] = '\0';
}
MyString::MyString(const MyString& str) : stringSize(str.stringSize),
    stringCapacity(str.stringCapacity), string(nullptr) {
        string = new char[stringCapacity];
        for(int i = 0; i < stringCapacity; i++){
            string[i] = str.string[i];
        }
}
MyString::MyString(const char* s) : stringSize(0), stringCapacity(0),
    string(nullptr) {
    for(int i = 0; s[i] != '\0'; i++){
        stringCapacity++;
        stringSize++;
    }
    if(stringCapacity == 0){
        stringCapacity = 1;
        string = new char[stringCapacity];
        string[0] = '\0';
    } else{
        string = new char[++stringCapacity];
        for(int i = 0; i < stringCapacity; i++){
            string[i] = s[i];
        }
    }
}
//deconstructor
MyString::~MyString() {
    if(string != nullptr)
        delete[] string;
    string = nullptr;
    stringSize = 0;
    stringCapacity = 0;
}


//resize
void MyString::resize(size_t n){
    char* newString = nullptr;
    if(static_cast<int>(n) <= stringSize){
        newString = new char[n+1];
        for(int i = 0; i < static_cast<int>(n); i++){
            newString[i] = string[i];
        }
        stringSize = n;
        newString[n] = '\0';
        stringCapacity = n+1;
    } else{
        newString = new char[n];
        for(int i = 0; i < stringSize; i++){
            newString[i] = string[i];
        }
        for(int i = stringSize; i < static_cast<int>(n); i++){
            newString[i] = '\0';
        } 
        stringSize = stringSize;
        stringCapacity = n;
    }
    if(string!=nullptr){
        delete[] string;}
    string = newString;
    newString = nullptr;
}
size_t MyString::capacity() const{ 
    return stringCapacity;
}
size_t MyString::size() const{
    return stringSize;
}
size_t MyString::length() const noexcept{
    return stringSize;
}
const char* MyString::data() const noexcept{
    return string;
}
bool MyString::empty() const{
    if(stringSize == 0){
        return true;
    } else {
        return false;
    }
}
const char& MyString::front() const{
    return string[0];
}
const char& MyString::at(size_t pos) const{
    if(static_cast<int>(pos) >= stringSize){
        throw std::out_of_range("");
    }
    return string[pos];
}
void MyString::clear(){
    for(int i = 0; i < stringCapacity; i++){
        string[i] = '\0';
    }
    stringSize = 0;
}
std::ostream& operator<<(std::ostream& os, const MyString& str){
    const char* outputString = str.data();
    for(int i = 0; outputString[i] != '\0'; i++){
        os << outputString[i];
    }
    return os;
}
MyString& MyString::operator=(const MyString& str){
    if(this != &str){
        stringSize = str.stringSize;
        stringCapacity = str.stringCapacity;
        if(string!=nullptr){
            delete[] string;
        }
        string = new char[stringCapacity];
        for(int i = 0; i < stringCapacity; i++){
            string[i] = str.string[i];
        }
    }
    return *this;
}
MyString& MyString::operator+=(const MyString& str){
    int oldSize = stringSize;
    this->resize(stringSize+str.stringCapacity);
    stringSize = stringSize+str.stringSize;
    int j = 0;
    for(int i = oldSize; i < stringCapacity; i++){
        string[i] = str.string[j];
        j++;
    }
    return *this;
}
size_t MyString::find(const MyString& str, size_t pos) const{
    int j = 0;
    int count = 0;
    size_t index = 0;
    for(int i = pos; string[i] != '\0'; i++){
        if(string[i] == str.string[j]){
            if(count == 0) index = i;
            count++;
            j++;
        } else{
            count = 0;
            j = 0;
        }
        if(count == static_cast<int>(str.length())){
            return index;
        }
    }
    return -1;
}

bool operator==(const MyString& lhs, const MyString& rhs){
    bool is_equal = false;
    const char* lhs_string = lhs.data();
    const char* rhs_string = rhs.data();
    if(lhs.size() != rhs.size()){
        return is_equal;
    }
    for(int i = 0; lhs_string[i] != '\0'; i++){
        if(lhs_string[i] != rhs_string[i]){
            return is_equal;
        }
    }
    is_equal = true;
    return is_equal;
}
MyString operator+(const MyString& lhs, const MyString& rhs){
    MyString new_string(lhs);
    new_string += rhs;
    return new_string;
}