#include <iostream>

int main(){
    int N;
    float x = 2, y = 3, Un = 0;
    do{
        std :: cout << "Enter N: ";
        std :: cin >> N;
    }while(N <= 0);
    switch(N){
        case 1 : Un = x; break;
        case 2 : Un = y; break;
    }
    for(int i = 3; i <= N; i++){
        Un = (float(2) / float(3)) * y - (float(1) / float(4)) * x;
        x = y;
        y = Un;
    }
    std :: cout << "Un = " << Un;
}