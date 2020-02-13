#include "QCalculatorUI.h"

QCalculator::QCalculator(): QWidget(NULL, Qt::WindowCloseButtonHint)
{

}

QCalculator::~QCalculator()
{

}

bool QCalculator::construct()
{
    bool ret = true;

    const char* btnText[20] =
       {
           "7", "8", "9", "+", "(",
           "4", "5", "6", "-", ")",
           "1", "2", "3", "*", "<-",
           "0", ".", "=", "/", "C",
       };

    m_lineEdit = new QLineEdit(this);

    if( m_lineEdit != NULL )
    {
        m_lineEdit->move(10, 10);
        m_lineEdit->resize(240, 30);
        m_lineEdit->setReadOnly(true);
    }
    else
    {
        ret = false;
    }

    for(int i=0; i<4 && ret; i++)
    {
        for(int j=0; j<5 && ret; j++)
        {
            m_button[i*5 + j] = new QPushButton(this);

           if( m_button[i*5 + j] != NULL )
           {
               m_button[i*5 + j] -> resize(40, 40);
               m_button[i*5 + j] -> move( 10 + (10 + 40) * j, 50 + (10 + 40) * i);
               m_button[i*5 + j] -> setText(btnText[i*5 + j]);
           }
           else
           {
                ret = false;
           }

        }
    }

    return ret;

}

QCalculator* QCalculator::NewInstance()
{
    QCalculator* ret = new QCalculator();

    if( ret == NULL || !ret->construct() )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}

void QCalculator::show()
{
    QWidget::show();
    this->setFixedSize(width(), height());
}
