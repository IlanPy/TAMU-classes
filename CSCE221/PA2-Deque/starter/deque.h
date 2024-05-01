#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
using namespace std;

template <class Type>
class Deque {
private:
	int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
	Deque();
	Deque(const Deque& other); 
	Deque& operator=(const Deque& other); 
	~Deque();
	bool isEmpty();
	int size();
	Type first();
	Type last();
	void insertFirst(Type o);
	void insertLast(Type o);
	Type removeFirst();
	Type removeLast();
};

// Your implementation here 

template <class Type>
Deque<Type>::Deque() {
	firstNode = lastNode = nullptr;
	s = 0;
}

template <class Type>
Deque<Type>::~Deque() {
	Node<Type>* current = firstNode;
	while(current != nullptr){
		Node<Type>* next_node = current->getNext();
		delete current;
		current = next_node;
	}
	firstNode = lastNode = nullptr;
	s = 0;
}

template <class Type>
Deque<Type>::Deque(const Deque& other) {
	Node<Type>* other_current = other.firstNode;
	firstNode = lastNode = nullptr;
	while(other_current != nullptr){
		Node<Type>* new_node = new Node<Type>(other_current->getData());
		if(firstNode == nullptr){
			firstNode = lastNode = new_node;
		} 
		else{
			new_node->setPrev(lastNode);
			lastNode->setNext(new_node);
			lastNode = new_node;
		}
		other_current = other_current->getNext();
	}
	s = other.s;
}

template <class Type>
Deque<Type>& Deque<Type>::operator=(const Deque& other) {
	if(this != &other){
		//delete
		Node<Type>* current = firstNode;
		while(current != nullptr){
			Node<Type>* next_node = current->getNext();
			delete current;
			current = next_node;
		}
		Node<Type>* other_current = other.firstNode;
		current = firstNode = lastNode = nullptr;
		while(other_current != nullptr){
			Node<Type>* new_node = new Node<Type>(other_current->getData());
			if(firstNode == nullptr){
				firstNode = lastNode = new_node;
			} 
			else{
				new_node->setPrev(lastNode);
				lastNode->setNext(new_node);
				lastNode = new_node;
			}
			other_current = other_current->getNext();
		}
		s = other.s;
	}
	return *this;
}

template <class Type>
bool Deque<Type>::isEmpty() {
	if(firstNode == nullptr){
		return true;
	}
	return false;
}

template <class Type>
int Deque<Type>::size() {
	return s;
}

template <class Type>
Type Deque<Type>::first() {
	if(firstNode == nullptr){
		return Type();
	}
	return firstNode->getData();
}

template <class Type>
Type Deque<Type>::last() {
	if(lastNode == nullptr){
		return Type();
	}
	return lastNode->getData();
}

template <class Type>
void Deque<Type>::insertFirst(Type o) {
	Node<Type>* new_node = new Node<Type>(o);
	if(firstNode == nullptr){
		firstNode = lastNode = new_node;
	}
	else{
		new_node->setNext(firstNode);
		firstNode->setPrev(new_node);
		firstNode = new_node;
	}
	s++;
}

template <class Type>
void Deque<Type>::insertLast(Type o) {
	Node<Type>* new_node = new Node<Type>(o, nullptr, nullptr);
	if(firstNode == nullptr){
		firstNode = lastNode = new_node;
	}
	else{
		new_node->setPrev(lastNode);
		lastNode->setNext(new_node);
		lastNode = new_node;
	}
	s++;
}

template <class Type>
Type Deque<Type>::removeFirst() {
	Type return_val;
	if(firstNode == nullptr){
		throw std::out_of_range("");
	}
	else if(firstNode == lastNode){
		return_val = firstNode->getData();
		delete firstNode;
		firstNode = lastNode = nullptr;
	}
	else{
		return_val = firstNode->getData();
		firstNode = firstNode->getNext();
		delete firstNode->getPrev();
		firstNode->setPrev(nullptr);
	}
	s--;
	return return_val;
}

template <class Type>
Type Deque<Type>::removeLast() {
	Type return_val;
	if(lastNode == nullptr){
		throw std::out_of_range("");
	}
	else if(firstNode == lastNode){
		return_val = lastNode->getData();
		delete lastNode;
		firstNode = lastNode = nullptr;
	}
	else{
		return_val = lastNode->getData();
		lastNode = lastNode->getPrev();
		delete lastNode->getNext();
		lastNode->setNext(nullptr);
	}
	s--;
	return return_val;
}

#endif
