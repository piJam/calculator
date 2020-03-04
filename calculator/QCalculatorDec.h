#ifndef _QCALCULATORDEC_H
#define _QCALCULATORDEC_H
#include <QString>
#include <QQueue>
#include <QDebug>
#include <QStack>
#include "ICalculator.h"

class QCalculatorDec : public ICalulator
{
protected:
    QString m_exp;
    QString m_result;

    bool isDigitOrDot(QChar c);
    bool isSymbol(QChar c);
    bool isSign(QChar c);
    bool isNumber(QString s);
    bool isOperator(QString s);
    bool isLeft(QString s);
    bool isRight(QString s);
    int priority(QString s);
    bool match(QQueue<QString>& exp);
    QString calculate(QQueue<QString>& exp);
    QString calculate(QString l, QString op, QString r);
    bool transform(QQueue<QString>& exp, QQueue<QString>& output);
    QQueue<QString> split(const QString& exp);

public:
    QCalculatorDec();
    ~QCalculatorDec();
    bool expression(const QString& exp);
    QString expression();
    QString result();
};

#endif // QCALCULATORDEC_H
