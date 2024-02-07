#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
#include "AbstractStack.h"

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <typename T>
class StackLinkedList : public AbstractStack<T>{
private:
    Node<T>* head;
    int length;
public:
    StackLinkedList();

    ~StackLinkedList();

    StackLinkedList(const StackLinkedList& other);

    StackLinkedList& operator=(const StackLinkedList& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackLinkedList<T>::StackLinkedList(){
    head = nullptr;
    length = 0;
}

template <typename T>
StackLinkedList<T>::~StackLinkedList(){
    Node<T>* current = head;
    while(current != nullptr){
        Node<T>* next_node = current->next;
        delete current;
        current = next_node;
    }
    head = nullptr;
    length = 0;
}

template <typename T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList& other) {
    Node<T>* other_current = other.head;
    Node<T>* current = head = nullptr;
    while(other_current != nullptr){
        Node<T>* new_node = new Node<T>();
        new_node->data = other_current->data;
        new_node->next = nullptr;
        if(head == nullptr){
            head = new_node;
            current = head;
        } else{
            current->next = new_node;
            current = current->next;
        }
        other_current = other_current->next;
    }
    length = other.length;
}

template <typename T>
StackLinkedList<T>& StackLinkedList<T>::operator=(const StackLinkedList& other) {
    if(this != &other){
        //delete
        Node<T>* current = head;
        while(current != nullptr){
            Node<T>* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
        current = nullptr;
        //assign
        Node<T>* other_current = other.head;
        while(other_current != nullptr){
            Node<T>* new_node = new Node<T>();
            new_node->data = other_current->data;
            new_node->next = nullptr;
            if(head == nullptr){
                head = new_node;
                current = head;
            } else{
                current->next = new_node;
                current = current->next;
            }
            other_current = other_current->next;
        }
        length = other.length;
    }
    return *this;
}

template <typename T>
bool StackLinkedList<T>::isEmpty(){
    if(head == nullptr){
        return true;
    }
    return false;
}

template <typename T>
int StackLinkedList<T>::size(){
    return length;
}

template <typename T>
T& StackLinkedList<T>::top(){
    Node<T>* current = head;
    if(head == nullptr){
        throw std::out_of_range("");
    }
    return head->data;
}

template <typename T>
T StackLinkedList<T>::pop(){
    T temp;
    if(head == nullptr){
        throw std::out_of_range("");
    }
    Node<T>* next_node = head->next;
    temp = head->data;
    delete head;
    head = next_node;
    length--;
    return temp;
}

template <typename T>
void StackLinkedList<T>::push(const T& e){
    Node<T>* new_node = new Node<T>();
    new_node->data = e;
    new_node->next = head;
    head = new_node;
    length++;
}


#endif