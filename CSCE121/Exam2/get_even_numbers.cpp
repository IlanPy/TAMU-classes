#include <iostream>
using namespace std;
int* get_even_numbers(int* A, unsigned int n, unsigned int& m){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(A[i] % 2 == 0){
            count++;
        }
    }
    m = count;
    int* arr = new int[m];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(A[i] % 2 == 0){
            arr[j] = A[i];
            j++;
        }
    }
    return arr;
}

int main(){
    unsigned int n = 15;
    unsigned int m = 1;
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        cin >> A[i];
    }
    int* arr = get_even_numbers(A, n, m);
    for(int i =0; i < m; i++){
        cout << arr[i] << " ";
    } cout << endl;
}