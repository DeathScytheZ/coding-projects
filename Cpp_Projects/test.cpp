#include <iostream>

int main(){
    int x = 0, y = 1, z = 2, N, Un = 0;
    do{
    std :: cout << "Enter N: ";
    std :: cin >> N;
    }while(N <= 0);
    switch (N){
    case 1 : Un = x; break;
    case 2 : Un = y; break;
    case 3 : Un = z; break;
    }
    for (int i = 4; i <= N; i++){
        Un = z + x;
        x = y;
        y = z;
        z = Un;
    }
    std :: cout << "Un = " << Un;
}
