#include <QApplication>
#include "QCalculatorUI.h"

int main(int argc, char *argv[])
{
    int ret = 0;
    QApplication a(argc, argv);
    QWidget* w = QCalculator::NewInstance();


    w->show();


    ret = a.exec();

    delete w;

    return ret;
}
