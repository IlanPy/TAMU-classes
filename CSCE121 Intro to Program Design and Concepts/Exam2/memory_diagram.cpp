#include <iostream>
using std::cout;
using std::endl;

int sideEffectSum(int c, int& d) {
    c *= 3;
    d /= 2;
    return  c + d;
}

int swapIfEvenSum(int& a, int& b) {
    if ((a+b)%2 == 0) {
        int temp = a;
        a = b;
        b = temp;
    }
    return sideEffectSum(a, b);
}

int heapSum(int* e, int* f) {
    return *e + *f;
}


int main()
{
    int z = 12;
    int y = 7;

    int *w = new int(swapIfEvenSum(z, y));
    cout << y << " " << z << endl;
    z++;
    int *v = new int(swapIfEvenSum(z, y));
    cout << y << " " << z << endl;

    int u = heapSum(w,v);

    cout << u << " " << *v << " " << *w << " ";
    cout << y << " " << z << endl;

    delete w;
    delete v;
    
    return 0;
}
