#include "jsfuncs.h"
#include <QFile>
#include <QtUiTools>

JSFuncs::JSFuncs(QJSEngine * engine) : QObject(engine), m_engine(engine)
{
}

QWidget * JSFuncs::loadUi(QString filename, QWidget * parent)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QUiLoader loader;
    return loader.load(&file, parent);
}

QJSValue JSFuncs::evalFile(QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QJSValue result = m_engine->evaluate(stream.readAll(), filename);
    if (result.isError()) {
        qDebug()
                << "Uncaught exception at line"
                << result.property("lineNumber").toInt()
                << ":" << result.toString()
                << "\n" << result.property("stack").toString();
    }
    return result;
}
