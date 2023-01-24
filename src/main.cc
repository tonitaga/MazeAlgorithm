#include <iostream>

#include "Model/ConsoleMaze/consolemaze.hpp"

int main()
{
    s21::ConsoleMaze maze(200, 1000);
    system("clear");
    // maze.GenerateMazeInteractive();
    maze.GenerateMaze();
    maze.ResetMaze();
    return 0;
}

