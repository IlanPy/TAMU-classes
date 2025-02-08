#include <iostream>
// EXAM 1 ##########################################
void multiples(int n, int k, int l){
    int count = 0;
    for(int i = 1; count < n; i++){
        if(i%k == 0 || i%l == 0){
            std::cout << i << " ";
            count++;
        }
    }
    std::cout << std::endl;
}

void triproduct(int n){
    int product = 0, low = 1, mid = 2, high = 3;
    while(product < n){
        product = (low++)*(mid++)*(high++);
    }
    if(product == n){
        std::cout << --low << " * " << --mid << " * " 
            << --high << " = " << n << std::endl;
    } else{
        std::cout << n << " is not a triproduct" << std::endl;
    }
}

void array_segments(int n){
    srand(time(0));
    int* array = new int[n];
    for(int i = 0; i < n; i++){
        array[i] = (rand() % 10);
        std::cout << array[i] << " ";
    }
    int set_value = -1;
    int segment = 0;
    for(int i = 0; i < n; i++){
        if(array[i] != set_value){
            segment++;
            set_value = array[i];
        }
    }
    delete[] array;
    std::cout << "| " << segment << std::endl;
}

void find_sum(int n, int k){
    int number = 1;
    int* array = new int[n];
    for(int i = 0; i < n; i++){
        array[i] = number;
        number+=1;
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n; j++){
            if(array[i]+array[j] == k && i != j){
                std::cout << array[i] << " " << array[j] << std::endl;
            }
        }
    }
    delete[] array;
}

void isHappy(int n){
    int cp = 0;
    int cp2 = n;
    if(n < 0){std::cout << n << " is unhappy :(" << std::endl;} else{
        std::cout << n;
        while(cp != 4 && cp != 1){
            cp = 0;
            while(cp2 != 0){
                cp += (cp2%10)*(cp2%10);
                cp2 = cp2/10;
            }
            cp2 = cp;
            std::cout << "->" << cp2;
        }
        std::cout << std::endl;
    }
}

int row_add(int n){
    int k = 1;
    int sum = 0;
    int row_length = 1;
    while(row_length < n){
        for(int i = 0; i < row_length; i++){
            k++;
        }
        row_length++;
    }
    for(int i = 0; i < row_length; i++){
        sum += k*k;
        k++;
    }
    return sum;
}

// EXAM 2 ##########################################

// EXAM 3 ##########################################
struct Node {
  int value;
  Node* next;
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {
  Node* head;

 public:
  LinkedList() : head{nullptr} {}
  ~LinkedList(){
    clear();
  }
  void clear(){
    Node* current = head;
    Node* NextNode;
    while(current != nullptr){
        NextNode = current->next;
        delete current;
        current = NextNode;
    }
    head = nullptr;
  }
  void insert(int value){
    Node* ptr = new Node(value);
    if(head == nullptr){
        head = ptr;
    } else{
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = ptr;
    }
  }
  void print(){
    Node* current = head;
    while(current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    } std::cout << std::endl;
  }
  // other member functions
  double average();
  void remove_max();
  void reverse_list();
  Node* middle_of_the_list();
  bool cycle();
  void test_cycle();
};

double LinkedList::average(){
    Node* current = head;
    if(head == nullptr){
        throw std::invalid_argument("");
    }
    double total = 0;
    int amount = 0;
    while(current != nullptr){
        total += current->value;
        amount++;
        current = current->next;
    }
    return total/amount;
}

void LinkedList::remove_max(){
    if(head == nullptr){} else{
        Node* current = head;
        int max = current->value;
        while(current != nullptr){
            if(max < current->value){
                max = current->value;
            }
            current = current->next;
        }
        current = head;
        Node* prev_node = nullptr;
        while(current != nullptr){
            if(current->value == max){
                if(current == head){
                    head = current->next;
                    delete current;
                    current = head;
                }
                else{
                    prev_node->next = current->next;
                    delete current;
                    current = prev_node->next;
                }
            } else{
                prev_node = current;
                current = current->next;
            }
        }
    }
}

void LinkedList::reverse_list(){
    Node* current = head;
    Node* prev_node = nullptr;
    Node* next_node = nullptr;
    while(current != nullptr){
        next_node = current->next;
        current->next = prev_node;
        prev_node = current;
        current = next_node;
    }
    head = prev_node;
}

Node* LinkedList::middle_of_the_list(){
    int size = 0;
    Node* current = head;
    while(current != nullptr){
        size++;
        current = current->next;
    }
    current = head;
    int index = size/2 + 1;
    int count = 0;
    while(current != nullptr){
        count++;
        if(count == index){
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

bool LinkedList::cycle(){
    Node* turtle = head;
    //I HAD MISSED
    if(turtle == nullptr){ return false; }
    Node* rabbit = head->next;
    while(rabbit != nullptr && rabbit->next != nullptr){
        if(turtle == rabbit){
            return true;
        }
        turtle = turtle->next;
        rabbit = rabbit->next->next;
    }
    return false;
}

void LinkedList::test_cycle(){
    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = head->next;
    std::cout << this->cycle() << std::endl;
}

bool isPalindrome(int number){
    //base case
    unsigned int n;
    if(number < 0){
        n = -number;
    } else{
        n = number;
    }
    bool return_val;
    int first_num, last_num;
    if(n < 10){
        return_val = true;
    } else{
        //recursive case
        int divisor = 1;
        while(n/divisor >= 10){
            divisor*=10;
        }
        last_num = n % 10;
        first_num = n / divisor;
        if(first_num == last_num){
            n %= divisor;
            n /= 10;
            return_val = isPalindrome(n);
        } else{
            return_val = false;
        }
    }
    return return_val;
}

int main(){
    // EXAM 1
    multiples(6, 2, 3);
    std::cout << "-----" << std::endl;
    triproduct(120);
    std::cout << "-----" << std::endl;
    array_segments(11);
    std::cout << "-----" << std::endl;
    find_sum(8,8);
    std::cout << "-----" << std::endl;
    isHappy(28);
    std::cout << "-----" << std::endl;
    std::cout << row_add(3) << std::endl;
    std::cout << "-----" << std::endl;
    // EXAM 3
    LinkedList ll;
    ll.insert(18); ll.insert(7); ll.insert(15); ll.insert(27);
    std::cout << ll.average() << std::endl;
    std::cout << "-----" << std::endl;
    ll.remove_max();
    ll.print();
    std::cout << "-----" << std::endl;
    ll.clear(); ll.insert(18); ll.insert(7); ll.insert(15); ll.insert(27);
    ll.reverse_list();
    ll.print();
    std::cout << "-----" << std::endl;
    ll.clear(); 
    ll.insert(18); ll.insert(7); ll.insert(15); ll.insert(27);
    Node* current = ll.middle_of_the_list();
    std::cout << current->value << std::endl;
    std::cout << "-----" << std::endl;
    // ll.test_cycle();
    int i = 18344381;
    std::cout << isPalindrome(i) << std::endl;
}