#include <iostream>
using namespace std;

int main(){
    int N, D;
    string Result;
    cout << "enter a 4 digit number: ";
    cin >> N;
    D = 1000;
    while (N > 0){
        if (D != 10){
            switch (N/D){
                case 1: Result += "One "; break;
                case 2: Result += "Two "; break;
                case 3: Result += "Three "; break;
                case 4: Result += "Four "; break;
                case 5: Result += "Five "; break;
                case 6: Result += "Six "; break;
                case 7: Result += "Seven "; break;
                case 8: Result += "Eight "; break;
                case 9: Result += "Nine "; break;
            }
            switch (D){
                case 1000:
                 Result += "Thousand "; break;
                case 100:
                    if (N/D != 0){
                     Result += "Hundred "; break;
                    }
            }
        }else{
            switch(N/D){
                case 1: 
                    switch(N%10){
                        case 0: Result += "and Ten"; break;
                        case 1: Result += "and Eleven"; break;
                        case 2: Result += "and Twelve"; break;
                        case 3: Result += "and Thirteen"; break;
                        case 4: Result += "and Fourteen" ;break;
                        case 5: Result += "and Fifteen"; break;
                        case 6: Result += "and Sixteen"; break;
                        case 7: Result += "and Seventeen"; break;
                        case 8: Result += "and Eighteen"; break;
                        case 9: Result += "and Nineteen"; break;
                    }
                    N = 0;
                    break;
                case 0: Result += "and "; break;
                case 2: Result += "and Twenty "; break;
                case 3: Result += "and Thirty "; break;
                case 4: Result += "and Fourty "; break;
                case 5: Result += "and Fifty "; break;
                case 6: Result += "and Sixty "; break;
                case 7: Result += "and Seventy "; break;
                case 8: Result += "and Eighty "; break;
                case 9: Result += "and Ninety "; break;
            }
        }
        N %= D;
        D /= 10;
    }
    cout << Result;  
}
