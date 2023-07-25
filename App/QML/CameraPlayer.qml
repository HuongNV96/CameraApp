import QtQuick
import QtMultimedia
import App 1.0
Item {
    anchors.fill: parent
    property QtObject cameraPlayerPresenter: CameraPlayerPresenter {}

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        fillMode : VideoOutput.Stretch
        Component.onCompleted:  {
            cameraPlayerPresenter.setVideoSink(videoSink)
            //cameraPlayerPresenter.init("http://streams.videolan.org/samples/360VR/180.mp4")
            cameraPlayerPresenter.init("./test.mp4")
        }
    }
}
