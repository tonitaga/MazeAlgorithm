#ifndef SRC_MODEL_CONSOLEHELPER_TRACTOR_HPP
#define SRC_MODEL_CONSOLEHELPER_TRACTOR_HPP

namespace s21
{
    struct Position
    {
    private:
        int x_, y_;

    public:
        Position(int x = 0, int y = 0) : x_(x), y_(y) {}
        Position(const Position &other) : x_(other.x_), y_(other.y_) {}
        ~Position() = default;

        int X() const { return x_; }
        int Y() const { return y_; }

        void SetPosition(const Position &position)
        {
            x_ = position.X();
            y_ = position.Y();
        }

        Position &operator+=(const Position &other) {
            x_ += other.X();
            y_ += other.Y();
            return *this;
        }
    };

    class MazeTractor
    {
    private:
        Position position_;

    public:
        MazeTractor() = default;
        MazeTractor(const MazeTractor &other) : position_(other.position_) {}

        ~MazeTractor() = default;

        MazeTractor &operator=(const MazeTractor &other)
        {
            position_ = other.position_;
            return *this;
        }

        const Position &GetPosition() { return position_; }

        void AddPosition(const Position &other)
        {
            position_ += other;
        }
    };

}

#endif // !SRC_MODEL_CONSOLEHELPER_TRACTOR_HPP
