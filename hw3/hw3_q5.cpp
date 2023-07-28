#include <iostream>
#include <string>
using namespace std;



int main(){
    double weightP, heightI, weight, height, bmi;
    string status = "default";

    cout << "Please enter weight (in pounds): ";
    cin >> weightP;
    cout << "Please enter height (in inches): ";
    cin >> heightI;

    weight = weightP * 0.453592;
    height = heightI * 0.0254;

    bmi = weight / height / height;

    if (bmi < 18.5){
        status = "Underweight";
    } else if (18.5 <= bmi && bmi < 25){
        status = "Normal";
    } else if (25 <= bmi && bmi < 30){
        status = "Overweight";
    } else {
        status = "Obese";
    }

    cout << "The weight status is: " << status;

    return 0;

}
