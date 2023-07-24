import QtQuick
import App 1.0

Rectangle {
    anchors.fill: parent
    Row {
        anchors.fill: parent
        Rectangle {
            width: parent.width * 0.495
            height: parent.height
            CameraPlayer {

            }
        }

        Rectangle {
            width: parent.width * 0.01
            height: parent.height
        }

        Rectangle {
            width: parent.width * 0.495
            height: parent.height
            CameraPlayer {

            }
        }
    }
}
