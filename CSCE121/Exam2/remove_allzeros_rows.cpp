#include <iostream>
using namespace std;
int** remove_allzeros_rows(int** matrix, 
					int nrows, 
					int ncolumns, 
					int& new_nrows){
    if(nrows == 0 || ncolumns == 0){
        throw invalid_argument("Invalid row/col");
    }
    int* nonzero_index = new int[nrows];
    int count=0;
    for(int i = 0; i < nrows; i++){
        count = 0;
        for(int j = 0; j < ncolumns; j++){
            if(matrix[i][j] != 0){
                count++;
            }
        }
        if(count != 0){
            new_nrows++;
            nonzero_index[i] = 1;
        } else{
            nonzero_index[i] = 0;
        }
    }
    if(new_nrows == 0){
        delete[] nonzero_index;
        return nullptr;
    }
    int** final = new int*[new_nrows];
    for(int i = 0; i < new_nrows; i++){
        final[i] = new int[ncolumns];
    }
    int z = 0;
    for(int i = 0; i < nrows; i++){
        if(nonzero_index[i] == 0){} else{
        for(int j = 0; j < ncolumns; j++){
            final[z][j] = matrix[i][j];
        }
        z++;
        }
    }
    delete[] nonzero_index;
    return final;
}
    
int main(){
    int nrows = 0;
    int ncolumns = 0;
    int new_nrows = 0;
    cout << "nrows: ";
    cin >> nrows;
    cout << "ncolumns";
    cin >> ncolumns;
    int** matrix = new int*[nrows];
    for(int i  = 0; i < nrows; i++){
        matrix[i] = new int[ncolumns];
    }
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncolumns; j++){
            cout << i << "," << j << ": ";
            cin >> matrix[i][j];
        }
    }
    int** new_matrix = remove_allzeros_rows(matrix,
                        nrows,
                        ncolumns,
                        new_nrows);
    for(int i = 0; i < new_nrows; i++){
        for(int j = 0; j < ncolumns; j++){
            cout << new_matrix[i][j] << " ";
        } cout << endl;
    }
    for(int i = 0; i < nrows; i++){
        delete[] matrix[i];
    } delete[] matrix;
    for(int i = 0; i < new_nrows; i++){
        delete[] new_matrix[i];
    } delete[] new_matrix;
    new_matrix = nullptr; matrix = nullptr;
}
