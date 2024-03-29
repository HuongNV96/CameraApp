#include "InitializerEngine.hpp"
#include <opencv2/opencv.hpp>
#include <QDebug>

void initializerEngine() {
    qDebug() << "OpenCV version : " << CV_VERSION;
    qDebug() << "Major version : " << CV_MAJOR_VERSION;
    qDebug() << "Minor version : " << CV_MINOR_VERSION;
    qDebug() << "Subminor version : " << CV_SUBMINOR_VERSION;
}

