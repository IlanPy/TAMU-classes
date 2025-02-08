# include "linked_list.h"
# include <iostream>
# include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // TODO
    MyNode* newptr = new MyNode(name, score);
    if(_head == nullptr){
        _head = _tail = newptr;
    } else{
        _tail->next = newptr;
        _tail = newptr;
    }
    _size += 1;
}

void MyList::clear() {
    // TODO
    MyNode* current = _head;
    while(current != nullptr){
        MyNode* nextMyNode = current->next;
        delete current;
        current = nextMyNode;
    }
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}

bool MyList::remove(const std::string& name) {
    // TODO
    MyNode* current = _head;
    MyNode* prevNode;
    bool return_val = false;
    while(current != nullptr){
        if(current->name == name){
            if(current == _head){
                return_val = true;
                _head = current->next;
                delete current;
                _size--;
                break;
            } else if(current == _tail){
                return_val = true;
                _tail = prevNode;
                prevNode->next = nullptr;
                delete current;
                _size--;
                break;
            } else{
                return_val = true;
                prevNode->next = current->next;
                delete current;
                _size--;
                break;
            }
        }
        prevNode = current;
        current = current->next;
    }
    return return_val;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO
    // TODO
    // MyNode* newNode = new MyNode(name, score);
    // define the newNode after verifying the index
    // otherwise we can get a memory leak
    MyNode* current = _head;
    MyNode* prevNode;
    bool return_val = false;
    size_t find_index = 0;
    if(index > _size){ // index > _size, not _size - 1, because we can insert at the end
        return false;
    }
    if(index == _size){ // insert at the end, handles 0 == 0 as well
        add(name, score);
        // update tail pointer
        _tail = _tail->next;
        _size++;
        return true;
    }
    if(_head == nullptr){
        // just return false, because at this point index != _size
        return false;
    } else{
        MyNode* newNode = new MyNode(name, score);
        while(current != nullptr){
            if(find_index == index){
                break;
            }
            find_index++;
            prevNode = current; // must be done before current is updated
            current = current->next;
        }
        if(find_index == index){
            if (prevNode == nullptr) {
                _head = newNode;
                // if there is no prev node
            } else {
                current->prev->next = newNode;
            }
            // Reassign pointers
            newNode->prev = prevNode;
            newNode->next = current;
            current->prev = newNode;
            _size++;
            return_val = true;
        }
    }
    return return_val;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score) : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
