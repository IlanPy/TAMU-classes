# ifndef MY_LIST_H
# define MY_LIST_H

# include <string>
# include <iostream>

struct Node {
  int value;
  Node* next;
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {
  Node* head;

 public:
  LinkedList() : head{nullptr} {}
  double average() const;
  void remove_maximum();
  void reverse_list();
  Node* middle_of_list();
  bool cycle();
  // other member functions

  //TESTING FUNCTION
  void insert(int num) {
    Node* newNode = new Node(num);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
          current = current->next;
        }
        current->next = newNode;
    }
  }
  ~LinkedList(){
	  Node* current = head;
	  Node* nextNode = nullptr;
	  while(current != nullptr){
		  nextNode = current->next;
		  delete current;
		  current = nextNode;
	  }
  }
  void print(){
    Node* current = head;
    while(current != nullptr){
      std::cout << current->value << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

# endif
