#include <iostream>
using namespace std;

// 1 dollar = 100 cents
// 1 quarter = 25 cents
// 1 dime = 10 cents
// 1 nickel = 5 cents
// 1 penny = 1 cent

int main(){
    int dollar, cent, quarter, dime, nickel, penny;
    int sum;

    cout << "Please enter your amount in the format of dollars and cents separated by a space: \n";
    cin >> dollar >> cent;

    sum = 100 * dollar + cent;

    quarter = sum / 25;
    dime = (sum - 25 * quarter) / 10;
    nickel = (sum - 25 * quarter - 10 * dime) / 5;
    penny = sum - 25 * quarter - 10 * dime - 5 * nickel;

    cout << dollar << " dollars and " << cent << " cents are:" << endl;

    cout << quarter << " quarters, " << dime << " dimes, " << nickel << " nickels, and " << penny << " pennies" << endl;

    return 0;
}