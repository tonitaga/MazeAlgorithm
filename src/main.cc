#include <iostream>

#include "Model/ConsoleHelper/MazeMatrix/mazematrix.hpp"
#include "Model/ConsoleHelper/MazeTractor/tractor.hpp"

const char DEFAULT_MAZEWALL_SYMBOL = '@';

using namespace s21;

void InitDefaultStateMazeMatrix(MazeMatrix &mazematrix);
void PrintStateMazeMatrix(const MazeMatrix &mazematrix, bool print_mazematrix = true);
void MazeMatrixTest(int row, int col);
void MazeTractorTest();

int main()
{
    MazeTractorTest();
    return 0;
}

void MazeMatrixTest(int row, int col)
{
    MazeMatrix mazematrix(row, col);
    InitDefaultStateMazeMatrix(mazematrix);
    PrintStateMazeMatrix(mazematrix, false);
}

void MazeTractorTest()
{
    MazeTractor mazetractor;
    {
        auto pos = mazetractor.GetPosition();
        std::cout << "{" << pos.X() << "; " << pos.Y() << "}\n";
    }

    {
        mazetractor.AddPosition({3, 5});
        auto pos = mazetractor.GetPosition();
        std::cout << "{" << pos.X() << "; " << pos.Y() << "}\n";
    }

    {
        mazetractor.AddPosition({3, 5});
        auto pos = mazetractor.GetPosition();
        std::cout << "{" << pos.X() << "; " << pos.Y() << "}\n";
    }
}

void InitDefaultStateMazeMatrix(MazeMatrix &mazematrix)
{
    for (int row = 0; row != mazematrix.GetRow(); ++row)
        for (int col = 0; col != mazematrix.GetCol(); ++col)
            mazematrix(row, col) = DEFAULT_MAZEWALL_SYMBOL;
}

void PrintStateMazeMatrix(const MazeMatrix &mazematrix, bool print_mazematrix)
{
    if (print_mazematrix)
    {
        for (int row = 0; row != mazematrix.GetRow(); ++row)
        {
            for (int col = 0; col != mazematrix.GetCol(); ++col)
            {
                std::cout << mazematrix(row, col);
            }
            std::cout << std::endl;
        }
    }
    std::cout << "rows: " << mazematrix.GetRow() << "\ncols: " << mazematrix.GetCol() << std::endl;
}