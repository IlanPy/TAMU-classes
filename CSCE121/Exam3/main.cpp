#include "linked_list.h"

int main(){
    LinkedList ll;
    ll.insert(18);
    ll.insert(7);
    ll.insert(15);
    ll.insert(27);
    // std::cout << ll.average() << std::endl;
    // ll.remove_maximum();
    // ll.reverse_list();
    ll.print();
    std::cout << ll.middle_of_list()->value << std::endl;
    ll.print();
}