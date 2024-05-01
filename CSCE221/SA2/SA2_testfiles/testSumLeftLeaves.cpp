#define ASCENDING_PATHS
#define TEST_MODE
#include "ques.cpp"
using namespace std;

int testEmptyTree() {
    Node* root = nullptr;
    if(sumOfLeftLeaves(root) != 0) {
        return 0;
    }
    return 1;
}

int testSingleTreeNode() {
    Node root(10);
    if(sumOfLeftLeaves(&root) != 0) {
        return 0;
    }
    return 1;
}

int testTreeWithOnlyLeftChildren() {
    Node root(1), left(2), leftLeft(3);
    root.left = &left;
    left.left = &leftLeft;
    if(sumOfLeftLeaves(&root) != 3) {
        return 0;
    }
    return 4;
}

int testTreeWithOnlyRightChildren() {
    Node root(1), right(2), rightRight(3);
    root.right = &right;
    right.right = &rightRight;
    if(sumOfLeftLeaves(&root) != 0) {
        return 0;
    }
    return 4;
}

int testCompleteBinaryTree() {
    Node root(1), left(2), right(3), leftLeft(4), leftRight(5), rightLeft(6), rightRight(7);
    root.left = &left;
    root.right = &right;
    left.left = &leftLeft;
    left.right = &leftRight;
    right.left = &rightLeft;
    right.right = &rightRight;
    if(sumOfLeftLeaves(&root) != 10) {
        return 0;
    }
    return 5;
}

int testTreeWithMixedChildren() {
    Node root(1), right(3), rightLeft(11), rightRight(4), rightRightRight(5),rightRightRightLeft(6);
    root.right = &right;
    right.left = &rightLeft;
    right.right = &rightRight;
    rightRight.right = &rightRightRight;
    rightRightRight.left = &rightRightRightLeft;
    if(sumOfLeftLeaves(&root) != 17) {
        return 0;
    }
    return 5;
}

int testLargeTree() {
    Node root(1);
    Node n2(2), n3(3);
    Node n4(4), n5(5), n6(6), n7(7);
    Node n8(8), n9(9);

    root.left = &n2; root.right = &n3;
    n2.left = &n4; n2.right = &n5;
    n3.left = &n6; n3.right = &n7;
    n4.left = &n8;
    n7.right = &n9;
    if(sumOfLeftLeaves(&root) != 14) {
        return 0;
    }
    return 5;
}

int main() {
    int score = 0;
    score += testEmptyTree();
    score += testSingleTreeNode();
    score += testTreeWithOnlyLeftChildren();
    score += testTreeWithOnlyRightChildren();
    score += testCompleteBinaryTree();
    score += testTreeWithMixedChildren();
    score += testLargeTree();

    cout << "Score: " << score << " / 25" << endl;
}