#include <iostream>
using namespace std;

int* seperate_even_odd(int* A, unsigned int n){
    int* arr = new int[n];
    int* even = new int[n];
    int* odd = new int[n];
    for(int i = 0; i < n; i++){
        even[i] = -1;
        odd[i] = -1;
    }
    int j = 0, k = 0;
    for(int i = 0; i < n; i++){
        if(A[i] % 2 == 0){
            even[j] = A[i];
            j++;
        } else {
            odd[k] = A[i];
            k++;
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(even[i] == -1){
            break;
        } else{
            arr[i] = even[i];
            count++;
        }
    }
    for(int j = 0; j < n; j++){
        if(odd[j] == -1){
            break;
        } else{
            arr[count] = odd[j];
            count++;
        }
    }
    delete[] odd;
    delete[] even;
    odd = nullptr;
    even = nullptr;
    return arr;
}

int main(){
    int n = 5;
    int* A = new int[n];
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        cin >> A[i];
    }
    int* arr = seperate_even_odd(A, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } cout << endl;
    delete[] arr;
    delete[] A;
    arr = nullptr; A = nullptr;
}

