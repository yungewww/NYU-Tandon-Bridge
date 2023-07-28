#include <iostream>
using namespace std;

// 0 blank + (2n - 1 - 2l) asterisk 7
// 1 blank + (2n - 1 - 2l) asterisk 5
// 2 blank + (2n - 1 - 2l) asterisk 3
// 3 blank + (2n - 1 - 2l) asterisk 1

int main(){
    int n;
    // b for blank, a for asterisk, l for line

    cout << "Input a positive integer: ";
    cin >> n;
    
    // reversed triangle
    for (int l = 0; l < n; l++){
        cout << "\n";
        for (int b = l; b > 0; b--){
            cout << " ";
        }
        for(int a = (2 * n - 1 - 2 * l); a > 0; a--){
            cout << "*";
        }
    }
    
    // triangle
    for (int l = 0; l < n; l++){
        cout << "\n";
        for (int b = n - l - 1; b > 0; b--){
            cout << " ";
        }
        for(int a = (2 * l + 1); a > 0; a--){
            cout << "*";
        }
    }

    cout << endl;
    return 0;

}