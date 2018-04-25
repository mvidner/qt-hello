#include <QApplication>
#include <QTextBrowser>
#include <QUrl>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextBrowser rt;

    rt.setSource(QUrl("test.html"));
    rt.show();
    return a.exec();
}
