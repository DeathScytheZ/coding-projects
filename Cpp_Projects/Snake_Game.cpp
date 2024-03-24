#include <conio.h>
#include <iostream>
#include <windows.h>


bool gameOver = false;
const int height = 20;
const int width = 50;
int X, Y, fruit_X, fruit_Y;
enum directions{stop, up, down, left, right};
directions dir;



void SetUp(){
    dir = stop;
    if(_kbhit()){
        switch (_getch()) {
            case 'w': dir = up; break;
            case 's': dir = down; break;
            case 'd': dir = right; break;
            case 'a': dir = left; break;
        }
    }
}

void Draw(){
    system("CLS");

    for(int i =0; i < width; i++){
        std::cout << "#";
    }

    std::cout << std::endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j == 0 || j == width - 1 )
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    
    for(int i =0; i < width; i++){
        std::cout << "#";
    }
    
}

void Input(){

}

void Logic(){

}

int main(){
    while(!gameOver){
        Draw();
        Input();
        Logic();
        Sleep(500);
}