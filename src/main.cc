#include <iostream>

#include "Model/ConsoleMaze/consolemaze.hpp"

int main()
{
    s21::ConsoleMaze maze(30, 50);
    system("clear");
    maze.GenerateMazeInteractive();
    maze.ResetMaze();
    return 0;
}
