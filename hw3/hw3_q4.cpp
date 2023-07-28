#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;


// floor: (int) input
// ceiling: (int) input + 1
// if (input - (int) input) < 0.5, floor 

int main(){
    double input, result;
    int choice, floor;
    bool valid = true;

    cout << "Please enter a Real Number: "<< endl;
    cin >> input;

    cout << "Choose your rounding method:" << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> choice;

    floor = (int)input;

    switch(choice){
        case 1:
            result = floor;
            break;
        case 2:
            result = floor + 1;
            break;
        case 3:
            if (input - floor < 0.5){
                result = floor;
            } else {
                result = floor + 1;
            }
            break;
        default:
            valid = false;
    }
    
    if(valid){
        cout << result;
    } else{
        cout << "Please enter a valid real number.";
    }

    return 0;

}