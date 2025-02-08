#include <iostream>
using namespace std;

void minusOddColumn(int** mat, int n){
    int* arr = new int[n];
    int odd = 0;
    for(int i = 0; i < n; i++){
        odd = 0;
        for(int j = 0; j < n; j++){
            if(mat[j][i] % 2 != 0){
                odd++;
            }
        }
        arr[i] = odd;
    }
    int max = arr[0];
    int index = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }
    for(int i = 0; i < n; i++){
        mat[i][index] = -1;
    }
    //dealocate
    delete[] arr;
    arr = nullptr;
}

int main(){
    int n = 5;
    int** inArray = new int*[n];
    for (unsigned int i=0; i < n; i++){
        inArray[i] = new int[n]; 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "i,j: ";
            cin >> inArray[i][j];
        }
    }
    minusOddColumn(inArray, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << inArray[i][j] << " ";
        }
        cout << endl;
    }
    for(int i =0; i < n; i++){
        delete[] inArray[i];
    } delete[] inArray;
}