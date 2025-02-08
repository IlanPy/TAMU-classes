#define TEST

#include <iostream>
#include <cstdlib> 
#include <vector>
#include <ctime> 
using namespace std;
#include "deque.h"

int testInsertFirst(Deque<int> *s){
    int projectedSize = (std::rand() % 25) + 3; 

    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        s->insertFirst(randomNumber);
    }
    
    if(s->size() != projectedSize){
        return 0;
    }
    return 1;
}

int testInsertLast(Deque<int> *s){
    int projectedSize = (std::rand() % 25) + 3; 

    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        s->insertLast(randomNumber);
    }
    
    if(s->size() != projectedSize){
        return 0;
    }
    return 1;
}


int testRemoveFirst(Deque<int> *s){
    int projectedSize = (std::rand() % 50) + 5; 

    vector<int> v;
    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        v.push_back(randomNumber);
        s->insertFirst(randomNumber);
    }

    for (int i = 0; i < projectedSize; i++) {
        if (s->removeFirst() != v[v.size() - (i + 1)]) {
            return 0;
        }
    }

    if (s->size() != 0) {
        return 0;
    }
    
    return 3;
}

int testRemoveLast(Deque<int> *s){
    int projectedSize = (std::rand() % 50) + 5; 

    vector<int> v;
    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        v.push_back(randomNumber);
        s->insertFirst(randomNumber);
    }

    for (int i = 0; i < projectedSize; i++) {
        if (s->removeLast() != v[v.size() - (i + 1)]) {
            return 0;
        }
    }

    if (s->size() != 0) {
        return 0;
    }
    
    return 3;
}

int testRemoveFirst_Exception(Deque<int> *s){
    int projectedSize = (std::rand() % 25) + 3; 

    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        s->insertLast(randomNumber);
    }

    for (int i = 0; i < projectedSize; i++) {
        s->removeFirst();
    }

    try {
        s->removeFirst();
    } catch(const std::out_of_range& e) {
        return 1;
    }
    return 0;
}

int testEmpty(Deque<int> *s){
    if(!s->isEmpty()){
        return 0;
    }
    s->insertFirst(1);
    if(s->isEmpty()){
        return 0;
    }
    s->removeLast();
    if(!s->isEmpty()){
        return 0;
    }
    return 1;
}

int testLinkedListCopyAssignment() {
    Deque<int> s;
    int projectedSize = (std::rand() % 25) + 3; 

    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        s.insertFirst(randomNumber);
    }

    Deque<int> s2;
    int projectedSize2 = (std::rand() % 12) + 3; 

    for (int i = 0; i < projectedSize2; i++) {
        int randomNumber = std::rand() % 200;
        s2.insertFirst(randomNumber);
    }

    s2 = s;
    int count = 0;
    while (!s.isEmpty()) {
        count++;
        if (s2.removeFirst() != s.removeFirst()) {
            return 0;
        }
    }

    if (count != projectedSize) {
        return 0;
    }
    return 1;
}

int testCopyConstructor() {
    Deque<int> s;
    int projectedSize = (std::rand() % 25) + 3; 

    for (int i = 0; i < projectedSize; i++) {
        int randomNumber = std::rand() % 100;
        s.insertFirst(randomNumber);
    }

    Deque<int> s2(s);
    int count = 0;

     while (!s.isEmpty()) {
        count++;
        if (s2.removeLast() != s.removeLast()) {
            return 0;
        }
    }

    if (count != projectedSize) {
        return 0;
    }
    return 1;
}

int testStack() {
    Deque<int>* s = nullptr;
    int score = 0;

    try {
        s = new Deque<int>();
        int tscore = testEmpty(s);
        if (tscore == 0) {
            cout << "Test Stack Empty Function Failed" << endl;
        } else {
            cout << "Test Stack Empty Function Passed" << endl;
        }
        score += tscore;
        delete s;
    } catch (const std::exception& e) {
        cout << "Test Stack Empty Function Failed" << endl;
        delete s;
    }

    try {
        s = new Deque<int>();
        int tscore = testInsertFirst(s);
        if (tscore == 0) {
            cout << "Test Stack Push Function Failed" << endl;
        } else {
            cout << "Test Stack Push Function Passed" << endl;
        }
        score += tscore;
        delete s;
    } catch (const std::exception& e) {
        cout << "Test Stack Push Function Failed" << endl;
        delete s;
    }

    try {
        s = new Deque<int>();
        int tscore = testInsertLast(s);
        if (tscore == 0) {
            cout << "Test Stack Push Function Failed" << endl;
        } else {
            cout << "Test Stack Push Function Passed" << endl;
        }
        score += tscore;
        delete s;
    } catch (const std::exception& e) {
        cout << "Test Stack Push Function Failed" << endl;
        delete s;
    }

    try {
        s = new Deque<int>();
        int tscore = testRemoveFirst(s);
        if (tscore == 0) {
            cout << "Test Stack Pop Function Failed" << endl;
        } else {
            cout << "Test Stack Pop Function Passed" << endl;
        }
        score += tscore;
        delete s;
    } catch (const std::exception& e) {
        cout << "Test Stack Pop Function Failed" << endl;
        delete s;
    }

    try {
        s = new Deque<int>();
        int tscore = testRemoveLast(s);
        if (tscore == 0) {
            cout << "Test Stack Pop Function Failed" << endl;
        } else {
            cout << "Test Stack Pop Function Passed" << endl;
        }
        score += tscore;
        delete s;
    } catch (const std::exception& e) {
        cout << "Test Stack Pop Function Failed" << endl;
        delete s;
    }

    try {
        s = new Deque<int>();
        int tscore = testRemoveFirst_Exception(s);
        if (tscore == 0) {
            cout << "Test Stack Pop_Exception Function Failed" << endl;
        } else {
            cout << "Test Stack Pop_Exception Function Passed" << endl;
        }
        score += tscore;
        delete s;
    } catch (const std::exception& e) {
        cout << "Test Stack Pop_Exception Function Failed" << endl;
        delete s;
    }

    return score;
} 



int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int finalScore = 0;
    finalScore += testStack();

    try {
        int tscore = testCopyConstructor();
        if (tscore == 0) {
            cout << "Test Stack Copy Constructor Failed" << endl;
        } else {
            cout << "Test Stack Copy Constructor Passed" << endl;
        }
        finalScore += tscore;
    } catch (const std::exception& e) {
        cout << "Test Stack Copy Constructor Failed" << endl;
    }

    try {
        int tscore = testLinkedListCopyAssignment();
        if (tscore == 0) {
            cout << "Test Stack Copy Assignment Failed" << endl;
        } else {
            cout << "Test Stack Copy Assignment Passed" << endl;
        }
        finalScore += tscore;
    } catch (const std::exception& e) {
        cout << "Test Stack Copy Constructor Failed" << endl;
    }

    cout << endl;

    cout << "Your final score is: " << finalScore << " / 50" << endl;
    
    return 0;
}