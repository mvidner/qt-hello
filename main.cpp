// #include <QDebug>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button("Hello, World!");
    qDebug()    << "Button D" << &button;
    //qWarning()  << "Button W" << button;
    //qCritical() << "Button C" << button;
    button.show();
    return a.exec();
}
