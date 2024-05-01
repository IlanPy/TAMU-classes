#ifndef CHAINING_H
#define CHAINING_H

#include "AbstractHashTable.h"
#include <vector>
#include <list>


// Chaining hash table class
class ChainingHashTable: public AbstractHashTable {
    private:
    std::vector<std::list<HashEntry>> table;
    void resizeAndRehash();

    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, const int val); 
    int remove(std::string key); 
    int get(std::string key) const;
    bool contains(std::string key) const;
};


///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor
ChainingHashTable::ChainingHashTable(): AbstractHashTable() {
    maxLoadFactor = 0.8;
    table.resize(capacity);
}

// destructor
ChainingHashTable::~ChainingHashTable() {
	num_elements = 0;
    capacity = 11;
    table.clear();
    table.resize(capacity);
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
    float loadFactor = static_cast<float>(num_elements)/capacity;
    if(loadFactor > maxLoadFactor){
        resizeAndRehash();
    }
    int hash_index = hash(key);
    std::list<HashEntry>::iterator it;
    for(it = table[hash_index].begin(); it != table[hash_index].end(); it++){
        if(it->key == key){
            it->val = val;
            break;
        }
    }
    if(it == table[hash_index].end()){
        table[hash_index].push_back(HashEntry(key, val));
        num_elements++;
    }
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
    int hash_index = hash(key);
    int return_val = -1;
    std::list<HashEntry>::iterator it;
    for(it = table[hash_index].begin(); it != table[hash_index].end(); it++){
        if(it->key == key){
            return_val = it->val;
            table[hash_index].erase(it);
            num_elements--;
            return return_val;
        }
    }
    throw std::out_of_range("");
    return -1;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) const {
    int hash_index = hash(key);
    std::list<HashEntry>::const_iterator it;
    for(it = table[hash_index].begin(); it != table[hash_index].end(); it++){
        if(it->key == key){
            return it->val;
        }
    }
    throw std::out_of_range("");
    return -1;
}

bool ChainingHashTable::contains(const std::string key) const {
    try{
        get(key);
        return true;
    } catch(...){}
	return false;
}

void ChainingHashTable::resizeAndRehash() {
    int old_capacity = capacity;
    capacity = findNextPrime(2*capacity);
    std::vector<std::list<HashEntry>> newTable(capacity);
    for(int i = 0; i < old_capacity; i++){
        std::list<HashEntry> entry = table[i];
        if(!entry.empty()){
            std::list<HashEntry>::iterator it;
            for(it = table[i].begin(); it != table[i].end(); it++){
                int hash_index = hash(it->key);
                newTable[hash_index].push_back(HashEntry(it->key, it->val));
            }
        }
    }
    table = std::move(newTable);
}

#endif