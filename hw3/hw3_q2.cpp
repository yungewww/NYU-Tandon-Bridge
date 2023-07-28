#include <iostream>
#include <string>
using namespace std;


int main(){
    string name, status;
    int graduationY, currentY, offset;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> graduationY;
    cout << "Please enter current year: ";
    cin >> currentY;

    offset = graduationY - currentY;

    if (offset <= 0){
        status = "Graduated";
    } else if (offset == 1){
        status = "Senior";
    }else if (offset == 2){
        status = "Junior";
    }else if (offset == 3){
        status = "Sophomore";
    }else if (offset == 4){
        status = "Freshman";
    }else if (offset > 5){
        status = "not in school yet";
    }

    cout << name << ", you are a " << status;

    return 0;

}
