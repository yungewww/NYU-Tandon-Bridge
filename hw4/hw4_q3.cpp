#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, value, sum;
    int count = 0;

    cout << "Enter decimal number: " << endl;
    cin >> n;
    
    for (int i = n; i > 0; i /= 2){
        if (i % 2 == 0){
            value = 0;
        } else if (i % 2 == 1){
            value = 1;
        }
        
        value *= pow(10, count);
        count++;
        sum += value;
    }
    
    cout << "The binary representation of " << n << " is " << sum << endl;
 
    return 0;
}