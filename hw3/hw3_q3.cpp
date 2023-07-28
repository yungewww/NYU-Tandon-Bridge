#include <iostream>
#include <cmath>
#include  <iomanip>
using namespace std;



// Infinite Solutions: a = 0 & b = 0 & c = 0
// No solution: a = 0 & b = 0 & c != 0
// let delta = b*b - 4ac
// No real solution: delta < 0
// One real solution: delta = 0 (strictly speaking it should be two equal solutions)
    // x = - b / 2a;
// Two real solutions: delta > 0
    // x1 = (-b + sqrt(delta)) / 2a
    // x2 = (-b - sqrt(delta)) / 2a


int main(){
    double a, b, c, delta, x, x1, x2;

    cout << "Please enter value of a: ";
    cin >> a;
        cout << "Please enter value of b: ";
    cin >> b;
        cout << "Please enter value of c: ";
    cin >> c;

    delta = b * b - 4 * a * c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "This equation has infinite number of solutions.";
    } else if (a == 0 && b == 0 && c != 0){
        cout << "This equation has no solution.";
    } else if (delta < 0){
        cout << "This equation has no real solution.";
    } else if (delta == 0){
        x = (-b) / (2 * a);
        cout << fixed << setprecision(1) << "This equation has a single real solution x=" << x;
    } else if (delta > 0){
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << fixed << setprecision(1) << "This equation has a single real solution: x1 = " << x1 << " and x2 = " << x2;

    }

    return 0;
}
