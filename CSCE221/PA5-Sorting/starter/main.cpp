#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>
#define TEST
#include "sort.cpp"
#include <math.h>
#include <fstream>

using namespace std;

enum SORT_TYPE {
    BUBBLE_SORT,
    HEAP_SORT,
    MERGE_SORT,
    QUICK_SORT
};

int testSort(SORT_TYPE sort_type, int n, string name) {
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=n; k++){
        for(int j = 1; j < 9; j+=3){
            int size = j*pow(10,k);
            int *arr = new int[size];
            for(int i=0; i<size; i++){
                arr[i] = rand() % 1000000 + 1;  // Random numbers between 1 and 10^6
            }
            auto start = std::chrono::high_resolution_clock::now();
            if (sort_type == SORT_TYPE::BUBBLE_SORT) {
                bubbleSort(arr, size);
            } else if (sort_type == SORT_TYPE::HEAP_SORT) {
                heapSort(arr, size);
            } else if (sort_type == SORT_TYPE::MERGE_SORT) {
                mergeSort(arr, 0, size - 1);
            } else if (sort_type == SORT_TYPE::QUICK_SORT) {
                quickSort(arr, 0, size - 1);
            }
            auto end = std::chrono::high_resolution_clock::now();
            if (sort_type == SORT_TYPE::BUBBLE_SORT) {
                auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);
                result.push_back(elapsed.count());
            } else if (sort_type == SORT_TYPE::HEAP_SORT) {
                auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
                result.push_back(elapsed.count());
            } else if (sort_type == SORT_TYPE::MERGE_SORT) {
                auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
                result.push_back(elapsed.count());
            } else if (sort_type == SORT_TYPE::QUICK_SORT) {
                auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
                result.push_back(elapsed.count());
            }
            delete[] arr;
        }
    }
    int i = 0;
    for(int k=1; k<=n; k++){
        for(int j = 1; j < 9; j+=3){
            fout << j*pow(10,k) << ", " << result[i] << endl;
            i++;
        }
    }
    fout.close();
    return 0;
}

int main(){
    srand(time(NULL));
    testSort(SORT_TYPE::BUBBLE_SORT, 5, "bubble_sort");
    testSort(SORT_TYPE::HEAP_SORT, 6, "heap_sort");
    testSort(SORT_TYPE::MERGE_SORT, 6, "merge_sort");
    testSort(SORT_TYPE::QUICK_SORT, 6, "quick_sort");
}