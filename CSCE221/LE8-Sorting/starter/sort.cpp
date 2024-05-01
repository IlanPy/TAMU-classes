#include <iostream>
#include "SortedPriorityQueue.h"

using namespace std;

//Counting sort helper function
void countingSort(int *arr, int n, int digit){
    int i = 0;
    //store count
    int count[10] = {0};
    for(i = 0; i < n; i++){
        count[arr[i]/digit % 10]++;
    }
    //cumulate
    for(i = 1; i < 10; i++){
        count[i] = count[i] + count[i-1];
    }
    //rewrite into new_arr
    int* new_arr = new int[n];
    int key = 0, pos = 0;
    for(i = n-1; i > -1; i--){
        key = arr[i];
        pos = --count[key/digit % 10];
        new_arr[pos] = arr[i];
    }
    //copy array 
    for(int i = 0; i < n; i++){
        arr[i] = new_arr[i];
    }
    delete[] new_arr;
}

void radixSort(int *arr, int n) {
    //find max num
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int digit = 1;
    while(max / digit != 0){
        countingSort(arr, n, digit);
        digit *= 10;
    }
}


void insertionSort(int *arr, int n) {
    SortedPriorityQueue<int> queue;
    for(int i = 0; i < n; i++){
        queue.pq_insert(arr[i]);
    }
    for(int i = 0; i < n; i++){
        arr[i] = queue.pq_delete();
    }
}
