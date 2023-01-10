#include <iostream>
#include <windows.h>

#include "Model/ConsoleMaze/consolemaze.hpp"

int main()
{
    s21::ConsoleMaze maze(25, 55);
    for (int i = 0; i != 10; ++i) {
        maze.GenerateMaze();
        maze.ResetMaze();
        Sleep(1500);
    }
    return 0;
}
