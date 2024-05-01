#ifndef DOUBLEHASHING_H
#define DOUBLEHASHING_H

#include "AbstractHashTable.h"
#include <vector>

// Double hashing hash table class
class DoubleHashTable : public AbstractHashTable {
    private:
    // helper functions
    int secondHash(std::string s) const;
    std::vector<HashEntry> table;
    int prevPrime;
    void resizeAndRehash();
    //add
    mutable int cap = -1;
    mutable int prev_prime;

    public: 
    DoubleHashTable();
    ~DoubleHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key) const; 
    bool contains(std::string key) const;
};


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor 
DoubleHashTable::DoubleHashTable(): AbstractHashTable() {
    maxLoadFactor = 0.4;
	table.resize(capacity);
}

// destructor
DoubleHashTable::~DoubleHashTable() {
	num_elements = 0;
    capacity = 11;
    table.clear();
    table.resize(capacity);
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
    float loadFactor = static_cast<float>(num_elements)/capacity;
    if(loadFactor > maxLoadFactor){
        resizeAndRehash();
    }
    int hash_index = hash(key) % capacity;
    num_elements++;
    HashEntry entry = table[hash_index];
    int saved_index = -1;
    if(entry.isFilled && entry.key == key){
        table[hash_index].val = val;
        num_elements--;
    } else{ //search if key exists
        int double_hash_index = secondHash(key);
        int i = 0;
        while(i < capacity){
            int j = (double_hash_index + i ) % capacity;
            entry = table[j];
            if(!entry.isFilled && !entry.DELETED){
                if(saved_index == -1){
                    saved_index = j;
                }
                break;
            } else if(!entry.isFilled && saved_index == -1){
                saved_index = j;
            } else if(entry.key == key){
                saved_index = j;
                break;
            }
            i++;
        }
        if(entry.key == key){
            table[saved_index].val = val;
            num_elements--;
        } else if(!table[hash_index].isFilled){
            entry = HashEntry(key, val);
            table[hash_index] = entry;
        } else{
            entry = HashEntry(key, val);
            table[saved_index] = entry;
        }
    }
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {
    int i =  0;
    int hash_index = hash(key);
    HashEntry entry = table[hash_index];
    if(entry.key == key){
        entry.isFilled = false;
        entry.DELETED = true;
        entry.key = "";
        table[hash_index] = entry;
        num_elements--;
        return entry.val;
    }
    int double_hash_index = secondHash(key);
    while(i < capacity){
        int j = (double_hash_index + i) % capacity;
        entry = table[j];
        if(!entry.DELETED && entry.isFilled && entry.key == key){
            entry.isFilled = false;
            entry.DELETED = true;
            entry.key = "";
            table[j] = entry;
            num_elements--;
            return entry.val;
        } else if(!entry.DELETED && !entry.isFilled){
            break;
        }
        i++;
    }
    throw std::out_of_range("");
    return -1;
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) const {
    int i =  0;
    int hash_index = hash(key);
    HashEntry entry = table[hash_index];
    if(entry.key == key){
        return entry.val;
    } else if(!entry.DELETED && !entry.isFilled){
        throw std::out_of_range("");
    }
    int double_hash_index = secondHash(key);
    while(i < capacity){
        int j = (double_hash_index + i) % capacity;
        entry = table[j];
        if(!entry.DELETED && entry.isFilled && entry.key == key){
            return entry.val;
        } else if(!entry.DELETED && !entry.isFilled){
            break;
        }
        i++;
    }
    throw std::out_of_range("");
    return -1;
}

bool DoubleHashTable::contains(std::string key) const {
    try{
        get(key);
        return true;
    } catch(...){}
	return false;
}

void DoubleHashTable::resizeAndRehash() {
    int old_capacity = capacity;
    capacity = findNextPrime(2*capacity);
    std::vector<HashEntry> newTable(capacity);
    for(int i = 0; i < old_capacity; i++){
        HashEntry entry = table[i];
        if(entry.isFilled){
            int new_i = hash(entry.key);
            if(newTable[new_i].isFilled){
                new_i = secondHash(entry.key);
            }
            while(newTable[new_i].isFilled){
                new_i = (new_i + 1) % capacity;
            }
            newTable[new_i] = entry;
        }
    }
    table = std::move(newTable);
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) const {
	unsigned long hash = 0;
	int n = s.length();
	int c = 31;
	for(int i = 0; i < n; i++){
		hash = c * hash + static_cast<int>(s[i]);
	}
    if(capacity != cap){
        cap = capacity;
        int n = capacity-1;
        while(!isPrime(n)){
            n--;
        }
        prev_prime = n;
    }
    int return_val = (prev_prime - (hash % prev_prime));
    return return_val;
}


#endif