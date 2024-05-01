#include <iostream>
#include "deque.h"
#include "string.h"
using namespace std;

int main() {
    Deque<string> deque;
    deque.insertFirst("S");
    deque.insertLast("E");
    deque.insertLast("L");
    deque.insertLast("A");
    deque.insertFirst("N ");
    deque.insertFirst("ILA");
    // for(int i = 0; i < 6; i++){
    //     std::cout << deque.removeFirst();
    // } std::cout << endl;
    Deque<string> deque2(deque);
    Deque<string> deque3;
    deque3 = deque;
    // for(int i = 0; i < 6; i++){
    //     std::cout << deque2.removeFirst();
    // } std::cout << endl;
    for(int i = 0; i < 6; i++){
        std::cout << deque3.removeFirst();
    } std::cout << endl;
    // try {
    //     // Test constructor
    //     Deque<int> deque;

    //     // Test isEmpty on an empty deque
    //     std::cout << "Is deque empty? " << (deque.isEmpty() ? "Yes" : "No") << std::endl;

    //     // Test size on an empty deque
    //     std::cout << "Deque size: " << deque.size() << std::endl;

    //     // Test invalid first and last on an empty deque
    //     try {
    //         std::cout << "First element: " << deque.first() << std::endl; // Should throw std::out_of_range exception
    //     } catch (const std::out_of_range& e) {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }

    //     try {
    //         std::cout << "Last element: " << deque.last() << std::endl; // Should throw std::out_of_range exception
    //     } catch (const std::out_of_range& e) {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }

    //     // Test invalid removeFirst and removeLast on an empty deque
    //     try {
    //         std::cout << "Removed first element: " << deque.removeFirst() << std::endl; // Should throw std::out_of_range exception
    //     } catch (const std::out_of_range& e) {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }

    //     try {
    //         std::cout << "Removed last element: " << deque.removeLast() << std::endl; // Should throw std::out_of_range exception
    //     } catch (const std::out_of_range& e) {
    //         std::cerr << "Exception: " << e.what() << std::endl;
    //     }

    //     // Test insertFirst and insertLast with various elements
    //     deque.insertFirst(1);
    //     deque.insertLast(2);
    //     deque.insertFirst(3);
    //     deque.insertLast(4);

    //     // Test size after insertions
    //     std::cout << "Deque size after insertions: " << deque.size() << std::endl;

    //     // Test first and last after insertions
    //     std::cout << "First element: " << deque.first() << std::endl;
    //     std::cout << "Last element: " << deque.last() << std::endl;

    //     // Test removeFirst and removeLast after insertions
    //     std::cout << "Removed first element: " << deque.removeFirst() << std::endl;
    //     std::cout << "Removed last element: " << deque.removeLast() << std::endl;

    //     // Test size after removals
    //     std::cout << "Deque size after removals: " << deque.size() << std::endl;

    //     // Test isEmpty after removals
    //     std::cout << "Is deque empty after removals? " << (deque.isEmpty() ? "Yes" : "No") << std::endl;

    //     // Test inserting and removing a single element
    //     deque.insertFirst(5);
    //     std::cout << "Removed single element: " << deque.removeFirst() << std::endl;

    //     // Test size after single element removal
    //     std::cout << "Deque size after single element removal: " << deque.size() << std::endl;

    //     // Test isEmpty after single element removal
    //     std::cout << "Is deque empty after single element removal? " << (deque.isEmpty() ? "Yes" : "No") << std::endl;
    // } catch (const std::out_of_range& e) {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }

    return 0;
}

// int main() {
//     // Test insertFirst
//     {
//         Deque<int> q;
//         q.insertFirst(3);
//         q.insertFirst(2);
//         q.insertFirst(1);
//         q.insertLast(8);
//         q.insertLast(7);
//         q.insertLast(6);
//         cout << q.size() << endl;
//         Deque<int> q2(q);
//         for(int i = 0; i < 6; i++){
//             cout << q2.last() << " ";
//             q2.removeLast();
//         }
//         cout << endl;
//         // for(int i = 0; i < 6; i++){
//         //     q.removeLast();
//         // }
//         q.~Deque();
//         q.insertFirst(3);
//         q.insertFirst(2);
//         q.insertFirst(1);
//         // Now the deque should be [1, 2, 3]
        
//         if (q.size() != 3) {
//             cout << "Test insertFirst failed: Incorrect size" << endl;
            
//         } else if (q.first() != 1 || q.last() != 3) {
//             cout << "Test insertFirst failed: Incorrect elements" << endl;
   
//         } else {
//             cout << "Test insertFirst passed" << endl;
//         }
        
//     }
    
//     // Test insertLast
//     {
//         Deque<int> q;
//         q.insertLast(1);
//         q.insertLast(2);
//         q.insertLast(3);
        
//         // Now the deque should be [1, 2, 3]
        
//         if (q.size() != 3) {
//             cout << "Test insertLast failed: Incorrect size" << endl;
//         } else if (q.first() != 1 || q.last() != 3) {
//             cout << "Test insertLast failed: Incorrect elements" << endl;
//         } else {
//             cout << "Test insertLast passed" << endl;
//         }
        
//     }

//     return 0;
// }