#ifndef _QCALCULATORUI_H_
#define _QCALCULATORUI_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>


class QCalculatorUI : public QWidget
{
private:

    QLineEdit* m_lineEdit;
    QPushButton* m_button[20];

    QCalculatorUI();
    bool construct();

public:

    static QCalculatorUI* NewInstance();
    void show();
    ~QCalculatorUI();
};

#endif // QCALCULATORUI_H
