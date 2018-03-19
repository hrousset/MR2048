#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>



#include "listevaleurs.h"
//#include "case.h"
//#include "tableau.h"

int main(int argc, char *argv[])
{
//#if defined(Q_OS_WIN)
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

    QGuiApplication app(argc, argv);
    listeValeurs uneValeur;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("listeNombres", &uneValeur);
    engine.rootContext()->setContextProperty("score", &uneValeur);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //if (engine.rootObjects().isEmpty())
        //return -1;

    return app.exec();
}
