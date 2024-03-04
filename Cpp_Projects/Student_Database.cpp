#include <iostream>
#include <string>
int main(){
    float Total;
    struct test{
        float s1;
        float s2;
        float s3;
    };

    struct student{
        std :: string name;
        int id;
        test score;
    };

    student T[2];
    for(int i = 0; i < 2; i++){
        std :: cout << "Enter student " << i + 1 << "'s name: "; 
        std :: cin >> T[i].name;
        std :: cout << "Enter student " << i + 1 << "'s ID: ";
        std :: cin >> T[i].id;
        std :: cout << "Enter student " << i + 1 << "'s test scores: " << std :: endl << "test 1: ";
        std :: cin >> T[i].score.s1;
        std :: cout << "test 2: ";
        std :: cin >> T[i].score.s2;
        std :: cout << "test 3: ";
        std :: cin >> T[i].score.s3;
        std :: cout << std :: endl;
    }

    for(int i = 0; i < 2; i++){
        Total = (T[i].score.s1 + T[i].score.s2 + T[i].score.s3) / 3;
        std :: cout << T[i].name << "'s average test score is : " << Total << std :: endl; 
    }
}