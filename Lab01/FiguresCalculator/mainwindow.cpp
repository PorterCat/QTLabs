#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "include/FiguresLib.h"

#include <QLineEdit>
#include <QMessageBox>
#include <QPointer>
#include <qtextedit.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalLayoutWidget_2->layout()->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::map<Shape, std::vector<string>> initializePrivateFieldsMap()
{
    std::map<Shape, std::vector<string>> result;

    result[Shape::square] = {"Длина"};
    result[Shape::rectangle] = {"Длина", "Ширина"};
    result[Shape::parallelogram] = {"Основание", "Высота"};
    result[Shape::rombus] = {"Диагональ 1", "Диагональ 2"};
    result[Shape::circle] = {"Радиус"};
    result[Shape::triangle] = {"Основание", "Высота"};
    result[Shape::sector] = {"Радиус", "Угол (в градусах)"};
    result[Shape::trapezoid] = {"Основание 1", "Основание 2", "Высота"};
    return result;
}

std::map<Shape, std::vector<string>> privateFieldsMap = initializePrivateFieldsMap();

QWidget* setShapeForm(Shape shape)
{
    QWidget* containerWidget = new QWidget();
    QPointer<QVBoxLayout> layout = new QVBoxLayout(containerWidget);

    auto it = privateFieldsMap.find(shape);
    if (it != privateFieldsMap.end())
    {
        const auto& fields = it->second;
        for(const auto& field : fields)
        {
            QPointer<QLabel> label = new QLabel(field.c_str());
            QPointer<QLineEdit> line = new QLineEdit();
            line->setValidator(new QDoubleValidator(1, 9999999, 2, line));
            layout->addWidget(label);
            layout->addWidget(line);
        }
    }
    return containerWidget;
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->verticalLayoutWidget_2->setLayout(NULL);
    switch(index)
    {
    case 0:
        ui->label_3->clear();
        Clear();
        ui->label->clear();
        ui->label->setStyleSheet(NULL);
        break;
    case 1:
        selectedShape = Shape::square;
        ui->label->setStyleSheet("image: url(:/img/img/Square.png);");
        break;
    case 2:
        selectedShape = Shape::rectangle;
        ui->label->setStyleSheet("image: url(:/img/img/Rectangle.png);");
        break;
    case 3:
        selectedShape = Shape::parallelogram;
        ui->label->setStyleSheet("image: url(:/img/img/Parallelogram.png);");
        break;
    case 4:
        selectedShape = Shape::rombus;
        ui->label->setStyleSheet("image: url(:/img/img/Rombus.png);");
        break;
    case 5:
        selectedShape = Shape::triangle;
        ui->label->setStyleSheet("image: url(:/img/img/Triangle.png);");
        break;
    case 6:
        selectedShape = Shape::trapezoid;
        ui->label->setStyleSheet("image: url(:/img/img/Trapezoid.png);");
        break;
    case 7:
        selectedShape = Shape::circle;
        ui->label->setStyleSheet("image: url(:/img/img/Circle.png);");
        break;
    case 8:
        selectedShape = Shape::sector;
        ui->label->setStyleSheet("image: url(:/img/img/Sector.png);");
        break;
    }
    ui->verticalLayoutWidget_2->layout()->addWidget(setShapeForm(selectedShape));
}

void MainWindow::Clear()
{
    QLayoutItem *child;
    while ((child = ui->verticalLayoutWidget_2->layout()->takeAt(0)) != nullptr)
    {
        delete child->widget();
        delete child;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("PorterCat");
    msgBox.exec();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->verticalLayoutWidget_2->children().count() < 2)
    {
        return;
    }

    auto layout = ui->verticalLayoutWidget_2->children().at(1);

    if(layout == nullptr)
    {
        return;
    }

    std::vector<double> values = std::vector<double>();
    QPointer<QObject> item;
    for(int i = 0; i < layout->children().count(); ++i)
    {
        item = layout->children().at(i);
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(item);
        if (lineEdit)
        {
            values.push_back((lineEdit->text().toDouble()));
        }
    }

    double result;
    switch(selectedShape)
    {
    case Figures::square:
        result = squareArea(values[0]);
        break;
    case Figures::rectangle:
        result = rectangleArea(values[0], values[1]);
        break;
    case Figures::triangle:
        result = triangleArea(values[0], values[1]);
        break;
    case Figures::parallelogram:
        result = parallelogramArea(values[0], values[1]);
        break;
    case Figures::rombus:
        result = rombusArea(values[0], values[1]);
        break;
    case Figures::circle:
        result = circleArea(values[0]);
        break;
    case Figures::sector:
        result = sectorArea(values[0], values[1]);
        break;
    case Figures::trapezoid:
        result = trapezoidArea(values[0], values[1], values[2]);
        break;
    }

    ui->label_3->setText(QString::number(result));
}

void MainWindow::on_pushButton_4_clicked()
{
    QApplication::quit();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    Clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_3->clear();

    if(ui->verticalLayoutWidget_2->children().count() < 2)
    {
        return;
    }

    auto layout = ui->verticalLayoutWidget_2->children().at(1);

    if(layout == nullptr)
    {
        return;
    }

    QPointer<QObject> item;
    for(int i = 0; i < layout->children().count(); ++i)
    {
        item = layout->children().at(i);
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(item);
        if (lineEdit)
        {
            lineEdit->clear();
        }
    }
}

void MainWindow::on_action_triggered()
{
    on_pushButton_2_clicked();
}

void MainWindow::on_action_2_triggered()
{
    on_pushButton_3_clicked();
}

void MainWindow::on_action_3_triggered()
{
    on_pushButton_4_clicked();
}

