#ifndef FIGURESLIB_H
#define FIGURESLIB_H

namespace Figures
{
    class Figure
    {
    public:
        Figure(){}
        virtual double area() const = 0;
    };

    class Square : public Figure
    {
    private:
        double length;
    public:
        Square(double length);
        double area() const override;
        double get_length();
    };
}

#endif //FIGURESLIB_H
