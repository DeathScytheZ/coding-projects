#include <iostream>

int main(){
    int N;
    int table[6] = {3,4,7,11,25};
    std :: cout << "Enter a number: ";
    std :: cin >> N;
    for(int z = 0; z < 5; z++){
        std :: cout << table[z] << "\t";
    }
    std :: cout << std :: endl;
    if(table[4] < N)
        table[5] = N;
    else{
        for(int j = 0; j < 6; j++){
            if(table[j] >= N){                
                for(int f = 6; f > j; f--){   
                table[f] = table[f - 1];
                }
                table[j] = N;     
                break;    
            }
        }
    }
    for(int i = 0; i < 6; i++){
        std :: cout << table[i] << "\t";
    }
}