#include <iostream>

#include "Model/ConsoleMaze/consolemaze.hpp"

int main()
{
    s21::ConsoleMaze maze(51, 145);
    maze.GenerateMaze();
    maze.RegenerateMaze();
    return 0;
}
