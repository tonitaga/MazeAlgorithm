#include "consolemaze.hpp"

namespace s21 {
    void ConsoleMaze::ShowMaze()
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

    void ConsoleMaze::InitializeDefaultStateMazeWalls()
    {
        for (int row = 0; row != maze_.GetRow(); ++row)
            for (int col = 0; col != maze_.GetCol(); ++col)
            {
                maze_(row, col) = DEFAULT_MAZEWALL_SYMBOL;
            }
        maze_(tractor_.GetPosition().Y(), tractor_.GetPosition().X()) = DEFAULT_MAZENOWALL_SYMBOL;
    }

    void ConsoleMaze::InitializeMazeAfterTractorMove(Position offset)
    {
        if (maze_(tractor_.GetPosition().Y(), tractor_.GetPosition().X()) == DEFAULT_MAZEWALL_SYMBOL)
        {
            maze_(tractor_.GetPosition().Y(), tractor_.GetPosition().X()) = DEFAULT_MAZENOWALL_SYMBOL;
            maze_(tractor_.GetPosition().Y() - offset.Y() / 2, tractor_.GetPosition().X() - offset.X() / 2) = DEFAULT_MAZENOWALL_SYMBOL;
        }
    }

    bool ConsoleMaze::IsValidMaze()
    {
        for (int row = 0; row < maze_.GetRow(); row += 2)
            for (int col = 0; col < maze_.GetCol(); col += 2)
                if (maze_(row, col) == DEFAULT_MAZEWALL_SYMBOL)
                    return false;
        return true;
    }

    Position ConsoleMaze::MoveTractor()
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
        tractor_.AddPosition(direction);
        return direction;
    }

    Position ConsoleMaze::GetRandomDirection(std::vector<Position> directions)
    {
        std::random_shuffle(directions.begin(), directions.end());
        return directions.front();
    }
}