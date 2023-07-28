#include <iostream>
#include <cmath>
#include  <iomanip>
using namespace std;

int main(){
    int length, input;
    int product = 1;
    double gmean;
    bool continueOrNot = true;

    // Part A

    cout << "Please enter the length of the sequence: ";
    cin >> length;
    cout << "Please enter your sequence:" << endl;

    for (int i = 0; i < length; i++){
        cin >> input;
        product *= input; 
    }

    gmean = pow(product, (double) 1/length);

    cout << fixed << setprecision(4) << "The geometric mean is: " << gmean << endl;

    // Part B
    
    cout << "\nPlease enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: " << endl;

    length = 0;
    product = 1;
    while (continueOrNot){
        cin >> input;
        if (input == -1){
            continueOrNot = false;
        } else {
            product *= input; 
            length++;
        }   
    }

    gmean = pow(product, (double) 1/length);

    cout << fixed << setprecision(4) << "The geometric mean is: " << gmean << endl;

    return 0;
}