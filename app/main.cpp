#include <QFile>
#include <QtUiTools>
#include <QApplication>

QWidget * loadUi(QString filename, QWidget * parent=nullptr)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QUiLoader loader;
    return loader.load(&file, parent);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget * w = loadUi(":/mainwindow.ui");
    w->show();

    return a.exec();
}
