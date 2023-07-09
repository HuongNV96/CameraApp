import QtQuick
import ExtraModule 1.0


Rectangle {
    x : 10
    y : 10
    width: 100
    height: 100
    color: 'red'

    property QtObject hello: Hello {}

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(parent.hello.test)
        }
    }
}


