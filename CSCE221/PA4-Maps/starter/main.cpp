#include "AbstractHashTable.h"
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
using namespace std;
#include <unordered_map>
#include <chrono>

vector<string> words;
void insertInto1(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=6; k++){
        for(int j = 1; j < 9; j+=3){
            AbstractHashTable* pht = new ProbingHashTable();
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 1000000;
                pht->insert(words[randomNumber], randomNumber-i);
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
            delete pht;
        }
    }
    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();

}
void insertInto2(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=6; k++){
        for(int j = 1; j < 9; j+=3){
            AbstractHashTable* dht = new DoubleHashTable();
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 1000000;
                dht->insert(words[randomNumber], randomNumber-i);
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
            delete dht;
        }
    }
    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}
void insertInto3(string name){
    vector<int> result;
    ofstream fout;
    fout.open(name + ".csv");
    for(int k=1; k<=6; k++){
        for(int j = 1; j < 9; j+=3){
            AbstractHashTable* cht = new ChainingHashTable();
            auto start = chrono::high_resolution_clock::now();
            for(int i=0; i<j*pow(10,k); i++){
                int randomNumber = std::rand() % 1000000;
                cht->insert(words[randomNumber], randomNumber-i);
            }

            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
            result.push_back(duration.count());
            delete cht;
        }
    }
    for(int i=0; i<result.size(); i++){
        fout<<result[i]<<endl;
    }
    fout.close();
}

int main() {
    std::string filename = "dictionary.txt";
    std::ifstream file(filename);
    std::srand(time(NULL));
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 0;
    }
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
    insertInto1("probe");
    insertInto2("double");
    insertInto3("chaining");

    
    return 0;
}