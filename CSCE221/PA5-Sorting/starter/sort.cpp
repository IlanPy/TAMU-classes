#include <iostream>
#include <queue>
using namespace std;

void bubbleSort(int *arr, int size){
    int temp;
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }   
}

void heapSort(int *arr, int size){
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int i = 0;
    for(i = 0; i < size; i++){
        min_heap.push(arr[i]);
    }
    for(i = 0; i < size; i++){
        arr[i] = min_heap.top();
        min_heap.pop();
    }
}

void merge(int * arr, int start, int mid, int end){
    //make temp arrays
    int i = 0, j = 0;
    int * left_arr = new int[mid - start + 1 + 1];
    int * right_arr = new int[end - mid + 1];
    //assign values to array
    for(i = 0; i < mid - start + 1; i++){
        left_arr[i] = arr[start + i];
    } 
    for(i = 0; i < end - mid; i++){
        right_arr[i] = arr[mid + 1 + i];
    }
    //set sentinel values
    left_arr[mid - start + 1] = INT32_MAX;
    right_arr[end - mid] = INT32_MAX;
    i = 0, j = 0;
    //sort
    while((i + j) < (end - start + 1)){
        if(left_arr[i] <= right_arr[j]){
            arr[i + j + start] = left_arr[i];
            i = i + 1;
        } else{
            arr[i + j + start] = right_arr[j];
            j = j + 1;
        }
    }
    delete[] left_arr;
    delete[] right_arr;
}

void mergeSort(int * arr, int start, int end) {
    //determine middle index
    if(end - start + 1 > 1){
        int mid = (start + end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}


int partition(int *arr, int start, int end){
    //pivot = start
    int x = arr[start], i = start, j = end+1;
    while(i < j){
        do{
            i++;
        } while(i < end && arr[i] <= x);
        do{
            j--;
        } while(arr[j] > x);
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int *arr, int start, int end) {
    if(end - start + 1 <= 1){
        return;
    }
    int index = partition(arr, start, end);
    quickSort(arr, start, index - 1);
    quickSort(arr, index + 1, end);
}
