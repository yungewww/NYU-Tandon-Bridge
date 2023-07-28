#include <iostream>
using namespace std;

int main(){
    int n, input, even, odd;

    cout << "Please enter a positive integer: ";
    cin >> input;

    n = input;
    
    for (int i = 1; i <= n; i++){
        even = 0;
        odd = 0;
        
        for (int j = i; j > 0; j /= 10){
            if(j % 2 == 0){
                even += 1;
            } else if (j % 2 == 1){
                odd += 1;
            }
        }
        
        if (even > odd){
            cout << i << endl;
        }
    }

    return 0;
}