#include <QDebug>
#include <QApplication>
#include <QPushButton>

void myMessageOutput(QtMsgType type, const char * msg)
{
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
        abort();
    }
}

int main(int argc, char *argv[])
{
    qInstallMsgHandler(myMessageOutput);

    QApplication a(argc, argv);
    QPushButton button("Hello, World!");
    qDebug()    << "Button D" << &button;
    //qWarning()  << "Button W" << button;
    //qCritical() << "Button C" << button;
    button.show();
    return a.exec();
}
