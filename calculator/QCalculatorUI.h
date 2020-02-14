#ifndef _QCALCULATORUI_H_
#define _QCALCULATORUI_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>


class QCalculatorUI : public QWidget
{
    Q_OBJECT

private:

    QLineEdit* m_lineEdit;
    QPushButton* m_button[20];

    QCalculatorUI();
    bool construct();

private slots:
    void onPush();

public:
    static QCalculatorUI* NewInstance();
    void show();
    ~QCalculatorUI();

};

#endif // QCALCULATORUI_H
