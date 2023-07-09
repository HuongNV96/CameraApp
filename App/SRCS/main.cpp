
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <DetectCar.hpp>
#include "LoginPresenter.h"
#include "InitializerExtraModule.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<LoginPresenter>("App", 1, 0, "LoginPresenter");
    qmlRegisterType(QUrl("qrc:/App/QML/CameraView.qml"), "App", 1, 0, "CameraView");
    qmlRegisterType(QUrl("qrc:/App/QML/LoginForm.qml"), "App", 1, 0, "LoginForm");
    initializerExtraModule();

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(QUrl("qrc:/App/QML/Main.qml"));

    return app.exec();
}
