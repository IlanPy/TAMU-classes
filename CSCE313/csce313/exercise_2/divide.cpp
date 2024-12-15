/*
Example: Division by zero fault, not handled.
*/

#include <iostream>
using namespace std;

float divide(float numerator, float denominator)
{
    if(denominator == 0){
        throw runtime_error("Exception caught - Math error: Zero Division");
    }
    return (numerator / denominator);
}

int main()
{
    float numerator;
    float denominator;
    float quotient;

    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Enter the denominator: ";
    cin >> denominator;

    try{
        quotient = divide(numerator, denominator);
        cout << "The quotient is: " << quotient << endl;
        cout << "More instructions to execute." << endl;
    }
    catch(const runtime_error& e){
        cout << e.what() << endl;
    }
}