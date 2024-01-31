#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"
#include "StackLinkedList.h"

int main() {
    // Write your own tests here
    StackLinkedList<int> S;
    S.push(3);
    cout << S.top() << endl;
    cout << S.size() << endl;
    S.push(5);
    S.push(6);
    cout << S.top() << endl;
    cout << S.size() << endl;
    return 0;
}