#ifndef SRC_MODEL_CONSOLEHELPER_MAZEMATRIX_HPP
#define SRC_MODEL_CONSOLEHELPER_MAZEMATRIX_HPP

#include <iostream>

namespace s21
{
    class MazeMatrix
    {
    private:
        int rows_;
        int cols_;
        char **matrix_;

    public:
        MazeMatrix() : rows_(11), cols_(11) { CreateMazeMatrix(); }
        MazeMatrix(int rows, int cols) : rows_(rows), cols_(cols)
        {
            if (rows <= 0 || cols <= 0)
                throw std::bad_array_new_length();
            rows = rows % 2 == 0 ? rows + 1 : rows;
            cols = cols % 2 == 0 ? cols + 1 : cols;
            CreateMazeMatrix();
        }
        MazeMatrix(const MazeMatrix &other)
        {
            CreateMazeMatrix();
            CopyMazeMatrix(other);
        }
        MazeMatrix(MazeMatrix &&other)
        {
            rows_ = other.rows_;
            cols_ = other.cols_;
            matrix_ = other.matrix_;
            other.rows_ = other.cols_ = 0;
            other.matrix_ = nullptr;
        }
        ~MazeMatrix() { RemoveMazeMatrix(); }

        MazeMatrix &operator=(const MazeMatrix &other)
        {
            if (this == &other)
                return *this;
            RemoveMazeMatrix();
            rows_ = other.GetRow();
            cols_ = other.GetCol();
            CreateMazeMatrix();
            CopyMazeMatrix(other);
            return *this;
        }

        int GetRow() const { return rows_; }
        int GetCol() const { return cols_; }

        void SetRow(int row);
        void SetCol(int col);

        void Clear()
        {
            for (int row = 0; row != rows_; ++row)
                for (int col = 0; col != cols_; ++col)
                    matrix_[row][col] = char();
        }

        char &operator()(int row, int col)
        {
            if (row < 0 || col < 0 || row >= rows_ || col >= cols_)
                throw std::out_of_range("operator(): Invalid input!");
            return matrix_[row][col];
        }

        char operator()(int row, int col) const
        {
            if (row < 0 || col < 0 || row >= rows_ || col >= cols_)
                throw std::out_of_range("operator() const: Invalid input!");
            return matrix_[row][col];
        }

    private:
        void CreateMazeMatrix();
        void RemoveMazeMatrix();
        void CopyMazeMatrix(const MazeMatrix &other);

        bool memory_allocated_successfully_{true};
    };
}

#endif // !SRC_MODEL_CONSOLEHELPER_MAZEMATRIX_HPP