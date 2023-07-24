import QtQuick
import App 1.0

Rectangle {
    anchors.fill: parent
    Row {
        anchors.fill: parent
        Column {
            width: parent.width * 0.495
            height: parent.height
            Rectangle {
                width: parent.width
                height: parent.height * 0.495
                color: 'red'
            }

            Rectangle {
                width: parent.width
                height: parent.height * 0.01
            }

            Rectangle {
                width: parent.width
                height: parent.height * 0.495
                color: 'green'
            }
        }

        Rectangle {
            width: parent.width * 0.01
            height: parent.height
        }

        Column {
            width: parent.width * 0.495
            height: parent.height
            Rectangle {
                width: parent.width
                height: parent.height * 0.495
                color: 'green'
            }

            Rectangle {
                width: parent.width
                height: parent.height * 0.01
            }

            Rectangle {
                width: parent.width
                height: parent.height * 0.495
                color: 'red'
            }
        }
    }
}
