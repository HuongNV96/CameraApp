import QtQuick
import ExtraModule 1.0


Rectangle {
    id : helloDemo
    x : 10
    y : 10
    width: 100
    height: 100
    color: 'red'

    property QtObject hello: Hello {}

    signal clicked;
    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(parent.hello.test)
            helloDemo.clicked()
        }
    }
}


