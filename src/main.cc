#include <iostream>

#include "Model/ConsoleMaze/consolemaze.hpp"

int main()
{
    s21::ConsoleMaze maze(50, 100);
    for (int i = 0; i != 1; ++i)
    {
        maze.GenerateMazeInteractive();
        maze.ResetMaze();
    }
    return 0;
}
