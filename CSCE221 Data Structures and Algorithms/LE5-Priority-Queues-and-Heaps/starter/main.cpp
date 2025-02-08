#include "PriorityQueueHeap.h"
using namespace std;

#ifndef TEST
int main() {
    // You can write your own test cases here
    PriorityQueueHeap<int> test;
    test.pq_insert(5);
    test.pq_insert(2);
    test.pq_insert(3);
    test.pq_insert(4);
    test.pq_insert(1);
    test.print_DELETE_AFTER();
    cout << endl;
    test.pq_delete();
    test.print_DELETE_AFTER();
    // cout << test.pq_size() << endl;
    // cout << test.pq_delete();
    // cout << test.pq_size() << endl;
    // test.print_DELETE_AFTER();
    return 0;
}
#endif