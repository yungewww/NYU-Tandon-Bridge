#include <iostream>
#include <string>
using namespace std;

// M = n / 1000
// D = n % 1000 / 500
// C = n % 500 / 100
// L = n % 100 / 50
// X = n % 50 / 10
// V = n % 10 / 5
// I = n % 5 / 1

int main(){
    int n;
    int M, D, C, L, X, V, I;
    string roman = "";

    cout << "Enter decimal number: " << endl;
    cin >> n;

    // calculation
    M = n / 1000;
    D = n % 1000 / 500;
    C = n % 500 / 100;
    L = n % 100 / 50;
    X = n % 50 / 10;
    V = n % 10 / 5;
    I = n % 5 / 1;

    // pushing the characters into the roman numerical string
    for(int i = 0; i < M; i ++){
        roman.push_back('M');
    }
    for(int i = 0; i < D; i ++){
        roman.push_back('D');
    }
    for(int i = 0; i < C; i ++){
        roman.push_back('C');
    }
    for(int i = 0; i < L; i ++){
        roman.push_back('L');
    }
    for(int i = 0; i < X; i ++){
        roman.push_back('X');
    }
    for(int i = 0; i < V; i ++){
        roman.push_back('V');
    }
    for(int i = 0; i < I; i ++){
        roman.push_back('I');
    }
    
    // output
    cout << n << " is " << roman << endl;
    
    return 0;
    
}