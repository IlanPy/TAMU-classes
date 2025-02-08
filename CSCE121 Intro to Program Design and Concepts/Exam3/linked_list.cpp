# include "linked_list.h"
# include <iostream>
# include <string>
# include <vector>
using namespace std;

double LinkedList::average() const{
    if(this->head == nullptr){
        return 0;
    }
    double sum = 0;
    double count = 0;
    Node* current = head;
    while(current != nullptr){
        count++;
        sum += current->value;
        current = current->next;
    }
    return sum/count;
}

void LinkedList::remove_maximum(){
    if(head == nullptr){} else{
        Node* current = head;
        Node* prev_node = nullptr;
        int max = current->value;
        //find the maximum value
        while(current != nullptr){
            if(current->value > max){
                max = current->value;
            }
            current = current->next;
        }
        //delete the maximum value
        current = head;
        while(current != nullptr){
            if(current->value == max){
                if(current == head){
                    head = current->next;
                    delete current;
                    current = head->next;
                } else{
                    prev_node->next = current->next;
                    delete current;
                    current = prev_node->next;
                }
            } else{
                prev_node = current;
                current = current->next;
            }
        }
    }
}

void LinkedList::reverse_list(){
    Node* current = head;
    Node* next_node = nullptr;
    Node* prev_node = nullptr;
    while(current != nullptr){
        next_node = current->next;
        current->next = prev_node;
        prev_node = current;
        current = next_node;
    }
    head = prev_node;
}

Node* LinkedList::middle_of_list(){
    if(head == nullptr){ return nullptr; }
    Node* current = head;
    int size = 0;
    while(current != nullptr){
        size++;
        current = current->next;
    }
    int n_element = size/2 + 1;
    current = head;
    int count = 0;
    while(current != nullptr){
        count++;
        if(count == n_element){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool LinkedList::cycle(){
    vector<int> slow;
    vector<int> fast;
    if(head == nullptr) { return false; }
    Node* slow_current = head;
    Node* fast_current = head;
    while(fast_current != nullptr && fast_current->next != nullptr){
        if(fast_current == slow_current){
            return true;
        }
        slow_current = slow_current->next;
        fast_current = fast_current->next->next;
    }
    return false;
}