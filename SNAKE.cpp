#include <iostream>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, Score;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void input()
{

}
void logic()
{

}
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
    system("clear");
    for (int i = 0; i < width; i++)
    cout << "#";
    cout << endl;

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            cout << "#";
            
            cout << " ";
            if (j = width-1)
            cout << "#";

        }

        cout << endl;
    }


    for (int i = 0; i < width; i++)
    cout << "#";


}

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        
    }

}