#include "../includes/FiguresLib.h"

namespace Figures
{
    Square::Square(double length)
    {
        this->length = length;
    }

    double Square::area() const
    {
        return this->length * this->length;
    }

    double Square::get_length()
    {
        return this->length;
    }
}
