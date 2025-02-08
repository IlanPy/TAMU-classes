#ifndef SORTED_PRIORITY_QUEUE_H
#define SORTED_PRIORITY_QUEUE_H

#include "AbstractPriorityQueue.h"

template <typename Type>
class SortedPriorityQueue : public AbstractPriorityQueue<Type> {
    private:
        Type *arr;
        int capacity;
        int size;

    public:
        SortedPriorityQueue();

        ~SortedPriorityQueue();

        void pq_insert(Type value);

        Type pq_delete();

        Type pq_get_min();

        int pq_size();
};

template <typename Type>
SortedPriorityQueue<Type>::SortedPriorityQueue() {
    arr = new Type[10];
    capacity = 10;
    size = 0;
}

template <typename Type>
SortedPriorityQueue<Type>::~SortedPriorityQueue(){
    delete[] arr;
}

template <typename Type>
void SortedPriorityQueue<Type>::pq_insert(Type value) {
    if(size == capacity){
        Type* new_arr = new Type[capacity*2];
        for(int i = 0; i < size; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = capacity*2;
    }
    Type swap_value = value;
    Type temp;
    for(int i = 0; i < size; i++){
        if(swap_value >= arr[i]){
            temp = arr[i];
            arr[i] = swap_value;
            swap_value = temp;
        }
    }
    arr[size++] = swap_value;
}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_delete(){
    if(size == 0){
        throw std::out_of_range("");
    }
    return arr[--size];
}

template <typename Type>
Type SortedPriorityQueue<Type>::pq_get_min(){
    if(size == 0){
        throw std::out_of_range("");
    }
    return arr[size-1];
}

template <typename Type>
int SortedPriorityQueue<Type>::pq_size(){
    return size;
}

#endif