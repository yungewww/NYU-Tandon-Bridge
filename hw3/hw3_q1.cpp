#include <iostream>
#include  <iomanip>
using namespace std;

// base price = item1 + item2
    // baseSum
// price after discount with membership:
    // determine which item's price is lower, if else
    // bogohSum
// price after discount without membership:
    // if yes
    // membershipSum = bogohSum * 0.9
// total price: price after discount + tax
    // inputTax
    // taxSum = (1 + inputTax / 100) * inputTax


int main(){
    int item1, item2;
    char memberOrNot;
    double taxRate, basePrice, bogohPrice, discountPrice, totalPrice;

    cout << "Enter price of first item: ";
    cin >> item1;
    cout << "Enter price of second item: ";
    cin >> item2;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> memberOrNot;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    // calculate base price
    basePrice = item1 + item2;
    cout << fixed << setprecision(1) << "Base price: " << basePrice << endl;

    // calculate bogoh price
    if (item1 < item2){
        bogohPrice = item1 / 2 + item2;
    } else if (item1 > item2){
        bogohPrice = item1 + item2 / 2;
    } else {
        bogohPrice = (item1 + item2) / 2;
    }

    // determine member price
    if (memberOrNot == 'y'){
        discountPrice = bogohPrice * 0.9;
    } else if (memberOrNot == 'n'){
        discountPrice = bogohPrice;
    } else {
        cout << "Invalid Input" << endl;
    }

    cout << "Price after discounts: " << discountPrice << endl;

    // price after tax
    totalPrice = discountPrice * (1 + taxRate / 100);
    cout << fixed << setprecision(5) << "Total price: " << totalPrice;

    return 0;
}
