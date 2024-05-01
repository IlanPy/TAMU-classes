#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "StackArrayDouble.h"
#include "StackArrayLinear.h"
#include "StackLinkedList.h"
#include <ctime>
#include <chrono>

int main() {
    // Write your own tests here
    StackLinkedList<int> S;
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000000; i++){
        S.push(i);
    }
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "elapsed time: " << microseconds << " us" << endl;
    // StackLinkedList<int> S;
    // S.push(30);
    // S.push(200);
    // StackLinkedList<int> S2(S);
    // while(!S.isEmpty()){
    //     std::cout << S.pop() << " ";
    // }
    // std::cout << endl;
    // while(!S2.isEmpty()){
    //     std::cout << S2.pop() << " ";
    // }
    // StackLinkedList<int> s = StackLinkedList<int>();
    // int projectedSize = (std::rand() % 25) + 3; 

    // for (int i = 0; i < projectedSize; i++) {
    //     int randomNumber = std::rand() % 100;
    //     s.push(randomNumber);
    // }

    // StackLinkedList<int> s2(s);

    // int count = 0;
    // while (!s.isEmpty()) {
    //     count++;
    //     if (s2.pop() != s.pop()) {
    //         return 0;
    //     }
    // }
    // std::cout << count << endl;
    // return 0;
}