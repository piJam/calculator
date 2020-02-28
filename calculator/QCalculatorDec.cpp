#include "QCalculatorDec.h"
#include <QDebug>

QCalculatorDec::QCalculatorDec()
{
    m_exp = "";
    m_result = "";

    QQueue<QString> r = split("+9.11 + ( -3 - 1 ) * -5");

    for(int i=0; i<r.length(); i++)
       {
           qDebug() << r[i];
       }

       QQueue<QString> output;

       transform(r, output);

       for(int i=0; i<output.length(); i++)
       {
           qDebug() << output[i];
       }
}

QCalculatorDec::~QCalculatorDec()
{

}

bool QCalculatorDec::isDigitOrDot(QChar c)
{
    return  ( '0' <= c ) && ( c <= '9' ) || (c =='.');
}

bool QCalculatorDec::isSymbol(QChar c)
{
    return isOperator(c) || (c == '(') || (c == ')');
}

bool QCalculatorDec::isSign(QChar c)
{
    return (c == '+') || (c == '-');
}

bool QCalculatorDec::isNumber(QString s)
{
    bool ret = false;

    s.toDouble(&ret);

    return ret;
}

bool QCalculatorDec::isOperator(QString s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool QCalculatorDec::isLeft(QString s)
{
    return (s == "(");
}

bool QCalculatorDec::isRight(QString s)
{
    return (s == ")");
}

int QCalculatorDec::priority(QString s)
{
    int ret = 0;

    if( (s == "+") || (s == "-") )
    {
        ret = 1;
    }

    if( (s == "*") || (s == "/") )
    {
        ret = 2;
    }

    return ret;
}

bool QCalculatorDec::expression(const QString& exp)
{
    bool ret = false;

    return ret;
}

QString QCalculatorDec::result()
{
    return m_result;
}

QQueue<QString> QCalculatorDec::split(const QString& exp)
{
    QQueue<QString> ret;
    QString num = "";
    QString pre = "";

    for( int i=0; i<exp.length(); i++)
    {
        if( isDigitOrDot(exp[i]) )
        {
            num += exp[i];
            pre = exp[i];
        }
        else if( isSymbol(exp[i]) )
        {
            if( !num.isEmpty() )
            {
                ret.enqueue(num);

                num.clear();
            }

            if( isSign(exp[i]) && ((pre == "") || (pre == "(") || isOperator(pre)) )
            {
                num += exp[i];
            }
            else
            {
                ret.enqueue(exp[i]);
            }

            pre = exp[i];
        }
    }

    if( !num.isEmpty() )
    {
        ret.enqueue(num);
    }

    return ret;
}

bool QCalculatorDec::match(QQueue<QString>& exp)
{
    bool ret = true;
    QStack<QString> stack;

    for(int i=0; i<exp.length(); i++)
    {
        if( isLeft(exp[i]) )
        {
            stack.push(exp[i]);
        }
        else if( isRight(exp[i]) )
        {
            if( isLeft(stack.top()) )
            {
                stack.pop();
            }
            else
            {
                ret = false;
                break;
            }
        }
    }

    return ret && stack.isEmpty();
}

bool QCalculatorDec::transform(QQueue<QString>& exp, QQueue<QString>& output)
{
    bool ret = match(exp);

    QStack<QString> stack;
    output.clear();

    while( ret && !exp.isEmpty())
    {
        QString e  = exp.dequeue();

        if( isNumber(e))
        {
            output.enqueue(e);
        }
        else if( isOperator(e) )
        {
            while ( !stack.isEmpty() && (priority(e) <= priority(stack.top())) )
            {
                output.enqueue(stack.pop());
            }

            stack.push(e);
        }
        else if( isLeft(e) )
        {
            stack.push(e);
        }
        else if( isRight(e) )
        {
            while(!stack.isEmpty() && !isLeft(stack.top()) )
            {
                output.enqueue(stack.pop());
            }

            if( !stack.isEmpty() )
            {
                stack.pop();
            }
        }
        else
        {
            ret = false;
        }
    }

    while ( !stack.isEmpty())
    {
        output.enqueue(stack.pop());
    }

    if( !ret )
    {
        output.clear();
    }

    return ret;
}
