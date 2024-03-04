#include <iostream>

int main(){
    int h, i, j;
    char s;
    std :: cout << "Enter The Height: ";
    std :: cin >> h;
    std :: cout << "Enter The Symbol: ";
    std :: cin >> s;
    for(i = 1; i <= h; i++){
        for(j = 1; j <= i; j++){
            std :: cout << s << "  "; 
        }
        std :: cout << std :: endl;
    }
    for(i = 1; i <= h; i++){
        for(j = h; j >= i; j--){
            std :: cout << s << "  ";
        }
        std :: cout << std :: endl;
    }
}