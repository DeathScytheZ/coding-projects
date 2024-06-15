#include <iostream>

void print_array(int parray[]){
    for (int i = 0; i < 5; i++) {
        std::cout << parray[i] << std::endl;
    }
}

int main(){
    int array[] = {12, 43, 23, 43, 23};
    print_array(array);   
    
    
}
