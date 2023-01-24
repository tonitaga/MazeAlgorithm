#ifndef SRC_MODEL_CONSOLEMAZE_CONSOLEMAZE_HPP
#define SRC_MODEL_CONSOLEMAZE_CONSOLEMAZE_HPP

#include <cstdlib>
#include <vector>
#include <algorithm>

#ifndef WIN32_
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "../ConsoleHelper/MazeMatrix/mazematrix.hpp"
#include "../ConsoleHelper/MazeTractor/tractor.hpp"

namespace s21
{
    const int TR_COUNT{1750};

    class ConsoleMaze
    {
    private:
        MazeMatrix maze_;
        MazeTractor tractor_[TR_COUNT];

        const char DEFAULT_MAZEWALL_SYMBOL{'O'};
        const char DEFAULT_MAZENOWALL_SYMBOL{' '};

    public:
        ConsoleMaze(int rows = 11, int cols = 11)
        {
            maze_ = MazeMatrix(rows % 2 == 0 ? rows + 1 : rows, cols % 2 == 0 ? cols + 1 : cols);
            InitializeDefaultStateMazeWalls();
        }

        void GenerateMaze(bool print = true)
        {
            while (!IsValidMaze())
            {
                for (int current = 0; current != TR_COUNT; ++current)
                {
                    auto direction = MoveTractor(tractor_[current]);
                    InitializeMazeAfterTractorMove(direction, tractor_[current]);
                }
            }
            if (print)
                ShowMaze();
        }

        void GenerateMazeInteractive()
        {
            ResetMaze();
            while (!IsValidMaze())
            {
                for (int current = 0; current != TR_COUNT; ++current)
                {
                    auto direction = MoveTractor(tractor_[current]);
                    InitializeMazeAfterTractorMove(direction, tractor_[current]);
                }
                ShowMaze();
                system("clear");
            }
            ShowMaze();
        }

        void SetMazeSize(int height, int width)
        {
            maze_.SetRow(height);
            maze_.SetCol(width);
            ResetMaze();
        }

        void ResetMaze()
        {
            maze_.Clear();
            InitializeDefaultStateMazeWalls();
        }

        int GetMazeWidth() const { return maze_.GetCol(); }
        int GetMazeHeihgt() const { return maze_.GetRow(); }

    private:
        void ShowMaze();
        void InitializeDefaultStateMazeWalls();
        void InitializeMazeAfterTractorMove(Position offset, MazeTractor tractor);
        bool IsValidMaze();
        Position MoveTractor(MazeTractor &tractor);
        Position GetRandomDirection(std::vector<Position> directions);
    };
} // !namespace s21 end

#endif // !SRC_MODEL_CONSOLEMAZE_CONSOLEMAZE_HPP
