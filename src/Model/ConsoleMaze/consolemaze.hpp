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

// #include <chrono>            // ! only for working time test
// using namespace std::chrono; // ! only for working time test

#include "../ConsoleHelper/MazeMatrix/mazematrix.hpp"
#include "../ConsoleHelper/MazeTractor/tractor.hpp"

namespace s21
{
    const int TR_COUNT{750};

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
            // auto start = high_resolution_clock::now();
            while (!IsValidMaze())
            {
                for (int current = 0; current != TR_COUNT; ++current)
                {
                    auto direction = MoveTractor(tractor_[current]);
                    InitializeMazeAfterTractorMove(direction, tractor_[current]);
                }
            }
            // auto stop = high_resolution_clock::now();
            if (print)
                ShowMaze();
            // std::cout << "Maze building time is (seconds) -> " << (duration_cast<milliseconds>(stop - start).count()) / 1000.0 << "\n";
            // std::cout << "Maze building time is (milliseconds) -> " << duration_cast<milliseconds>(stop - start).count() << "\n";
        }

        void GenerateMazeInteractive()
        {
            ResetMaze();
            // auto start = high_resolution_clock::now();
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
            // auto stop = high_resolution_clock::now();
            // std::cout << "Maze was generated successfully!\n";
            // std::cout << "Maze building time is (seconds) -> " << (duration_cast<milliseconds>(stop - start).count()) / 1000.0 << "\n";
            // std::cout << "Maze building time is (milliseconds) -> " << duration_cast<milliseconds>(stop - start).count() << "\n";
            // std::cout << "Tractor count: " << TR_COUNT << "\n";
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
