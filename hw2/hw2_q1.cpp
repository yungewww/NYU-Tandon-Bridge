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

    cout << "Please enter number of coins: \n";
    cout << "# of quarters: ";
    cin >> quarter;
    cout << "# of dimes: ";
    cin >> dime;
    cout << "# of nickels: ";
    cin >> nickel;
    cout << "# of pennies: ";
    cin >> penny;

    sum = 25 * quarter + 10 * dime + 5 * nickel + penny;

    dollar = sum / 100;
    cent = sum % 100;

    cout << "The total is " << dollar << " dollars and " << cent << " cents." << endl;

    return 0;

}