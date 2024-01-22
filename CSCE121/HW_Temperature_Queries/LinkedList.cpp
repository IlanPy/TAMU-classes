# include <iostream>
# include <string>
# include <sstream>
# include "LinkedList.h"
# include "Node.h"

using std::string, std::ostream;

LinkedList::LinkedList() /* TODO */: head(nullptr), tail(nullptr) {
	// TODO: implement this function
}

LinkedList::~LinkedList() {
	// TODO: implement this function
	Node* current = head;
	Node* nextNode = nullptr;
	while(current != nullptr){
		nextNode = current->next;
		delete current;
		current = nextNode;
	}
}

LinkedList::LinkedList(const LinkedList& source) /* TODO */
	: head(nullptr), tail(nullptr) {
	// TODO: implement this function
	Node* current = source.head;
	while(current != nullptr){
		Node* ptr = new Node(source.head->data.id, source.head->data.year, 
			source.head->data.month, source.head->data.temperature);
		if(head == nullptr){
			head = tail = ptr;
		} else {
			tail->next = ptr;
			tail = ptr;
		}
		current = current->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// TODO: implement this function
	if(this != &source){
		clear();
		Node* current = source.head;
		while(current != nullptr){
			//push
			Node* ptr = new Node(source.head->data.id, source.head->data.year, 
				source.head->data.month, source.head->data.temperature);
			if(head == nullptr){
				head = tail = ptr;
			} else {
				tail->next = ptr;
				tail = ptr;
			}
			current = current->next;
		}
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// TODO: implement this function
	//create the new node
	Node* ptr = new Node(location, year, month, temperature);
	Node* current = head;
	Node* prev_current;
	int index = 0;
	bool is_tail = true;
	bool is_head = false;
	if(head == nullptr){
		head = tail = ptr;
	} else {
		while(current != nullptr){
			if(*ptr < *current){
				is_tail = false;
				break;
			}
			index++;
			prev_current = current;
			current = current->next;
		}
		if(index == 0){is_head = true;}
		if(is_tail){
			tail->next = ptr;
			tail = ptr;
		} else if(is_head){
			ptr->next = head;
			head = ptr;
		} else{
			prev_current->next = ptr;
			ptr->next = current;
		}
	}
}

void LinkedList::clear() {
	// TODO: implement this function
	Node* current = head;
	while(current != nullptr){
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = tail = nullptr;
}

Node* LinkedList::getHead() const {
	// TODO: implement this function, it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;
	// TODO: implement this function
	std::ostringstream OSS;
	Node* current = head;
	while(current != nullptr){
		OSS << current->data.id << " "
			<< current->data.year << " "
			<< current->data.month << " "
			<< current->data.temperature << "\n";
		current = current->next;
	}
	outputString = OSS.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.print();
	return os;
}
