#ifndef QFIELDSINPUT_H
#define QFIELDSINPUT_H

#include <QWidget>

#include "../include/FiguresLib.h"

using namespace Figures;

class QFieldsInput : public QWidget
{
    Q_OBJECT
public:
    explicit QFieldsInput(QWidget *parent = nullptr);
    void setShapeForm(Shape shape);
    void clear();
private:
    void initializePrivateFieldsMap();
    void updateForm(Shape shape);
    std::map<Shape, std::vector<std::string>> privateFieldsMap;
    QWidget* containerWidget;
signals:
};

#endif // QFIELDSINPUT_H
