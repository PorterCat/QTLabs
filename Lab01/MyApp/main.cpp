#include <QApplication>
#include <QWidget>
#include <QLocale>
#include <QTranslator>
#include <iostream>

#include "includes/FiguresLib.h"

int main(int argc, char *argv[])
{
    auto figure = Figures::Square(10);

    std::cout << figure.get_length() << std::endl;

    QApplication app(argc, argv);
    QWidget widget;
    widget.show();
    return app.exec();
}
