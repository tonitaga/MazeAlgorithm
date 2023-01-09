#include "mazematrix.hpp"

namespace s21
{
    void MazeMatrix::SetRow(int rows)
    {
        if (rows <= 0)
        {
            throw std::out_of_range("Invalid input!");
        }
        MazeMatrix tmp_this(*this);
        RemoveMazeMatrix();
        rows_ = rows;
        cols_ = tmp_this.GetCol();
        CreateMazeMatrix();
        for (int row = 0; row < rows_; row++)
            for (int col = 0; col < cols_; col++)
                if (row < tmp_this.GetRow())
                    matrix_[row][col] = tmp_this(row, col);
    }

    void MazeMatrix::SetCol(int cols)
    {
        if (cols <= 0)
        {
            throw std::out_of_range("setCol: 'cols' element less or equal zero!");
        }
        MazeMatrix tmp_this(*this);
        RemoveMazeMatrix();
        cols_ = cols;
        rows_ = tmp_this.GetRow();
        CreateMazeMatrix();
        for (int row = 0; row < rows_; row++)
            for (int col = 0; col < cols_; col++)
                if (col < tmp_this.GetCol())
                    matrix_[row][col] = tmp_this(row, col);
    }

    void MazeMatrix::CreateMazeMatrix()
    {
        matrix_ = new (std::nothrow) char *[rows_]();
        for (int row = 0; row != rows_; ++row)
            matrix_[row] = new (std::nothrow) char[cols_]();
        memory_allocated_successfully_ = (matrix_ != nullptr);
        if (!memory_allocated_successfully_)
            throw std::bad_alloc();
    }

    void MazeMatrix::RemoveMazeMatrix()
    {
        if (memory_allocated_successfully_)
        {
            for (int row = 0; row != rows_; ++row)
                delete[] matrix_[row];
            delete[] matrix_;
        }
    }

    void MazeMatrix::CopyMazeMatrix(const MazeMatrix &other)
    {
        for (int row = 0; row != rows_; ++row)
            for (int col = 0; col != cols_; ++col)
                matrix_[row][col] = other(row, col);
    }
}