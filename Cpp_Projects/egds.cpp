#include <iostream>

int main(){
    int f;
    std::cout << "Enter f";
    std::cin >> f;
    int g[f];
    for (int i = 0; i < f; i++) {
        g[i] = i + 3;
        std::cout << g[i] << std::endl;
    }

}
