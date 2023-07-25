
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "LoginPresenter.h"
#include "CameraPlayerPresenter.hpp"
#include "InitializerExtraModule.h"
#include "InitializerEngine.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<LoginPresenter>("App", 1, 0, "LoginPresenter");
    qmlRegisterType<CameraPlayerPresenter>("App", 1, 0, "CameraPlayerPresenter");

    qmlRegisterType(QUrl("qrc:/App/QML/CameraView.qml"), "App", 1, 0, "CameraView");
    qmlRegisterType(QUrl("qrc:/App/QML/LoginForm.qml"), "App", 1, 0, "LoginForm");
    qmlRegisterType(QUrl("qrc:/App/QML/CameraPlayer.qml"), "App", 1, 0, "CameraPlayer");

    initializerExtraModule();
    initializerEngine();

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(QUrl("qrc:/App/QML/Main.qml"));

    return app.exec();
}
