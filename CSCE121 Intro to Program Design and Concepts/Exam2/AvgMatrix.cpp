//lines 12-15, 34-37
#include <iostream>
using namespace std;

void avgMatrix (double** inArray, int rows, int columns, double** outArray){
    double sum = 0;
    double amount = 0;
    double avg = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            avg = 0; sum = 0; amount = 0;
            for(int k = i-1; k <= i+1; k++){
                for(int z = j-1; z <= j+1; z++){
                    if((k >= 0 && z >= 0) && (k < rows && z < columns)
                    && !(k == i && z == j)){
                        sum+=inArray[k][z];
                        amount+=1;
                    }
                }
            }
            if(amount > 0)
                outArray[i][j] = sum/amount;
        }
    }
}
int main()
{ 
    int rows = 3;
    int columns = 4;
    double** inArray = new double*[rows];
    for (unsigned int i=0; i < rows; i++){
        inArray[i] = new double[columns]; 
    }
    double** outArray = new double*[rows];
    for (unsigned int i=0; i < rows; i++){
        outArray[i] = new double[columns]; 
    }

    inArray[0][0] = 0.5;
    inArray[0][1] = 2.0;
    inArray[0][2] = 1.2;
    inArray[0][3] = 3.0;
    inArray[1][0] = -1.0;
    inArray[1][1] = 1.5;
    inArray[1][2] = 3.0;
    inArray[1][3] = 2.4;
    inArray[2][0] = 0.0;
    inArray[2][1] = 1.0;
    inArray[2][2] = 1.5;
    inArray[2][3] = 2.0;
    avgMatrix(inArray, rows, columns, outArray);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << outArray[i][j] << " ";
        }
        cout << endl;
    }
    for(unsigned int i = 0; i < rows; i++){
        delete[] inArray[i];
    } delete[] inArray;
    inArray = nullptr;
    for(unsigned int i = 0; i < rows; i++){
        delete[] outArray[i];
    } delete[] outArray;
    outArray = nullptr;
}