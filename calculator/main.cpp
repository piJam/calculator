#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    int ret = 0;
    QApplication a(argc, argv);
    QWidget* w = new QWidget(NULL, Qt::WindowCloseButtonHint);

    QLineEdit* le = new QLineEdit(w);

    le->move(10, 10);
    le->resize(240, 30);

    QPushButton* button[20] = {0};

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            button[i*5 + j] = new QPushButton(w);
            button[i*5 + j] -> resize(40, 40);
            button[i*5 + j] -> move( 10 + (10 + 40) * j, 50 + (10 + 40) * i);
        }
    }



    w ->show();

    ret = a.exec();

    delete w;

    return ret;
}
