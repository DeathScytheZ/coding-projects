#include <cderr.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>


bool gameOver = false;
const int height = 20;
const int width = 50;
int X, Y, fruit_X, fruit_Y, score, prev_X, prev_Y;
int tail_X[100], tail_Y[100], tail_count;
enum directions{stop, up, down, left, right};
directions dir = stop;



void SetUp(){
    score = 0;
    tail_count = 0;
    X = width / 2;
    Y = height / 2;
    tail_X[0] = X;
    tail_Y[0] = Y;
    srand(time(0));
    fruit_X = rand() % (width - 2) + 1;
    fruit_Y = rand() % (height - 2) + 1;
}

void Draw(){
    system("cls");

    for(int i = 0; i < width; i++){
        std::cout << "#";
    }

    std::cout << std::endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j == 0 || j == width - 1)
                std::cout << "#";
            else if(j == tail_Y[i] && i == tail_X[j]) 
                std::cout << "O";
            else if(i == fruit_Y && j == fruit_X){
                std::cout << "X";
            }
            else
                std::cout << " "; 
        }
        std::cout << std::endl;
    }
    
    for(int i = 0; i < width; i++){
        std::cout << "#";
    }
    std::cout << std::endl;
}

void Input(){
    if(_kbhit()){
        switch (_getch()) {
            case 'w': dir = up; break;
            case 's': dir = down; break;
            case 'd': dir = right; break;
            case 'a': dir = left; break;
        }
    }
}

void Logic(){
    for(int i = tail_count - 1; i > 0 ; i--){
        tail_X[i] = tail_X[i - 1];
        tail_Y[i] = tail_Y[i - 1];
    }
    switch (dir) {
        case up : Y--; break;
        case down: Y++; break;
        case right: X++; break;
        case left: X--; break;
    }

    if(X == fruit_X && Y == fruit_Y){
        tail_count++;
        score += 10;
        srand(time(0));
        fruit_X = rand() % (width - 2) + 1;
        fruit_Y = rand() % (height - 2) + 1;
    }
    if(Y == -1 || Y == height)
        gameOver = true;
    else if(X == 0)
        X = width - 2;
    else if( X == width - 1)
        X = 1;
}

int main(){
    SetUp();
    while(!gameOver){
        Draw();
        std::cout << "Score: " << score;
        Input();
        Logic();
        Sleep(50);
    }
    std::cout << std::endl << "Game Over! " << std::endl;
    system("Pause");
}

