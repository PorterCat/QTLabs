#include "include/FiguresLib.h"

double Figures::squareArea(double length) {return length * length; }
double Figures::rectangleArea(double length, double width) {return length * width; }
double Figures::triangleArea(double base, double hight) {return base * hight/2; }
double Figures::parallelogramArea(double base, double hight) {return base * hight; }
double Figures::rombusArea(double diagonal_1, double diagonal_2) {return diagonal_1 * diagonal_2/2; }
double Figures::circleArea(double radius) {return M_PI * radius * radius; }
double Figures::sectorArea(double radius, int angle)
{
    return (double)(angle % 360) / 360 * M_PI * radius * radius;
}

double Figures::trapezoidArea(double base_1, double base_2, double height)
{
    return (base_1 + base_2) * height/2;
}
