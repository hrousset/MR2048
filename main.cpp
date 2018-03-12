#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <QObject>


#include "case.h"
#include "tableau.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    Case uneValeur;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("valeur_index", &uneValeur);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
