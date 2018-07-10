#include <QApplication>
#include <QJSEngine>
#include "jsfuncs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QJSEngine engine;
    engine.installExtensions(QJSEngine::ConsoleExtension);
    JSFuncs js(&engine);
    engine.globalObject().setProperty("qt", engine.newQObject(&js));
    js.evalFile(":/main.js");

    return a.exec();
}
