#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "WeatherManager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    WeatherManager weather;
    engine.rootContext()->setContextProperty("weatherManager", &weather);

    engine.load(QUrl("qrc:/WeatherClient/main.qml"));
    return app.exec();
}
