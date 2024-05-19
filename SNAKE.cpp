#include <iostream>
#include <conio.h>
#include <thread> // for std::this_thread::sleep_for
#include <chrono> // for std::chrono::milliseconds
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, Score;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
int tailX[100], tailY[100];
int ntail;

void setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

    Score = 0;

}
void draw()
{
    // Clear the screen
    SetConsoleCursorPosition
    (GetStdHandle(STD_OUTPUT_HANDLE), {0,0});

    // Draw the game board
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "0";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < ntail; k++)
                {
                    
                    if (tailX[k] == j &&  tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                    
                }

             if (!print)
              cout << " ";
            }
                
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "SCORE" << Score << endl;

}

void input()
{
    
       if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'q':
            gameOver = true;
            break;  
        }
    }  
    
}
void logic()
{
    int pX = tailX[0];
    int pY = tailY[0];
    int p2X, p2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < ntail; i++)
    {
        p2X = tailX[i];
        p2Y = tailY[i];
        tailX[i] = pX;
        tailY[i] = pY;
        pX = p2X;
        pY = p2Y;
    }
    switch (dir)

   {
        case LEFT:
           x--;
           break;
        case RIGHT:
           x++;
           break;
        case UP:
           y--;
           break;
        case DOWN:
           y++;
           break;
        case STOP:
           break;
   }

   if (x > width || x < 0 || y > height || y < 0)
   gameOver = true;
   
   for (int i = 0; i < ntail; i++)
   if (tailX[i] == x && tailY[i] == y)
   gameOver = true;
   if (x == fruitX && y == fruitY)
   {
        Score +=10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        ntail++;
   }
}

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        logic();
        input();

        std::this_thread::sleep_for(std::chrono::milliseconds(90));
        
    }

}