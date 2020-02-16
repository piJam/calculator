#include "QCalculatorUI.h"

QCalculatorUI::QCalculatorUI(): QWidget(NULL, Qt::WindowCloseButtonHint)
{

}

QCalculatorUI::~QCalculatorUI()
{

}

bool QCalculatorUI::construct()
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
        m_lineEdit->setAlignment(Qt::AlignRight);
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

               QObject::connect(m_button[i*5 + j], SIGNAL(clicked(bool)), this, SLOT(onPush()));
           }
           else
           {
                ret = false;
           }

        }
    }

    return ret;

}

QCalculatorUI* QCalculatorUI::NewInstance()
{
    QCalculatorUI* ret = new QCalculatorUI();

    if( ret == NULL || !ret->construct() )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}

void QCalculatorUI::show()
{
    QWidget::show();
    this->setFixedSize(width(), height());
}

void QCalculatorUI::onPush()
{
    QPushButton* qbtn = dynamic_cast< QPushButton* > (QObject::sender());

    QString clickTest = qbtn->text();

    if( clickTest == "<-")
    {
        if( clickTest.length() > 0 )
        {
            QString test = m_lineEdit->text();
            test.remove(test.length()-1, 1);
            m_lineEdit->setText( test );
        }
    }
    else if( clickTest == "C")
    {
        m_lineEdit->setText("");
    }
    else if( clickTest == "=" )
    {

    }
    else
    {
        m_lineEdit->setText( m_lineEdit->text() + clickTest );
    }

}
