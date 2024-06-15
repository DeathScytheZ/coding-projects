#include <iostream>

int main(){
    int N;
    std :: string P;
    std :: cout << "Enter a number: ";
    std :: cin >> N;
    P = " is a prime number";
    for(int i = 2; i < N; i++){
        if(N % i == 0)
            P = " is not a prime number";
    }
    std :: cout << N << P;
}