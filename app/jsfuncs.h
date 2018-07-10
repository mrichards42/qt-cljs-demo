#ifndef JSFUNCS_H
#define JSFUNCS_H

#include <QObject>
#include <QWidget>
#include <QJSEngine>

class JSFuncs : public QObject
{
    Q_OBJECT

public:
    explicit JSFuncs(QJSEngine *engine = nullptr);

    Q_INVOKABLE QWidget * loadUi(QString filename, QWidget * parent=nullptr);
    Q_INVOKABLE QJSValue evalFile(QString filename);

private:
    QJSEngine * m_engine;
};

#endif // JSFUNCS_H
