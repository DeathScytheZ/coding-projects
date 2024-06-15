#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <winnt.h>



enum direction{UP, DOWN, LEFT, RIGHT, STOP};

const int width = 20;
const int height = 10;
int snakeY;
int snakeX;
int foodY;
int foodX;
bool gameOver = false;
direction dir;

void drawBoard(const int height, const int width){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == height - 1 || j == 0 || j == width - 1 || (i == foodY && j == foodX))
                std::cout << "#";
            else if(i == snakeY && j == snakeX)
                std::cout << "O";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}


void generateFood(){
    srand(time(NULL));
    foodY = 2 + rand() % (height - 3);
    foodX = 2 + rand() % (width - 3);
    if(foodY == snakeY && foodX == snakeX)
        generateFood();
}


void setUp(){
    dir = STOP;
    snakeY = 5;
    snakeX = 10;
    generateFood();
    drawBoard(height, width);
}


void controls(){
    if(_kbhit()){
        char c = _getch();
        switch(c){
            case 'w':
                dir = UP; break;
            case 's':
                dir = DOWN; break;
            case 'a':
                dir = LEFT; break;
            case 'd':
                dir = RIGHT; break;
        }
    }
}



void logic(){
    switch(dir){
        case UP:
            snakeY--; break;
        case DOWN:
            snakeY++; break;
        case LEFT:
            snakeX--; break;
        case RIGHT:
            snakeX++; break;
        case STOP:
            break;
    }
    if(snakeY == foodY && snakeX == foodX)
        generateFood();
    if(snakeY == 0 || snakeY == height - 1 || snakeX == 0 || snakeX == width -1)
        gameOver = true;
}


int main() {
    setUp();
    controls();
    logic();
    while(!gameOver){
        system("cls");
        drawBoard(height, width);
        controls();
        logic();
        Sleep(150);
        std::cout << foodY << " " << foodX;
    }
}

