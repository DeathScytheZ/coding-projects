#include <iostream>

int main(){
    bool duplicate = false;
    int f = 0, r = 0, n;
    int ar[50] = {};
    int ar_2[] = {};
    
    std :: cout << "How many elements in the array? ";
    std :: cin >> n;
    for(int i = 0; i < n; i++){
        std :: cout << "Enter the numbers: ";
        std :: cin >> f;
        ar[i] = f;
    }

    for(int i = 0; i < n; i++)
        std :: cout << ar[i] << "\t";
    std :: cout << std :: endl;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(ar[i] == ar[j])
                duplicate = true;
        }
        if(!duplicate){
            ar_2[r] = ar[i];
            r += 1;
        }    
        duplicate = false;
    }
    for(int i = 0; i < r; i++)
        std :: cout << ar_2[i] << "\t";
}
