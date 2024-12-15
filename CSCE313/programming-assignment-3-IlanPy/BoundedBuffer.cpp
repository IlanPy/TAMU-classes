#include "BoundedBuffer.h"

using namespace std;


BoundedBuffer::BoundedBuffer (int _cap) : cap(_cap) {
    // modify as needed
}

BoundedBuffer::~BoundedBuffer () {
    // modify as needed
}

void BoundedBuffer::push (char* msg, int size) {
    // 1. Convert the incoming byte sequence given by msg and size into a vector<char>
    // 2. Wait until there is room in the queue (i.e., queue lengh is less than cap)
    // 3. Then push the vector at the end of the queue
    // 4. Wake up threads that were waiting for push
    vector<char> bytes(msg, msg + size); // (1)
    unique_lock<mutex> ulck(lck); // (2)
    cv_of.wait(ulck, [this]{ return q.size() < (long unsigned int)cap; });
    q.push(bytes); // (3)
    ulck.unlock(); // (4)
    cv_uf.notify_one();
}

int BoundedBuffer::pop (char* msg, int size) {
    // 1. Wait until the queue has at least 1 item
    // 2. Pop the front item of the queue. The popped item is a vector<char>
    // 3. Convert the popped vector<char> into a char*, copy that into msg; assert that the vector<char>'s length is <= size
    // 4. Wake up threads that were waiting for pop
    // 5. Return the vector's length to the caller so that they know how many bytes were popped
    unique_lock<mutex> ulck(lck); // (1)
    cv_uf.wait(ulck, [this]{ return q.size() >= 1; });
    vector<char> item = q.front(); // (2)
    q.pop();
    assert(item.size() <= (long unsigned int)size); // (3)
    memcpy(msg, item.data(), item.size());
    ulck.unlock(); // (4)
    cv_of.notify_one();
    return item.size(); // (5)
}

size_t BoundedBuffer::size () {
    return q.size();
}
