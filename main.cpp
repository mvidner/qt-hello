#include <QDebug>
#include <QApplication>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QHBoxLayout>

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
    a.setLayoutDirection(Qt::RightToLeft);

    QGroupBox *groupBox = new QGroupBox("السّلام عليكم");

    QRadioButton *radio1 = new QRadioButton("&Radio button 1");
    QRadioButton *radio2 = new QRadioButton("R&adio button 2");
    QRadioButton *radio3 = new QRadioButton("Ra&dio button 3");
    QPushButton  *button = new QPushButton("التالي");

    QBoxLayout *vbox = new QHBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addStretch(1);
    vbox->addWidget(button);
    groupBox->setLayout(vbox);
    groupBox->show();

    return a.exec();
}
