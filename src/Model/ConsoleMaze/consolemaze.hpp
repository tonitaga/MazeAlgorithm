#ifndef SRC_MODEL_CONSOLEMAZE_CONSOLEMAZE_HPP
#define SRC_MODEL_CONSOLEMAZE_CONSOLEMAZE_HPP

#include <cstdlib>
#include <vector>
#include <ctime>
#include <windows.h>
#include <algorithm>

#include "../ConsoleHelper/MazeMatrix/mazematrix.hpp"
#include "../ConsoleHelper/MazeTractor/tractor.hpp"

namespace s21
{
    class ConsoleMaze
    {
    private:
        MazeMatrix maze_;
        MazeTractor tractor_;

        const char DEFAULT_MAZEWALL_SYMBOL{'@'};
        const char DEFAULT_MAZENOWALL_SYMBOL{' '};
        const char DEFAULT_MAZETRACTOR_SYMBOL{'*'};

        Position tractor_prev_position_;

    public:
        ConsoleMaze(int rows = 11, int cols = 11)
        {
            maze_ = MazeMatrix(rows % 2 == 0 ? rows + 1 : rows, cols % 2 == 0 ? cols + 1 : cols);
            InitializeDefaultStateMazeWalls();
        }

        void GenerateMaze()
        {
            // while (IsValidMaze()) // ! some troubles with function IsValidMaze (stop flag there)
            while (true)
            {
                auto offset_position = MoveTractor();
                InitializeMazeAfterTractorMove(offset_position);
                system("cls");
                ShowMaze(); // !only for test there
                Sleep(33);
            }
            std::cout << "Maze is ready: lookup (ShowMaze() - function)\n";
        }

        void ShowMaze()
        {
            for (int row = 0; row != maze_.GetRow(); ++row)
            {
                for (int col = 0; col != maze_.GetCol(); ++col)
                {
                    std::cout << maze_(row, col);
                }
                std::cout << std::endl;
            }
        }

    private:
        void InitializeDefaultStateMazeWalls()
        {
            for (int row = 0; row != maze_.GetRow(); ++row)
                for (int col = 0; col != maze_.GetCol(); ++col)
                {
                    maze_(row, col) = DEFAULT_MAZEWALL_SYMBOL;
                }
            maze_(tractor_.GetPosition().Y(), tractor_.GetPosition().X()) = DEFAULT_MAZETRACTOR_SYMBOL;
        }

        void InitializeMazeAfterTractorMove(Position offset) {
            if (maze_(tractor_.GetPosition().Y(), tractor_.GetPosition().X()) == DEFAULT_MAZEWALL_SYMBOL) {
                maze_(tractor_.GetPosition().Y(), tractor_.GetPosition().X()) = DEFAULT_MAZETRACTOR_SYMBOL;
                maze_(tractor_.GetPosition().Y() - offset.Y() / 2, tractor_.GetPosition().X() - offset.X() / 2) = DEFAULT_MAZENOWALL_SYMBOL;
            }
            maze_(tractor_prev_position_.Y(), tractor_prev_position_.X()) = DEFAULT_MAZENOWALL_SYMBOL;
        }

        bool IsValidMaze()
        {
            for (int row = 0; row < maze_.GetRow(); row += 2)
                for (int col = 0; col < maze_.GetCol(); col += 2)
                    if (maze_(row, col) == DEFAULT_MAZEWALL_SYMBOL)
                        return false;
            return true;
        }

        Position MoveTractor()
        {
            std::vector<Position> directions;
            if (tractor_.GetPosition().X() > 0)
                directions.push_back({-2, 0});
            if (tractor_.GetPosition().X() < maze_.GetCol() - 1)
                directions.push_back({2, 0});
            if (tractor_.GetPosition().Y() > 0)
                directions.push_back({0, -2});
            if (tractor_.GetPosition().Y() < maze_.GetRow() - 1)
                directions.push_back({0, 2});

            auto direction = GetRandomDirection(directions);
            tractor_prev_position_ = tractor_.GetPosition();
            tractor_.AddPosition(direction);

            // *lookup for tractor coordinates
            std::cout << "tractor position: {" << tractor_.GetPosition().X() << "; "  << tractor_.GetPosition().Y() << "}\n";
            return direction;
        }

        Position GetRandomDirection(std::vector<Position> directions)
        {
            std::random_shuffle(directions.begin(), directions.end());
            return directions.front();
        }
    };
} // !namespace s21 end

#endif // !SRC_MODEL_CONSOLEMAZE_CONSOLEMAZE_HPP
