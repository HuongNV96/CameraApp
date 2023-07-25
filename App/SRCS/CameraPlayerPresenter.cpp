#include "CameraPlayerPresenter.hpp"
#include <QDebug>
#include <QVideoFrame>
#include <QAudioOutput>

CameraPlayerPresenter::CameraPlayerPresenter()
{

}

CameraPlayerPresenter::~CameraPlayerPresenter() {
    mPlayer.stop();
}

void CameraPlayerPresenter::init(QString url)
{
    mPlayer.setAudioOutput(new QAudioOutput());
    mPlayer.setVideoSink(new QVideoSink());
    connect(mPlayer.videoSink(), &QVideoSink::videoFrameChanged, this, &CameraPlayerPresenter::onVideoFrameChanged);
    mPlayer.setSource(QUrl(url));
    mPlayer.play();
}

void CameraPlayerPresenter::onVideoFrameChanged(const QVideoFrame &frame) {
    auto img = frame.toImage();
    img.fill(Qt::red);


    QVideoFrame newFrame(QVideoFrameFormat(img.size(), QVideoFrameFormat::pixelFormatFromImageFormat(img.format())));
    newFrame.map(QVideoFrame::ReadWrite);
    memcpy(newFrame.bits(0), img.bits(), img.sizeInBytes());
    newFrame.unmap();
    mVideoSink->setVideoFrame(newFrame);
}

void CameraPlayerPresenter::setVideoSink(QVideoSink * videoSink) {
    mVideoSink = videoSink;
}
