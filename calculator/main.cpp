#include <QApplication>
#include "QCalculatorUI.h"
#include "QCalculatorDec.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    int ret = -1;
    QApplication a(argc, argv);
    QCalculatorUI* cal = QCalculatorUI::NewInstance();

    if( cal != NULL)
    {
         cal->show();

         ret = a.exec();

         delete cal;
    }

   /* QCalculatorDec c;

    c.expression( " 5 - 8 * ( 5 - 6 ) " );
    qDebug() << c.result();
    */
    return 0;
}
