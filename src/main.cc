#include <iostream>

#include "Model/ConsoleMaze/consolemaze.hpp"

using namespace s21;

int main()
{
    ConsoleMaze maze(11, 11);
    maze.GenerateMaze();
    return 0;
}
