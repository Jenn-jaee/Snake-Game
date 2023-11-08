#include<iostream>
#include<conio.h>
#include<Windows.h>
#include <iostream>
#include <chrono> // for std::chrono functions
#include <thread>

using namespace std;
bool gameOver;
const int width = 25;  // The width coordinate of the map
const int height = 25; // The height coordinate of the map
int x, y; // The head position of the Snake
int food_X, food_Y; // The Food position of the snake
int score; // The game score (optional)
int tail_X[100], tail_Y[100];
int nTail;
enum edirection { STOP = 0, RIGHT, LEFT, UP, DOWN };
edirection dir; // Assigning specific button/key to perform direction.

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2; // The head position would be centered;
    y = height / 2;
    food_X = rand() % width; // assigning random positions for the food with respect to the width
    food_Y = rand() % height; // assigning random positions for the food with respect to the height
    score = 0;
}

void Draw() {
    system("cls"); // A command to clear the console
    for (int i = 0; i < width + 2; i++) // To define the top border (+2 to account for the borders)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << "O"; // Snake head
            else if (i == food_Y && j == food_X)
                cout << "F"; // Food
            else 
            {
                bool print = false;
                for (int K = 0; K < nTail; K++) 
                {
                    if (tail_X[K] == j && tail_Y[K] == i) 
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
    cout << "Score:" << score << endl;
}




void Input()     // Add code for handling user input (e.g., arrow keys or WASD)
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
        case 'x':
            gameOver = true;
            break;
        default:
            break;
        }
       
    }

        
}
/// <summary>
///    y1 y2 y3 
/// x1
/// x2
/// x3
/// </summary>
void Logic()// Add code for updating game logic (e.g., checking collisions, updating score)
{
    int prevX = tail_X[0];
    int prevY = tail_Y[0];
    int prev2X, prev2Y;
    tail_X[0] = x;
    tail_Y[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tail_X[i];
        prev2Y = tail_Y[i];
        tail_X[i] = prevX;
        tail_Y[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
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
    default:
        break;
    }
    if (x >= width || x < 0 || y >= height || y < 0) // boundary check condition
        gameOver = true;
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (x >= height) x = 0; else if (x < 0) x = height - 1;
    for (int i = 0; i < nTail; i++)
        if (tail_X[i] == x && tail_Y[i] == y)
            gameOver = true;
    if (x == food_X && y == food_Y)
    {
        score += 10;
        food_X = rand() % width;
        food_Y = rand() % height;
        nTail++;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        this_thread::sleep_for(std::chrono::milliseconds(100));
        Input();
        Logic();
        Sleep(10);
        //Sleep(); The sleep function
    }

    return 0;
}
