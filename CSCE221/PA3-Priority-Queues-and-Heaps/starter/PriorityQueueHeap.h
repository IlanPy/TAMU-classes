#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

using namespace std;

template <typename Type>
class PriorityQueueHeap : public AbstractPriorityQueue<Type> {
private:
    Type *arr;
    int capacity;
    int size;
    
    void minHeapify(int i);
    void bubbleUp(int i);
    int pq_parent(int i);

public:
    PriorityQueueHeap();

    ~PriorityQueueHeap();

    int pq_size();
    
    Type pq_get_min();

    void pq_insert(Type value);

    Type pq_delete();
};

// Your implementation here

template <typename Type>
PriorityQueueHeap<Type>::PriorityQueueHeap(){
    arr = new Type[10];
    capacity = 10;
    size = 0;
}

template <typename Type>
PriorityQueueHeap<Type>::~PriorityQueueHeap(){
    delete[] arr;
}

template <typename Type>
int PriorityQueueHeap<Type>::pq_size() {
    return size;
}

template <typename Type>
int PriorityQueueHeap<Type>::pq_parent(int i){
    if((i-1)%2 == 0){
        return (i-1)/2;
    }
    return (i-2)/2;
}

template <typename Type>
Type PriorityQueueHeap<Type>::pq_get_min(){
    if(size == 0){
        throw std::out_of_range("");
    }
    return arr[0];
}

template <typename Type>
void PriorityQueueHeap<Type>::pq_insert(Type x) {
    if(size == capacity){
        Type* new_arr = new Type[capacity*2];
        for(int i = 0; i < size; i++){
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        capacity = capacity*2;
    }
    arr[size] = x;
    bubbleUp(size++);
}


template <typename Type>
void PriorityQueueHeap<Type>::bubbleUp(int i){
    if(i > 0){
        int parent_i = pq_parent(i);
        if(arr[parent_i] > arr[i]){
            Type temp = arr[i];
            arr[i] = arr[parent_i];
            arr[parent_i] = temp;
            bubbleUp(parent_i);
        }
    }
}

template <typename Type>
Type PriorityQueueHeap<Type>::pq_delete(){
    if(size == 0){
        throw std::out_of_range("");
    }
    Type return_val = arr[0];
    arr[0] = arr[--size];
    minHeapify(0);
    return return_val;
}

template <typename Type>
void PriorityQueueHeap<Type>::minHeapify(int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int min = i;
    if(left < size && arr[left] < arr[min]){
        min = left;
    }
    if(right < size && arr[right] < arr[min]){
        min = right;
    }
    if(min != i){
        Type temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        minHeapify(min);
    }
}

#endif