# Snake-Game (Interactive and Fun Snake Game)
 
## 🐍 Snake in the Maze

### About the Game

Snake in the Maze is a classic console-based snake game built in C++. Inspired by the legendary snake game I played growing up, this version adds a fun twist with randomized obstacles and speed variations to enhance the challenge. Players control the snake to collect food while avoiding collisions with the maze boundaries and their own tail. The goal is to survive as long as possible while growing the snake and achieving the highest score!

### 🎮 How to Play

Use WASD keys to navigate the snake:
W → Move Up
A → Move Left
S → Move Down
D → Move Right
Collect food (F) to increase the snake’s length and score.
Avoid crashing into the walls or the snake's own tail—hitting either ends the game.
Press X to exit the game at any time.

### 🛠️ Tech Stack

Programming Language: C++
Libraries Used:     

 .<iostream> for console input/output
 
 .<conio.h> for handling keyboard input
 
 .<Windows.h> for system functions
 
 .<chrono> and <thread> for managing game speed

### 🎯 Motivation Behind the Game

I built this game as an experimental project during my early C++ learning phase. My goal was to recreate one of my childhood favorites while exploring fundamental game mechanics like handling user input, rendering dynamic graphics in the console, and implementing a basic AI for the snake’s movement. I also wanted to understand how to manage game loops efficiently while keeping the game lightweight and fun to play.

### ⚙️ Technical Challenges

Game Loop Optimization: Ensuring smooth gameplay by implementing an efficient game loop with sleep intervals to manage speed.

Snake Movement Logic: Handling direction changes seamlessly without conflicting inputs, especially when reversing directions.

Collision Detection: Preventing the snake from running into itself or the walls while maintaining a wrap-around effect at the screen edges.

Dynamic Growth Mechanic: Managing the snake’s tail properly so it extends with each food item consumed while updating the display correctly.
