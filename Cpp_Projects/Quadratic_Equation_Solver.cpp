#include <iostream> 
#include <cmath>
using namespace std;

int main(){
    int a,b,c,d;
    float s1,s2;
    cout<< "enter a: ";
    cin>> a;
    cout<< "enter b: ";
    cin>> b;
    cout<< "enter c: ";
    cin>> c;
    d = pow(b,2) - (4*a*c);
    cout<< d << endl;
    if(d > 0){
        s1 = (-b - sqrt(d))/(2*a);
        s2 = (-b + sqrt(d))/(2*a);
        cout<< s1 << endl << s2; 
    }else if(d == 0){
        s1 = -b / (2*a);
        cout<< s1;
    }else
        cout<< "there are no solutions!";
}