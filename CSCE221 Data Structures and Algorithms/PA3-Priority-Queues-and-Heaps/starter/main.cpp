#include "AbstractPriorityQueue.h"
#include "PriorityQueueHeap.h"
#include "UnsortedPriorityQueue.h"
#include "SortedPriorityQueue.h"
#include <chrono>
#include <vector>
#include <fstream>
#include <math.h>
using namespace std;

#ifndef TEST
void insertIntoQueueHeap(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=4; k++){
        for(int j = 1; j < 9; j+=3){
            PriorityQueueHeap<int> queue;
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 100000;
                queue.pq_insert(randomNumber);
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
        }
    }
    PriorityQueueHeap<int> queue;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<pow(10,5); i++){
        int randomNumber = std::rand() % 100000;
        queue.pq_insert(randomNumber);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    result.push_back(duration.count());

    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

void sortQueueHeap(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=4; k++){
        for(int j = 1; j < 9; j+=3){
            PriorityQueueHeap<int> queue;
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 100000;
                queue.pq_insert(randomNumber);
            }
            for(int i=0; i<j*pow(10,k); i++){
               queue.pq_delete();
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
        }
    }

    PriorityQueueHeap<int> queue;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<pow(10,5); i++){
        int randomNumber = std::rand() % 100000;
        queue.pq_insert(randomNumber);
    }
    for(int i=0; i<pow(10,5); i++){
        queue.pq_delete();
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    result.push_back(duration.count());

    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

void insertIntoQueueSorted(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=4; k++){
        for(int j = 1; j < 9; j+=3){
            SortedPriorityQueue<int> queue;
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 100000;
                queue.pq_insert(randomNumber);
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
        }
    }

    SortedPriorityQueue<int> queue;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<pow(10,5); i++){
        int randomNumber = std::rand() % 100000;
        queue.pq_insert(randomNumber);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    result.push_back(duration.count());

    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

void sortQueueSorted(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=4; k++){
        for(int j = 1; j < 9; j+=3){
            SortedPriorityQueue<int> queue;
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 100000;
                queue.pq_insert(randomNumber);
            }
            for(int i=0; i<j*pow(10,k); i++){
               queue.pq_delete();
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
        }
    }
    SortedPriorityQueue<int> queue;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<pow(10,5); i++){
        int randomNumber = std::rand() % 100000;
        queue.pq_insert(randomNumber);
    }
    for(int i=0; i<pow(10,5); i++){
        queue.pq_delete();
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    result.push_back(duration.count());

    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

void insertIntoQueueUnsorted(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=4; k++){
        for(int j = 1; j < 9; j+=3){
            UnsortedPriorityQueue<int> queue;
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 100000;
                queue.pq_insert(randomNumber);
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
        }
    }
    UnsortedPriorityQueue<int> queue;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<pow(10,5); i++){
        int randomNumber = std::rand() % 100000;
        queue.pq_insert(randomNumber);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    result.push_back(duration.count());
    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

void sortQueueUnsorted(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=4; k++){
        for(int j = 1; j < 9; j+=3){
            UnsortedPriorityQueue<int> queue;
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 100000;
                queue.pq_insert(randomNumber);
            }
            for(int i=0; i<j*pow(10,k); i++){
               queue.pq_delete();
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
        }
    }
    UnsortedPriorityQueue<int> queue;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<pow(10,5); i++){
        int randomNumber = std::rand() % 100000;
        queue.pq_insert(randomNumber);
    }
    for(int i=0; i<pow(10,5); i++){
        queue.pq_delete();
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    result.push_back(duration.count());
    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

// void insertIntoQueue(AbstractPriorityQueue<int>& queue, string name){
//     vector<int> result;
//     ofstream fout;
//     fout.open(name + ".csv");
//     for(int k=0; k<=8; k++){
//         auto start = chrono::high_resolution_clock::now();
//         for(int i=0; i<k*pow(10,4); i++){
//             queue.pq_insert(i);
//         }

//         auto stop = chrono::high_resolution_clock::now();
//         auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//         result.push_back(duration.count());
//     }

//     for(int i=0; i<result.size(); i++){
//         fout<<i*pow(10,4)<<","<<result[i]<<endl;
//     }
//     fout.close();
// }

// void sortQueue(AbstractPriorityQueue<int>& queue, string name){
//     vector<int> result;
//     ofstream fout;
//     fout.open(name + ".csv");
//     for(int k=0; k<=8; k++){
//         auto start = chrono::high_resolution_clock::now();
//         for(int i=0; i<k*pow(10,4); i++){
//             queue.pq_insert(i);
//         }
//         for(int i=0; i<k*pow(10,4); i++){
//             queue.pq_delete();
//         }

//         auto stop = chrono::high_resolution_clock::now();
//         auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//         result.push_back(duration.count());
//     }
// }

int main() {
    SortedPriorityQueue<int> queue;
    queue.pq_insert(3);
    queue.pq_insert(2);
    queue.pq_insert(5);
}
#endif