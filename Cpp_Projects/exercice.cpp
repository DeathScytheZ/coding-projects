#include <iostream>

int main(){
    char A[5][5] = {};
    int n, m, nv = 0;
    char e;
    bool ex = false;
    std :: cout << "Enter n and m: ";
    std :: cin >> n >> m;
    std :: cout << "Enter e: ";
    std :: cin >> e;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std :: cout << "enter the values: ";
            std :: cin >> A[i][j];
            if(A[i][j] == e){
                ex = true;
            }
            switch(A[i][j]){
                case 'a': nv++; break;
                case 'e': nv++; break;
                case 'h': nv++; break;
                case 'i': nv++; break;
                case 'o': nv++; break;
                case 'u': nv++; break;
                case 'y': nv++; break;
            }
        }
    }
    if(ex)
        std :: cout << "The value Exists";
    else
        std :: cout << "The value Does't Exist";
    std :: cout << std :: endl;
    std :: cout << nv;
}