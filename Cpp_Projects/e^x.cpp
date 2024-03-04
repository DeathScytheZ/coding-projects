#include <iostream>

int main(){
    int n, f;
    float x, p, e;
    std :: cout << "Enter X: ";
    std :: cin >> x;
    std :: cout << "Enter N: ";
    std :: cin >> n; 
    e = 1;
    f = 1;
    p = 1;
    for(int i = 1; i <= n; i++){
        f *= i;
        p *= x;
        e += p / f;
    }
    std :: cout << "f = " << f << std :: endl;
    std :: cout << "p = " << p << std :: endl;
    std :: cout << "s = " << e << std :: endl;
}