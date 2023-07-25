#ifndef CAMERAPLAYERPRESENTER_H
#define CAMERAPLAYERPRESENTER_H

#include <QObject>
#include <QMediaPlayer>
#include <QVideoSink>

class CameraPlayerPresenter : public QObject
{
    Q_OBJECT
public:
    CameraPlayerPresenter();
    ~CameraPlayerPresenter();
    Q_INVOKABLE void setVideoSink(QVideoSink * videoSink);
    Q_INVOKABLE void init(QString url);
private :
    QMediaPlayer mPlayer;
    QVideoSink * mVideoSink;
    Q_SLOT void onVideoFrameChanged(const QVideoFrame &frame);
};

#endif // CAMERAPLAYERPRESENTER_H
