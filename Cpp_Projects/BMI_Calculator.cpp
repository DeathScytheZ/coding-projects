#include <iostream>
using namespace std;

int main(){
    float weight, height,BMI;
    cout << "enter your weight(Kg): ";
    cin >> weight;
    cout << "enter your height(Cm): ";
    cin >> height;
    height = height / 100;
    BMI = weight / (height * height);
    cout << "your BMI is: " << BMI << endl;
    if (BMI < 18.5)
        cout << "you are Underweight";
    else if(BMI > 25)
        cout << "you are Overweight";
    else
        cout << "your are Normalweight";
}