#include <iostream>

int main(){
    int N ;
    bool Prime;
    std :: cout << "How many prime number? ";
    std :: cin >> N;
    std :: cout << "First " << N << " Prime numbers: " << std :: endl;
    for(int i = 2; N > 0; i++){
        Prime = true;
        for(int j = 2; j <= i / 2; j++){
            if(i % j == 0){
                Prime = false;
                break;
            }
        }
        if(Prime){
            std :: cout << i << std :: endl;
            N--;
        }
    }
}

