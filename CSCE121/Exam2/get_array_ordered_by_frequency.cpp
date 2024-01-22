#include <iostream>
using namespace std;
int* get_array_ordered_by_frequency (int *a, 
				unsigned int size_a,
				unsigned int& new_array_size){
    bool* flag_arr = new bool[size_a];
    int* amount = new int[size_a];
    int am = 0;
    for(int i = 0; i < size_a; i++){
        flag_arr[i] = false;
        amount[i] = 0;
    }
    int* arr = new int[size_a];
    for(int i = 0; i < size_a; i++){
        int count = 0;
        am = 0;
        for(int j =0; j < size_a; j++){
            if(a[i] == arr[j]){
                count++;
            }
            if(a[i] == a[j]){
                am++;
            }
        }
        if(count == 0){
            arr[i] = a[i];
            flag_arr[i] = true;
            amount[i] = am;
        }
    }
    int size = 0;
    for(int i = 0; i < size_a; i++){
        if(flag_arr[i] == true){
            size++;
        }
    }
    new_array_size = size;
    int* final = new int[size];
    int* final_amount = new int[size];
    int z = 0;
    for(int i = 0; i < size_a; i++){
        if(flag_arr[i] == true){
            final[z] = arr[i];
            z++;
        }
    }
    z = 0;
    for(int i = 0; i < size_a; i++){
        if(amount[i] != 0){
            final_amount[z] = amount[i];
            z++;
        }
    }
    bool swapped;
    int temp;
    for(int i = 0; i < size -1; i++){
        swapped = false;
        for(int j = 0; j < size-i - 1; j++){
            if(final_amount[j] < final_amount[j+1]){
                temp = final_amount[j];
                final_amount[j] = final_amount[j+1];
                final_amount[j+1] = temp;
                temp = final[j];
                final[j] = final[j+1];
                final[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
    delete[] amount;
    delete[] flag_arr;
    delete[] arr;
    delete[] final_amount;
    return final;

}

int main(){
    unsigned int size = 15;
    int* a = new int[size];
    unsigned int new_size =0 ;
    for(int i = 0; i < size; i++){
        cout << i <<  ": ";
        cin >> a[i];
    }
    int* alex = get_array_ordered_by_frequency(a, size, new_size);
    for(int i = 0; i < new_size; i++){
        cout << alex[i] << " ";
    } cout << endl;
    delete[] alex;
    delete[] a;
}