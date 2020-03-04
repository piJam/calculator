#include <QApplication>
#include "QCalculatorUI.h"
#include "QCalculatorDec.h"
#include <QDebug>
#include "QCalculator.h"

int main(int argc, char *argv[])
{
    int ret = -1;
    QApplication a(argc, argv);
    QCalculator* cal = QCalculator::newInstance();

    if( cal != NULL)
    {
         cal->show();

         ret = a.exec();

         delete cal;
    }


    return 0;
}
