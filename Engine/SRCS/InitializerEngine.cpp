#include "InitializerEngine.hpp"
#include <opencv2/opencv.hpp>
#include <QDebug>
#include "RepeaterManager.hpp"

void initializerEngine() {
    qDebug() << "OpenCV version : " << CV_VERSION;
    qDebug() << "Major version : " << CV_MAJOR_VERSION;
    qDebug() << "Minor version : " << CV_MINOR_VERSION;
    qDebug() << "Subminor version : " << CV_SUBMINOR_VERSION;
    RepeaterManager & manager = SingletonTemplate<RepeaterManager>::getInstance();
    manager.echo();
}

