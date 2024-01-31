#ifndef STACK_DOUBLE_ARRAY_H
#define STACK_DOUBLE_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayDouble : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayDouble();

    ~StackArrayDouble();

    StackArrayDouble(const StackArrayDouble& other);

    StackArrayDouble& operator=(const StackArrayDouble& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here

template <typename T>
StackArrayDouble<T>::StackArrayDouble(){
    topIndex = -1;
    length = 1;
    data = new T[1];
}

template <typename T>
StackArrayDouble<T>::~StackArrayDouble(){
    delete[] data;
}

template <typename T>
StackArrayDouble<T>::StackArrayDouble(const StackArrayDouble& other) {
    length = other.length;
    topIndex = other.topIndex;
    data = new T[other.length];
    for(int i = 0; i <= other.topIndex; i++){
        data[i] = other.data[i];
    }
}

template <typename T>
StackArrayDouble<T>& StackArrayDouble<T>::operator=(const StackArrayDouble& other) {
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
bool StackArrayDouble<T>::isEmpty(){
    if(topIndex < 0){
        return true;
    }
    return false;
}

template <typename T>
int StackArrayDouble<T>::size(){
    return topIndex+1;
}

template <typename T>
T& StackArrayDouble<T>::top(){
    if(topIndex < 0){
        throw std::out_of_range("");
    }
    return data[topIndex];
}

template <typename T>
T StackArrayDouble<T>::pop(){
    if(topIndex < 0){
        throw std::out_of_range("");
    }
    return data[topIndex--];
}

template <typename T>
void StackArrayDouble<T>::push(const T& e){
    if(topIndex+1 == length){
        T* temp = new T[length*2];
        for(int i = 0; i <= topIndex; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        data[++topIndex] = e;
        length = length*2;
    } else{
        data[++topIndex] = e;
    }
}

#endif