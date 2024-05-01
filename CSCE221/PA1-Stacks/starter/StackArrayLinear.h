#ifndef STACK_LINEAR_ARRAY_H
#define STACK_LINEAR_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayLinear : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayLinear();

    ~StackArrayLinear();

    StackArrayLinear(const StackArrayLinear& other);

    StackArrayLinear& operator=(const StackArrayLinear& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackArrayLinear<T>::StackArrayLinear(){
    topIndex = -1;
    length = 1;
    data = new T[1];
}

template <typename T>
StackArrayLinear<T>::~StackArrayLinear(){
    delete[] data;
}

template <typename T>
StackArrayLinear<T>::StackArrayLinear(const StackArrayLinear& other) {
    length = other.length;
    topIndex = other.topIndex;
    data = new T[other.length];
    for(int i = 0; i <= other.topIndex; i++){
        data[i] = other.data[i];
    }
}

template <typename T>
StackArrayLinear<T>& StackArrayLinear<T>::operator=(const StackArrayLinear& other) {
    if(this != &other){
        length = other.length;
        topIndex = other.topIndex;
        delete[] data;
        data = new T[length];
        for(int i = 0; i <= topIndex; i++){
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
bool StackArrayLinear<T>::isEmpty(){
    if(topIndex < 0){
        return true;
    }
    return false;
}

template <typename T>
int StackArrayLinear<T>::size(){
    return topIndex+1;
}

template <typename T>
T& StackArrayLinear<T>::top(){
    if(topIndex < 0){
        throw std::out_of_range("");
    }
    return data[topIndex];
}

template <typename T>
T StackArrayLinear<T>::pop(){
    if(topIndex < 0){
        throw std::out_of_range("");
    }
    return data[topIndex--];
}

template <typename T>
void StackArrayLinear<T>::push(const T& e){
    if(topIndex+1 == length){
        T* temp = new T[length+10];
        for(int i = 0; i <= topIndex; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        data[++topIndex] = e;
        length = length+10;
    } else{
        data[++topIndex] = e;
    }
}

#endif