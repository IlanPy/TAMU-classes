#include "lru.h"

int main() {
    LRUCache cache1(3);
    cache1.insertKeyValue("mango", 10);
    cache1.insertKeyValue("apple", 20);
    cache1.insertKeyValue("guava", 30);
    if (cache1.mostRecentKey() == "guava") {
        std::cout << "Test Case 1 passed: Most recent key is guava\n";
    } else {
        std::cout << "Test Case 1 failed: Most recent key is not guava\n";
    }
    // Test Case 4: Insert Additional Items (Cache Full)
    cache1.insertKeyValue("banana", 20);
    int temp_score = 0;
    if (cache1.getValue("guava") == nullptr && cache1.mostRecentKey() == "banana") {
        cache1.insertKeyValue("orange", 3);
        cache1.insertKeyValue("pineapple", 2);
        
        if (cache1.mostRecentKey() == "pineapple") {
            int* orangeValue = cache1.getValue("orange");
            
            if (orangeValue != nullptr && *orangeValue == 3 && cache1.mostRecentKey() == "orange" 
                        && cache1.getValue("mango") == nullptr && cache1.getValue("apple") == nullptr) {
                int* pineappleValue = cache1.getValue("pineapple");
                if (pineappleValue != nullptr && *pineappleValue == 2 && cache1.mostRecentKey() == "pineapple") {
                    temp_score = 5;
                    std::cout << "Test Case 4 passed: Correct cache state after inserting additional items\n";
                } 
            }
        }
    }
}