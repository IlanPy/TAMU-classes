#define LEFT_LEAVES
#define TEST_MODE
#include "ques.cpp"
using namespace std;

int testEmptyTree() {
    Node* root = nullptr;
    if(countAscendingPaths(root) != 0){
        return 0;
    }
    return 1;
}

int testLinearAscendingTree() {
    Node root(1), node1(2), node2(3);
    root.right = &node1;
    node1.right = &node2;
    if(countAscendingPaths(&root) != 1) {
        return 0;
    }
    return 4;
}

int testLinearDescendingTree() {
    Node root(3), node1(2), node2(1);
    root.right = &node1;
    node1.right = &node2;
    if(countAscendingPaths(&root) != 0) {
        return 0;
    }
    return 4;
}

int testCompleteBinaryTreeAscendingValues() {
    Node root(1), left(2), right(3), leftLeft(4), leftRight(5), rightLeft(6), rightRight(7), leftLeftLeft(8), leftLeftRight(9),leftLeftLeftLeft(10); 
    root.left = &left;
    root.right = &right;
    left.left = &leftLeft;
    left.right = &leftRight;
    right.left = &rightLeft;
    right.right = &rightRight;
    leftLeft.left = &leftLeftLeft;
    leftLeft.right = &leftLeftRight;
    leftLeftLeft.left = &leftLeftLeftLeft;
    if(countAscendingPaths(&root) != 5) {
        return 0;
    }
    return 5;
}

int testTreeWithMixedValues() {
    Node root(2), left(1), right(3), leftLeft(4), rightLeft(5), rightRight(6), rightRightLeft(7), rightRightRight(8),rightRightRightLeft(9);
    root.left = &left;
    root.right = &right;
    left.left = &leftLeft;
    right.left = &rightLeft;
    right.right = &rightRight;
    rightRight.left = &rightRightLeft;
    rightRight.right = &rightRightRight;
    rightRightRight.left = &rightRightRightLeft;
    if(countAscendingPaths(&root) != 3) {
        return 0;
    }
    return 6;
}

int testTreeWithEqualValues() {
    Node root(2), left(2), right(2), leftLeft(2), leftRight(2);
    root.left = &left;
    root.right = &right;
    left.left = &leftLeft;
    left.right = &leftRight;
    if(countAscendingPaths(&root) != 0) {
        return 0;
    }
    return 5;
}

int main() {
    int score = 0;
    score += testEmptyTree();
    score += testLinearAscendingTree();
    score += testLinearDescendingTree();
    score += testCompleteBinaryTreeAscendingValues();
    score += testTreeWithMixedValues();
    score += testTreeWithEqualValues();

    cout << "Score: " << score << " / 25" << endl;
}