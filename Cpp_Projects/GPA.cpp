#include <iostream>
using namespace std;

int main(){
    float Algorithms, Algebra, Analysis, GPA;
    int Credit;
    cout << "enter the Algebra mark: ";
    cin >> Algebra;
    cout << "enter the Analysis mark: ";
    cin >> Analysis;
    cout << "enter the Algorithms mark: ";
    cin >> Algorithms;
    GPA = (Algebra * 2 + Analysis * 4 + Algorithms * 4) / 10;
    if (GPA >= 10){
        cout << "GPA = " << GPA << endl;
        cout << "Credit = 17";    
    }else{
        if(Algebra >= 10)
            Credit += 5;
        if(Analysis >= 10)
            Credit += 6;
        if(Algorithms >= 10)
            Credit += 6;
    cout << "GPA = " << GPA << endl;
    cout << "Credit = " << Credit;
    }
}