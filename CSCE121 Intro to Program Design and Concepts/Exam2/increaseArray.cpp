#include <iostream>
using namespace std;
void increaseArray(int**& ary, int& numRows, int& numColumns, 
				int addRows, int addColumns){
    int** arr = new int*[numRows+addRows];
    for(int i = 0; i < numRows+addRows; i++){
        arr[i] = new int[numColumns+addColumns];
    }
    int sum = 0;
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numColumns; j++){
            arr[i][j] = ary[i][j];
        }
    }
    for(int j = numColumns; j < numColumns+addColumns; j++){
        if(addColumns == 0) break;
        for(int i = 0; i < numRows; i++){
            sum = 0;
            if(j-1 >= 0 && i-1 >=0){
                sum += arr[i-1][j-1];
            }
            if(j-1 >= 0){
                sum += arr[i][j-1];
            }
            if(j-1 >= 0 && i+1 < numRows){
                sum += arr[i+1][j-1];
            }
            arr[i][j] = sum;
        }
    }
    for(int i = numRows; i < numRows+addRows; i++){
        if(addRows == 0) break;
        for(int j = 0; j < numColumns+addColumns; j++){
            sum = 0;
            if(i-1 >= 0 && j-1 >=0){
                sum += arr[i-1][j-1];
            }
            if(i-1 >= 0){
                sum += arr[i-1][j];
            }
            if(i-1 >= 0 && j+1 < numColumns+addColumns){
                sum += arr[i-1][j+1];
            }
            arr[i][j] = sum;
        }
    }
    for(int i = 0; i < numRows; i++){
        delete[] ary[i];
    } delete[] ary;
    ary = arr;
    numRows = numRows + addRows;
    numColumns = numColumns + addColumns;
}

int main(){
    int nCols = 0;
    int nRows = 0;
    int addRows = 0;
    int addColumns = 0;
    cout << "Num. Rows: ";
    cin >> nRows;
    cout << "Num. Cols: ";
    cin >> nCols;
    cout << "Add Rows: ";
    cin >> addRows;
    cout << "Add Cols: ";
    cin >> addColumns;
    int** ary = new int*[nRows];
    for(int i = 0; i < nRows; i++){
        ary[i] = new int[nCols];
    }
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            cout << i << "," << j << ": ";
            cin >> ary[i][j];
        }
    }
    increaseArray(ary, nRows, nCols, addRows, addColumns);
    for(int i = 0; i < nRows; i++){
        for(int j = 0; j < nCols; j++){
            cout << ary[i][j] << " ";
        } cout << endl;
    }
    for(int i = 0; i < nRows; i++){
        delete[] ary[i];
    } delete[] ary;
}