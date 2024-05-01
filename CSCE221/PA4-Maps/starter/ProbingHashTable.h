#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "AbstractHashTable.h"
#include <vector>

// Linear probing hash table class
class ProbingHashTable : public AbstractHashTable {
    private:
    std::vector<HashEntry> table;
    void resizeAndRehash();
    
    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key) const; 
    bool contains(std::string key) const;
};

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor 
ProbingHashTable::ProbingHashTable(): AbstractHashTable() {
    maxLoadFactor = 0.8;
    table.resize(capacity);
}

// destructor
ProbingHashTable::~ProbingHashTable() {
	num_elements = 0;
    capacity = 11;
    table.clear();
    table.resize(capacity);
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
    float loadFactor = static_cast<float>(num_elements)/capacity;
    if(loadFactor > maxLoadFactor){
        resizeAndRehash();
    }
    int i = 0;
    int hash_index = hash(key);
    int new_index = -1;
    num_elements++;
    HashEntry entry;
    while(i < capacity){
        int j = (hash_index + i) % capacity;
        entry = table[j];
        if(!entry.isFilled && new_index == -1){
            new_index = j;
        } else if(entry.key == key){
            new_index = j;
            num_elements--;
        }
        if((!entry.isFilled && !entry.DELETED) || entry.key == key){
            table[new_index] = HashEntry(key, val);
            break;
        }
        i++;
    }
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
    int i =  0;
    int hash_index = hash(key);
    while(i < capacity){
        int j = (hash_index + i) % capacity;
        HashEntry entry = table[j];
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
int ProbingHashTable::get(std::string key) const {
    int i =  0;
    int hash_index = hash(key);
    while(i < capacity){
        int j = (hash_index + i) % capacity;
        HashEntry entry = table[j];
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

bool ProbingHashTable::contains(std::string key) const {
    try{
        get(key);
        return true;
    } catch(...){}
	return false;
}

void ProbingHashTable::resizeAndRehash() {
    // Double the capacity and find the next prime number
    this->capacity = findNextPrime(this->capacity * 2);
    // Move elements from table to tempTable
    vector<HashEntry> tempTable = std::move(table);
    // Clear the original table and resize it to the new capacity
    table.clear();
    table.resize(this->capacity);
    // Reset the number of elements
    num_elements = 0;
    // Rehash existing elements into the new hash table
    for (auto it = tempTable.begin(); it != tempTable.end(); ++it) {
        // If the bucket is filled, insert its key-value pair into the new table
        if (it->isFilled) {
            insert(it->key, it->val);
        }
    }
}

#endif