#include "skiplist.h"

int main() {
    int score = 0;
    int maxLevel = 10;
    double probability = 0.5;
    SkipList skipList(maxLevel, probability);
    srand(time(0));

    skipList.insertElement(3);
    skipList.insertElement(6);
    skipList.insertElement(9);
    skipList.insertElement(2);
    skipList.insertElement(8);
    skipList.deleteElement(3);
    skipList.insertElement(4);
    skipList.insertElement(5);
    skipList.displayList();
    return 0;
}