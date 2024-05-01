#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Node {
public:
    int key;
    std::vector<Node*> forward;

    Node(int key, int level) : key(key), forward(level + 1, nullptr) {}
};

class SkipList {
private: 
    double P;
    int MAXLVL;
    Node* header;
    int level;

public:
    SkipList(int max_lvl, double p);
    ~SkipList();
    int randomLevel();
    void insertElement(int key);
    void deleteElement(int search_key);
    bool searchElement(int key);
    void displayList();
};


SkipList::SkipList(int max_lvl, double p) : MAXLVL(max_lvl), P(p), level(0) {
    header = new Node(-1, MAXLVL);
}

SkipList::~SkipList() {
    Node* current = header;
    while(current != nullptr){
        Node* next_node = current->forward[0];
        delete current;
        current = next_node;
    }
    header = nullptr;
} 

int SkipList::randomLevel() {
    double random;
    int level = -1;
    do{
        random = static_cast<double>(rand()) / RAND_MAX;
        level++;
    } while(random < P && level < MAXLVL);
    return level;
}

void SkipList::insertElement(int key) {
    if(searchElement(key)){
        return;
    }
    Node* current = header;
    int new_level = randomLevel();
    if(new_level > level){
        level = new_level;
    }
    int lvl = level+1;
    Node* new_node = new Node(key, new_level);
    while(lvl-1 >= 0){
        lvl--;
        while(current->forward[lvl] != nullptr && current->forward[lvl]->key < key){
            current = current->forward[lvl];
        }
        if(lvl <= new_level){
            new_node->forward[lvl] = current->forward[lvl];
            current->forward[lvl] = new_node;
        }
    }
}

void SkipList::deleteElement(int search_key) {
    if(!searchElement(search_key)){
        return;
    }
    Node* current = header;
    int lvl = level+1;
    Node* deleted = nullptr;
    while(lvl-1 >= 0){
        lvl--;
        while(current->forward[lvl] != nullptr && current->forward[lvl]->key < search_key){
            current = current->forward[lvl];
        }
        if(current->forward[lvl] != nullptr && current->forward[lvl]->key == search_key){
            deleted = current->forward[lvl];
            current->forward[lvl] = current->forward[lvl]->forward[lvl];
        }
    }
    delete deleted;
}

bool SkipList::searchElement(int key) {
    Node* current = header;
    int lvl = level+1;
    while(lvl-1 >= 0){
        lvl--;
        while(current->forward[lvl] != nullptr && current->forward[lvl]->key <= key){
            current = current->forward[lvl];
        }
    }
    if(current->key == key){
        return true;
    }
    return false;
}

void SkipList::displayList() {
    std::cout << "\n*****Skip List******" << std::endl;
    Node* head = header;
    for (int lvl = 0; lvl <= level; lvl++) {
        std::cout << "Level " << lvl << ": ";
        Node* node = head->forward[lvl];
        while (node != nullptr) {
            std::cout << node->key << " ";
            node = node->forward[lvl];
        }
        std::cout << std::endl;
    }
}

#endif