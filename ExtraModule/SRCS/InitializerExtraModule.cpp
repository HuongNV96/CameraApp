#include "InitializerExtraModule.h"

#include <QQmlApplicationEngine>
#include "Hello.h"

void initializerExtraModule() {
    qmlRegisterType<Hello>("ExtraModule", 1, 0, "Hello");
    qmlRegisterType(QUrl("qrc:/ExtraModule/QML/hello.qml"), "ExtraModule", 1, 0, "HelloQml");
}
