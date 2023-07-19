#include <iostream>
using namespace std;

// 1 day = 1440 minutes
// 1 hour = 60 minutes

int main(){
    int jDay, jHour, jMin, bDay, bHour, bMin;
    int sum;
    int sumDay, sumHour, sumMin;

    cout << "Please enter the number of days John has worked: ";
    cin >> jDay;
    cout << "Please enter the number of hours John has worked: ";
    cin >> jHour;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> jMin;
    cout << "\nPlease enter the number of days Bill has worked: ";
    cin >> bDay;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> bHour;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> bMin;

    sum = 1440 * (jDay + bDay) + 60 * (jHour + bHour) + jMin + bMin;
    
    sumDay = sum / 1440;
    sumHour = (sum - 1440 * sumDay) / 60;
    sumMin = sum - 1440 * sumDay - 60 * sumHour;

    cout << "\nThe total time both of them worked together is: " << sumDay << " days, " << sumHour << " hours and " << sumMin << " minutes." << endl;

    return 0;

}