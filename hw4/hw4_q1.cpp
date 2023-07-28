#include <iostream>
using namespace std;


int main(){
    int n;

    // using while loop
    cout << "Please enter a positive integer: ";
    cin >> n;

    int j = 1;
    while (j <= n){
        cout << 2 * j << endl;
        j++;
    }

    // using for loop
    cout << "Please enter a positive integer: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << 2 * i << endl;
    }

    return 0;

}