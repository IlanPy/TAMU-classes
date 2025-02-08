#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

template <typename Type>
class BST_Node {
public:
    Type key;
    BST_Node* left;
    BST_Node* right;

    BST_Node(Type key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename Type>
class BST {
private: 
    // helper function for copy constructor
    BST_Node<Type>* copyTree(BST_Node<Type>* originalNode);
    // helper function for deallocating all nodes recursively
    void clearTree(BST_Node<Type>* node);
    // insertRecursive is helper function for insert
    void insertRecursive(BST_Node<Type>* node, Type key);
    // deleteRecursive is helper function for deleteNode
    BST_Node<Type>* deleteRecursive(BST_Node<Type>* node, Type key);
    // Helper method to find the minimum value in the subtree rooted at node (as well as the node itself)
    Type minValue(BST_Node<Type>* node);
    // Helper function for recursively searching for a key
    bool findHelper(BST_Node<Type>* node, Type lkpkey);
    // Helper function for recursively adding the in-order output key values to a string s
    void printTreeInOrderHelper(BST_Node<Type>* node, string& s);

    void printTreeLevelOrderHelper(BST_Node<Type>* node, string& s);
public:
    BST_Node<Type>* root;  
    // Constructor
    BST();
    
    // Copy Constructor
    BST(const BST& other);
    
    // Copy Assignment Operator - uses helper functions copyTree and clearTree
    BST& operator=(const BST& other);

    // Destructor
    ~BST();

    // Insert method to insert node with key
    void insert(Type key);

    // deleteNode method to delete a node with a particular key
    void deleteNode(Type key);

    // Find method to search for a key; returns true if it exists in the tree and false if it does not
    bool find(Type lkpkey);

    // Creates and returns a string that contains the tree in-order
    string printTreeInOrder();
};

template <typename Type>
BST<Type>::BST(){
    this->root = nullptr;
}

template <typename Type>
BST_Node<Type>* BST<Type>::copyTree(BST_Node<Type>* originalNode) {
    // Your implementation here
    if(originalNode == nullptr){
        return nullptr;
    }
    BST_Node<Type>* newNode = new BST_Node<Type>(originalNode->key);
    newNode->left = copyTree(originalNode->left);
    newNode->right = copyTree(originalNode->right);
    return newNode;
}

template <typename Type>
BST<Type>::BST(const BST<Type>& other){
    // Your implementation here
    this->root = copyTree(other.root);
}

template <typename Type>
BST<Type>& BST<Type>::operator=(const BST& other) {
    // Your implementation here
    if(this != &other){
        clearTree(this->root);
        this->root = copyTree(other.root);
    }
    return *this;
}

template <typename Type>
void BST<Type>::clearTree(BST_Node<Type>* node){
    // Your implementation here
    if(node != nullptr){
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

template <typename Type>
BST<Type>::~BST(){
    // Your implementation here
    clearTree(this->root);
}

template <typename Type>
void BST<Type>::insertRecursive(BST_Node<Type>* node, Type key) {
   // Your implementation here
    if(key < node->key){
            if(node->left != nullptr){
                insertRecursive(node->left, key);
            } else{
                node->left = new BST_Node<Type>(key);
            }
    } else if(key > node->key){
            if(node->right != nullptr){
                insertRecursive(node->right, key);
            } else{
                node->right = new BST_Node<Type>(key);
            }
    }
}

template <typename Type>
void BST<Type>::insert(Type key) {
    if (this->root == nullptr) {
        this->root = new BST_Node<Type>(key);
    } else {
        insertRecursive(this->root, key);
    }
}

template <typename Type>
BST_Node<Type>* BST<Type>::deleteRecursive(BST_Node<Type>* node, Type key) {
    // Your implementation here
    if(node == nullptr){
        return nullptr;
    }
    else{
        if(key == node->key){
            if(node->left == nullptr && node->right == nullptr){
                BST_Node<Type>* temp = nullptr;
                delete node;
                return temp;
            } else if(node->left == nullptr){
                BST_Node<Type>* temp = node->right;
                delete node;
                return temp;
            } else if(node->right == nullptr){
                BST_Node<Type>* temp = node->left;
                delete node;
                return temp;
            } else{
                node->key = minValue(node->right);
                node->right = deleteRecursive(node->right, node->key);
            }
        } else if(key < node->key){
            node->left = deleteRecursive(node->left, key);
        } else if(key > node->key){
            node->right = deleteRecursive(node->right, key);
        }
    }
    return node;
}

template <typename Type>
void BST<Type>::deleteNode(Type key) {
    if (this->root == nullptr) {
        return;
    }
    this->root = deleteRecursive(this->root, key);
}

// Helper method to find the minimum value in the subtree rooted at a particular node (including the node itself)
template <typename Type>
Type BST<Type>::minValue(BST_Node<Type>* node) {
    // Your implementation here
    if(node == nullptr){
        return Type();
    }
    while(node->left != nullptr){
        node = node->left;
    }
    return node->key;
}

template <typename Type>
bool BST<Type>::findHelper(BST_Node<Type>* node, Type lkpkey) {
    // Your implementation here
    if(node == nullptr){
        return false;
    }
    else{
        if(lkpkey == node->key){
            return true;
        }
        else if(lkpkey < node->key){
            return findHelper(node->left, lkpkey);
        }
        else{
            return findHelper(node->right, lkpkey);
        }
    }
}

template <typename Type>
bool BST<Type>::find(Type lpkey) {
    if (this->root == nullptr) {
        return false;
    }
    return findHelper(this->root, lpkey);
}

template <typename Type>
void BST<Type>::printTreeInOrderHelper(BST_Node<Type>* node, string& s) {
    // Your implementation here
    if(node != nullptr){
        printTreeInOrderHelper(node->left, s);
        s += to_string(node->key) + " ";
        printTreeInOrderHelper(node->right, s);
    }
}

template <typename Type>
void BST<Type>::printTreeLevelOrderHelper(BST_Node<Type>* node, string& s) {
    // Your implementation here
    s += to_string(node->key) + " \n";

    if(node != nullptr){
        printTreeInOrderHelper(node->left, s);
        s += to_string(node->key) + " ";
        printTreeInOrderHelper(node->right, s);
    }
}

template <typename Type>
string BST<Type>::printTreeInOrder() {
    if (this->root == nullptr) {
        return "";
    }
    string s = "";
    printTreeInOrderHelper(this->root, s);
    return s;
}

#endif


