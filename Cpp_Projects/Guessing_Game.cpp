#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    int num, guessed_num;
    srand(time(0));
    num = (rand() % 10) + 1 ;
    cout << num << endl;
    cout << "Guess a number between 1 and 10: ";
    cin >> guessed_num;
    (guessed_num == num) ? cout << "you got it right!" : cout << "you got it wrong!";
}
