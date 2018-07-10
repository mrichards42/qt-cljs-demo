#include <QFile>
#include <QtUiTools>
#include <QApplication>
#include <QScriptEngine>

QWidget * loadUi(QString filename, QWidget * parent=nullptr)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QUiLoader loader;
    return loader.load(&file, parent);
}

QScriptValue evalFile(QScriptEngine * engine, QString filename)
{
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    return engine->evaluate(stream.readAll(), filename);
}

static QScriptValue loadUi(QScriptContext * context, QScriptEngine * engine)
{
    QScriptValue filename = context->argument(0);
    QScriptValue parent = context->argument(1);
    return engine->newQObject(loadUi(filename.toString(), (QWidget *)parent.toQObject()),
                              QScriptEngine::AutoOwnership);
}

static QScriptValue evalFile(QScriptContext * context, QScriptEngine * engine)
{
    QScriptValue filename = context->argument(0);
    return evalFile(engine, filename.toString());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScriptEngine engine;
    engine.globalObject().setProperty("evalFile", engine.newFunction(evalFile, 1));
    engine.globalObject().setProperty("loadUi", engine.newFunction(loadUi, 2));
    evalFile(&engine, ":/main.js");

    return a.exec();
}
