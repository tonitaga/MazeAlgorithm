#ifndef SRC_MODEL_CONSOLEHELPER_MAZEMATRIX_HPP
#define SRC_MODEL_CONSOLEHELPER_MAZEMATRIX_HPP

namespace s21
{
    class MazeMatrix
    {
    private:
        int rows_;
        int cols_;
        char **matrix_;

    public:
        MazeMatrix() : rows_(11), cols_(11) {}
        MazeMatrix(int rows, int cols) : rows_(rows), cols_(cols) {}
        MazeMatrix(const MazeMatrix &other) {}
        MazeMatrix(MazeMatrix &&other) {}
        ~MazeMatrix() {}
    };
}

#endif // !SRC_MODEL_CONSOLEHELPER_MAZEMATRIX_HPP