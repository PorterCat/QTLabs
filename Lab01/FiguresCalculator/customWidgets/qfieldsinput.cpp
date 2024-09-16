#include "qfieldsinput.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <qpointer.h>

QFieldsInput::QFieldsInput(QWidget *parent)
    : QWidget{parent}
{
    initializePrivateFieldsMap();
}

void QFieldsInput::initializePrivateFieldsMap()
{
    privateFieldsMap = {
        {Shape::square, {"Длина"}},
        {Shape::rectangle, {"Длина", "Ширина"}},
        {Shape::parallelogram, {"Длина", "Ширина", "Высота"}},
        {Shape::circle, {"Радиус"}},
        {Shape::triangle, {"Основание", "Высота"}},
        {Shape::sector, {"Радиус", "Угол (в градусах)"}},
        {Shape::trapezoid, {"Основание 1", "Основание 2", "Высота"}}
    };
}

void QFieldsInput::setShapeForm(Shape shape)
{
    clear();
    containerWidget = new QWidget();
    QPointer<QVBoxLayout> layout = new QVBoxLayout(containerWidget);

    auto it = privateFieldsMap.find(shape);
    if (it != privateFieldsMap.end())
    {
        const auto& fields = it->second;
        for(const auto& field : fields)
        {
            QPointer<QLabel> label = new QLabel(field.c_str());
            QPointer<QLineEdit> line = new QLineEdit();
            layout->addWidget(label);
            layout->addWidget(line);
        }
    }
}

void QFieldsInput::clear()
{

}
