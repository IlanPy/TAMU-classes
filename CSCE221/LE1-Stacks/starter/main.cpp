#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"

int main() {
    // Write your own tests here
    StackArrayLinear<int> S;
    S.push(3);
    cout << "size: " <<  S.size() << endl;
    cout << "top: " << S.top() << endl;
    return 0;
}