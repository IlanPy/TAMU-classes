#ifndef UNSORTED_PRIORITY_QUEUE_H
#define UNSORTED_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"

template <typename Type>
class UnsortedPriorityQueue : public AbstractPriorityQueue<Type> {
    private:
        Type *arr;
        int capacity;
        int size;

    public:
        UnsortedPriorityQueue();

        ~UnsortedPriorityQueue();

        void pq_insert(Type value);

        Type pq_delete();

        Type pq_get_min();

        int pq_size();
};

template <typename Type>
UnsortedPriorityQueue<Type>::UnsortedPriorityQueue() {
    arr = new Type[10];
    capacity = 10;
    size = 0;
}

template <typename Type>
UnsortedPriorityQueue<Type>::~UnsortedPriorityQueue(){
    delete[] arr;
}

template <typename Type>
void UnsortedPriorityQueue<Type>::pq_insert(Type value) {
    if(size == capacity){
        Type* new_arr = new Type[capacity*2];
        for(int i = 0; i < size; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = capacity*2;
    }
    arr[size++] = value;
}

template <typename Type>
Type UnsortedPriorityQueue<Type>::pq_delete(){
    if(size == 0){
        throw std::out_of_range("");
    }
    int min_i = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < arr[min_i]){
            min_i = i;
        }
    }
    Type return_val = arr[min_i];
    for(int i = min_i; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
    return return_val;
}

template <typename Type>
Type UnsortedPriorityQueue<Type>::pq_get_min(){
    if(size == 0){
        throw std::out_of_range("");
    }
    int min_i = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] < arr[min_i]){
            min_i = i;
        }
    }
    return arr[min_i];
}

template <typename Type>
int UnsortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif