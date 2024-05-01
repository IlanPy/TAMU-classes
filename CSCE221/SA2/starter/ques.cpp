#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

#ifndef ASCENDING_PATHS

// You can create helper functions for count ascending paths if required here
void recursivePaths(Node* root, bool isAscending, int prevData, int& count){
    if(root == nullptr) return;
    if(prevData >= root->data){
        isAscending = false;
    }
    if(root->left == nullptr && root->right == nullptr && isAscending){
        count++;
    }
    recursivePaths(root->left, isAscending, root->data, count);
    recursivePaths(root->right, isAscending, root->data, count);
}

int countAscendingPaths(Node* root){
    int count = 0;
    //FORGOT root != nullptr check before accessing data
    if(root != nullptr){
        recursivePaths(root, true, root->data-1, count);
    }
    return count;
}

#endif

#ifndef LEFT_LEAVES

// You can create helper functions for sum of left leaves if required here
int sums(Node* root, int& summation){
    if(root == nullptr) return 0;
    summation += sums(root->left, summation);
    if(root->left == nullptr && root->right == nullptr){
        return root->data;
    }
    sums(root->right, summation);
    return 0;
}

int sumOfLeftLeaves(Node* root) {
    int summation = 0;
    sums(root, summation);
    return summation;
}

#endif

#ifndef TEST_MODE
int main() {
    cout << "Sample Test case 1" << endl;
    {
        Node root(3);
        Node left(4), right(5);
        Node leftLeft(7), leftRight(8), rightLeft(9), rightRight(10);
        Node leftRightLeft(3), rightLeftRight(12);

        root.left = &left, root.right = &right;
        left.left = &leftLeft, left.right = &leftRight, right.left = &rightLeft, right.right = &rightRight;
        leftRight.left = &leftRightLeft, rightLeft.right = &rightLeftRight;

        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 10" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 3" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }
    cout << endl;
    cout << endl;

    cout << "Sample Test case 2" << endl;
    {
        Node root(3);
        Node right(4);
        Node rightLeft(5), rightRight(16);
        Node rightRightLeft(14);

        root.right = &right;
        right.left = &rightLeft, right.right = &rightRight;
        rightRight.left = &rightRightLeft;


        int sumReturned = sumOfLeftLeaves(&root);
        cout << "Testing sum of left leaves" << endl;
        cout << "Expected sum of left leaves: 19" << endl;
        cout << "Returned sum of left leaves: " << sumReturned << endl;

        cout << endl;

        int numAscendingPaths = countAscendingPaths(&root);
        cout << "Testing count ascending paths" << endl;
        cout << "Expected number of ascending paths: 1" << endl;
        cout << "Returned number of ascending paths: " << numAscendingPaths << endl;
    }
}
#endif