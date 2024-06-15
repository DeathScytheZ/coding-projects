#include <iostream>

int main(){
    int max = -100, index;
    int array[5] = {33, -93, 324, 103, 99};
    for(int i = 0; i < 5; i++){
        std :: cout << array[i] << "\t";
    }
    std :: cout << std :: endl;
    for(int j = 4; j >= 0; j--){
        for(int i = 0; i <= j; i++){
            if(array[i] > max){
                max = array[i];
                index = i;
            }
        }
        array[index] = array[j];
        array[j] = max;
        max = -100;
    }
    for(int i = 0; i < 5; i++){
        std :: cout << array[i] << "\t";
    }
}