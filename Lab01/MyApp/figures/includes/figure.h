#ifndef FIGURE_H
#define FIGURE_H

namespace Figures
{
    class Figure
    {
    public:
        Figure(){}
        virtual double area() const = 0;
    };
}
#endif // FIGURE_H
