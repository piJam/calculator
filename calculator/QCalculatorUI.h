#ifndef _QCALCULATORUI_H_
#define _QCALCULATORUI_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>


class QCalculator : public QWidget
{
private:

    QLineEdit* m_lineEdit;
    QPushButton* m_button[20];

    QCalculator();
    bool construct();

public:

    static QCalculator* NewInstance();
    void show();
    ~QCalculator();
};

#endif // QCALCULATORUI_H
