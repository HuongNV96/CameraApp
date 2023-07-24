#include "StreamRepeater.hpp"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

StreamRepeater::StreamRepeater(QString input, QString output) {
    mUrlInput = input;
    mUrlOutput = output;
    mRepublic = std::make_unique<QProcess>();
    mRepublic->start("./ffmpeg.exe -re -stream_loop -1 -f rawvideo -pix_fmt "
                     "rgb24 -s 1920x1080 -i pipe:0 -pix_fmt yuv420p "
                     "-f rtsp rtsp://127.0.0.1:8554/stream");
}

StreamRepeater::~StreamRepeater() {
    mExit = true;
    if (mLoop.joinable()) {
        mLoop.join();
    }
}

static byte * matToBytes(Mat &image)
{
    int size = image.total() * image.elemSize();
    byte * bytes = new byte[size];  // you will have to delete[] that later
    std::memcpy(bytes,image.data,size * sizeof(byte));
    return bytes;
}

void StreamRepeater::run() {
    mCap = std::make_unique<VideoCapture>(mUrlInput.toStdString());
    if (!mCap->isOpened()) {
        qDebug() << "Failed to open : " << mUrlInput;
        mRepublic->closeWriteChannel();
        mRepublic->close();
        mRepublic->waitForFinished();
        return;
    }

    cv::Mat frame;
    while (!mExit) {
        if (!mCap->read(frame)) {
            break;
        }
        // Write the data
        auto bytes = matToBytes(frame);
        mRepublic->write((const char *)bytes);
        mRepublic->waitForBytesWritten();
        delete [] bytes;
    }

    mCap.release();
    mRepublic->closeWriteChannel();
    mRepublic->close();
    mRepublic->waitForFinished();
}
