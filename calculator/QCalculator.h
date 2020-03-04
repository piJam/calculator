#ifndef QCALCULATOR_H
#define QCALCULATOR_H
#include "QCalculatorUI.h"
#include "QCalculatorDec.h"

class QCalculator
{
private:
    QCalculatorUI* m_ui;
    QCalculatorDec m_cal;

    QCalculator();
    bool construct();

public:
    static QCalculator* newInstance();
    void show();
    ~QCalculator();
};

#endif // QCALCULATOR_H
