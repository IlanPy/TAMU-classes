int* get_array_ordered_by_frequency (int* a, unsigned int size_a,
				unsigned int& new_array_size){
    //e.g. if a = [9,8,7,9,8,9]
    //frequencies [3,2,1,3,2,3]
    int* frequencies = new int[size_a];
    for(int i = 0; i < size_a; i++){
        frequencies[i] = 0;
        for(int j = 0; j < size_a; j++){
            if(a[j] == a[i]){
                frequencies[i]++;
            }
        }
    }
    int* result = new int[size_a];
    new_array_size = 0;
    while(true){
        //find the most frequent element of a
        int max_freq = 0;
        int best_ind = -1;
        for(int i = 0; i < size_a; i++){
            if(frequencies[i] > max_freq){
                max_freq = frequencies[i];
                best_ind = i;
            }
        }
        if(best_ind == -1){
            break;
        }
        result[new_array_size] = a[best_ind];
        new_array_size++;
        //zero out this element's frequency
        for(int i = 0; i < size_a; i++){
            if(a[i] == a[best_ind]){
                frequencies[i] = 0;
            }
        }
    }
    delete[] frequencies;
    return result;
}
