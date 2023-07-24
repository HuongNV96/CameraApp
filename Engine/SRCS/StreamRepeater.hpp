#ifndef STREAMREPEATER_H
#define STREAMREPEATER_H
#include <QObject>
#include <QProcess>
#include <atomic>
#include <thread>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <QDebug>

using namespace cv;
using namespace std;

class StreamRepeater : public QObject
{
    Q_OBJECT
public:
    StreamRepeater(QString input, QString output);
    ~StreamRepeater();
private:
    QString mUrlInput;
    QString mUrlOutput;
    std::unique_ptr<QProcess> mRepublic;
    std::unique_ptr<VideoCapture> mCap;
    void run();
    std::atomic_bool mExit;
    std::thread mLoop{[this](){this->run();}};
};

#endif // STREAMREPEATER_H
