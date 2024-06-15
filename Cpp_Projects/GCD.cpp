#include <iostream>

int main(){
    int a, b, remainder, divisor, dividend;
    std :: cout << "Enter a: ";
    std :: cin >> a;
    std :: cout << "Enter b: ";
    std :: cin >> b;
    if(a > b){
        divisor = b;
        dividend = a;
    }else{ 
        divisor = a;
        dividend = b;
    }
    while(true){
        remainder = dividend % divisor;
        if(remainder != 0){
            dividend = divisor;
            divisor = remainder;
        }else
            break;
    }
    std :: cout << "GCD = " << divisor; 
}