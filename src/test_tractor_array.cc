#include <iostream>

#include "Model/ConsoleHelper/MazeTractor/tractor.hpp"

void TestTractorArray();

int main()
{
    TestTractorArray();
    return 0;
}

void TestTractorArray()
{
    s21::MazeTractor tractors[10];
    for (int i = 0; i != 10; ++i)
    {
        tractors[i].AddPosition(s21::Position(2, 4));
    }

    for (int i = 0; i != 10; ++i)
    {
        std::cout << "tractor[" << i << "] -> " << tractors[i].GetPosition().X() << " " << tractors[i].GetPosition().Y() << std::endl;
    }
}