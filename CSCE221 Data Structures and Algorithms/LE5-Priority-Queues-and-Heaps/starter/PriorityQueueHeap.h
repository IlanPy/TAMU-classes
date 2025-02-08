#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <iostream>

using namespace std;

template <typename Type, typename Compare = std::greater<Type>>
class PriorityQueueHeap {
private:
    Compare compare;
    Type *arr;
    int capacity;
    int size;

    void heapify(int i);
    void bubbleUp(int i);
    int pq_parent(int i);

public:
    PriorityQueueHeap();

    PriorityQueueHeap(const PriorityQueueHeap& other);

    PriorityQueueHeap(const Compare& comp);

    PriorityQueueHeap& operator=(const PriorityQueueHeap& other);

    ~PriorityQueueHeap();

    int pq_size();

    bool is_pq_empty();
    
    Type pq_top();

    void pq_insert(Type x);

    Type pq_delete();
};

// Your implementation here

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap() : compare() {
    arr = new Type[10];
    capacity = 10;
    size = 0;
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::~PriorityQueueHeap(){
    delete[] arr;
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap(const Compare& _comp) {
    arr = new Type[10];
    capacity = 10;
    size = 0;
    compare = _comp;
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>::PriorityQueueHeap(const PriorityQueueHeap& other) {
    arr = new Type[other.capacity];
    capacity = other.capacity;
    size = other.size;
    for(int i = 0; i < other.size; i++){
        arr[i] = other.arr[i];
    }
    compare = other.compare;
}

template <typename Type, typename Compare>
PriorityQueueHeap<Type, Compare>& PriorityQueueHeap<Type, Compare>::operator=(const PriorityQueueHeap& other) {
    if(this != &other){
        delete[] arr;
        arr = new Type[other.capacity];
        capacity = other.capacity;
        size = other.size;
        for(int i = 0; i < other.size; i++){
            arr[i] = other.arr[i];
        }
        compare = other.compare;
    }
    return *this;
}

template <typename Type, typename Compare>
int PriorityQueueHeap<Type, Compare>::pq_size() {
    return size;
}

template <typename Type, typename Compare>
bool PriorityQueueHeap<Type, Compare>::is_pq_empty(){
    if(size == 0){
        return true;
    }
    return false;
}

template <typename Type, typename Compare>
int PriorityQueueHeap<Type, Compare>::pq_parent(int i){
    if((i-1)%2 == 0){
        return (i-1)/2;
    }
    return (i-2)/2;
}

template <typename Type, typename Compare>
Type PriorityQueueHeap<Type, Compare>::pq_top(){
    if(is_pq_empty()){
        throw std::out_of_range("");
    }
    return arr[0];
}

template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::pq_insert(Type x) {
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
    bubbleUp(size);
    size++;
}


template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::bubbleUp(int i){
    if(i > 0){
        int parent_i = pq_parent(i);
        if(compare(arr[parent_i], arr[i]) == 1){
            Type temp = arr[i];
            arr[i] = arr[parent_i];
            arr[parent_i] = temp;
            bubbleUp(parent_i);
        }
    }
}

template <typename Type, typename Compare>
Type PriorityQueueHeap<Type, Compare>::pq_delete(){
    if(is_pq_empty()){
        throw std::out_of_range("");
    }
    Type return_val = arr[0];
    arr[0] = arr[--size];
    heapify(0);
    return return_val;
}

template <typename Type, typename Compare>
void PriorityQueueHeap<Type, Compare>::heapify(int i){
    if(2*i+1 < size && 2*i+2 < size){
        if(compare(arr[i], arr[2*i+1]) == 1 || compare(arr[i], arr[2*i+2]) == 1){
            int index_to_switch = 0;
            if(compare(arr[2*i+1], arr[2*i+2]) == 1){
                index_to_switch = 2*i+2;
            } else{
                index_to_switch = 2*i+1;
            }
            Type temp = arr[index_to_switch];
            arr[index_to_switch] = arr[i];
            arr[i] = temp;
            heapify(index_to_switch);
        }
    } else if(2*i + 1 < size){
        if(compare(arr[i], arr[2*i+1]) == 1){
            Type temp = arr[2*i+1];
            arr[2*i+1] = arr[i];
            arr[i] = temp;
        }
    }
}

#endif