#include <iostream>
#include <iomanip>

int main(){
    int i, j, h, z;
    std :: cout << "Enter The Height Of The Triangle: ";
    std :: cin >> h;
    z = h + 1;
    for(i = 1; i <= h; i++){
        std :: cout << std :: setw(z);
        z--;
        for(j = 1; j <= i; j++){
            std :: cout << "* " ;
        }
        std :: cout << std :: endl;
    }
    z = 2;
    for(i = h; i >= 1; i--){
        std :: cout << std :: setw(z);
        z ++;
        for (j = i; j >= 1; j--){
            std :: cout << "* ";
        }
        std :: cout << std :: endl;    
        }
}