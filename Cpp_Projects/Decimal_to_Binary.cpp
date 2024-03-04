#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, reminder = 0; 
    string result = "";
    cout << "Enter a number: ";
    cin >> N;
    while(N > 0){
        reminder = N % 2;
        N /= 2;
        result += to_string(reminder);
    }
    reverse(result.begin(), result.end());
    cout << result;
}