#include <iostream>
using namespace std;

int main(){
    int a, b;

    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << (double) a / b << endl;
    cout << a << " div " << b << " = " << a / b << endl;
    cout << a << " mod " << b << " = " << a % b << endl;

    return 0;

}