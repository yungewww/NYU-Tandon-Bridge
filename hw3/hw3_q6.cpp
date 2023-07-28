#include <iostream>
#include <string>
using namespace std;


// Mo, Tu, We, Th, Fr
    // 8 <= h && h < 18
    // (0 <= h && h < 8 )|| (18 <= h && h < 24)
// Sa, Su

int main(){
    string day, startTime;
    int length, h;
    double cost;
    bool valid = true;


    cout << "Please enter the day of the week (Mo, Tu, We, Th, Fr, Sa, Sun): ";
    cin >> day;
    cout << "Please enter the time the call started (hh:mm in 24 hour notation): ";
    cin >> startTime;
    cout << "Please enter the length of the call in minutes: ";
    cin >> length;


    // convert the startTime string to hour, such that "13:30" would be converted into integer 13
    int h1 = (startTime[0] - '0') * 10;
    int h2 = startTime[1] - '0';
    h = h1 + h2;


    if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr"){
        if (8 <= h && h < 18){
            cost = 0.4 * length;
        } else if ((0 <= h && h < 8 )|| (18 <= h && h < 24)){
            cost = 0.25 * length;
        } else {
            valid = false;
        }
    } else if (day == "Sa" || day == "Su"){
        cost = 0.15 * length;
    } else {
        valid = false;
    }

    if (valid){
        cout << "The cost of the call is " << cost << " dollars.";
    } else{
        cout << "Your input is not valid, please try again.";
    }

    return 0;

}
