#include <iostream>
#include <thread>
using namespace std;

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

void mergeSort(int * arr, int start, int end, int level) {
    if(end - start + 1 > 1){
        //determine middle index
        int mid = (start + end)/2;
        if(level > 0){
            level--;
            thread thread1(mergeSort, arr, start, mid, level);
            thread thread2(mergeSort, arr, mid + 1, end, level);
            thread1.join();
            thread2.join();
        } else{
            mergeSort(arr, start, mid, level);
            mergeSort(arr, mid + 1, end, level);
        }
        merge(arr, start, mid, end);
    }
}