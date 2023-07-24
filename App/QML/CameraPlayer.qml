import QtQuick
import QtMultimedia

Item {
    anchors.fill: parent
    MediaPlayer {
        id: mediaplayer
        source: "http://streams.videolan.org/samples/360VR/180.mp4"
        audioOutput: AudioOutput {}
        videoOutput: videoOutput
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        fillMode : VideoOutput.Stretch
    }

    Component.onCompleted: {
        onPressed: mediaplayer.play();
    }
}
