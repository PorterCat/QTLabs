#ifndef FIGURESLIB_H
#define FIGURESLIB_H

#include <cmath>

namespace Figures
{
    enum Shape {
        square,
        rectangle,
        parallelogram,
        rombus,
        circle,
        triangle,
        sector,
        trapezoid,
    };

double squareArea(double);
double rectangleArea(double, double);
double triangleArea(double, double);
double parallelogramArea(double, double);
double rombusArea(double, double);
double circleArea(double);
double sectorArea(double, int);
double trapezoidArea(double, double, double);

}
#endif // FIGURESLIB_H
