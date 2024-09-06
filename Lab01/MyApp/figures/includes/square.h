#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"
namespace Figures
{
    class Square : public Figure
    {
    private:
        double _length;
    public:
        Square(double length);
        double area() const override;
        double get_length();
    };
}
#endif // SQUARE_H
