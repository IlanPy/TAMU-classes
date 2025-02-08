#include "bst.h"
using namespace std;

#ifndef TEST
int main() {
    // You can write your own test cases here
    BST<int>* bst = new BST<int>();
    bst->insert(10);
    bst->insert(1);
    bst->insert(5);
    bst->insert(20);
    bst->insert(3);
    bst->insert(21);
    // cout << bst->find(20) << endl;
    // cout << bst->find(11) << endl;
    cout << bst->printTreeInOrder() << endl;
    bst->deleteNode(3);
    cout << bst->printTreeInOrder() << endl;
    return 0;
}
#endif