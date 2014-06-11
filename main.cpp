#include <QDebug>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QMessageLogContext>

// http://qt-project.org/doc/qt-5.0/qtcore/qtglobal.html#qInstallMessageHandler
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        abort();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);

    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.addText("Hello, world!");

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
