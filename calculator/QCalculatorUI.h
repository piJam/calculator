#ifndef _QCALCULATORUI_H_
#define _QCALCULATORUI_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include "ICalculator.h"

class QCalculatorUI : public QWidget
{
    Q_OBJECT

private:
    ICalulator* m_cal;

    QLineEdit* m_lineEdit;
    QPushButton* m_button[20];

    QCalculatorUI();
    bool construct();

private slots:
    void onPush();

public:
    static QCalculatorUI* NewInstance();

    void setCalculator(ICalulator* cal);
    ICalulator*  getCalculator();

    void show();
    ~QCalculatorUI();

};

#endif // QCALCULATORUI_H
