#include "includes/square.h"

namespace Figures
{
    Square::Square(double length)
    {
        _length = length;
    }

    double Square::area() const
    {
        return _length * _length;
    }

    double Square::get_length()
    {
        return _length;
    }
}
