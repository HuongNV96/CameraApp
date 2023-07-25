import QtQuick
import ExtraModule 1.0
import QtMultimedia
import QtQuick.Controls

Rectangle {
    visible: true
    anchors.fill: parent
    id : cameraView
    property int optionView: 1
    property var cameras: null

    function switchViews(option) {
        if (cameras !== null) {
            cameras.destroy()
            cameras = null
        }
        let component
        if (option === 1) {
            component = Qt.createComponent("qrc:/App/QML/1x1View.qml")
        } else if (option === 2) {
            component = Qt.createComponent("qrc:/App/QML/2x2View.qml")
        } else if (option === 3) {
            component = Qt.createComponent("qrc:/App/QML/4x4View.qml")
        } else {
            component = Qt.createComponent("qrc:/App/QML/1x1View.qml")
        }

        if (component.status !== Component.Ready) {
            console.log("Error create *View.qml")
            return;
        } else {
            cameras = component.createObject(viewArena);
            if (cameras === null) {
                console.log("Error create cameras object")
            }
        }
    }

    Column {
        spacing: 1
        anchors.fill: parent
        Rectangle {
            id : settingArena
            width: parent.width
            height: 0.2 * parent.height
            Column {
                width: 0.1 * parent.width
                height: parent.height

                MenuBar {
                    Menu {
                        title: qsTr("VideoMode")
                        Action {
                            text: qsTr("1x1")
                            onTriggered: {
                                optionView = 1
                                switchViews(optionView)
                            }
                        }
                        Action {
                            text: qsTr("2x1")
                            onTriggered: {
                                optionView = 2
                                switchViews(optionView)
                            }
                        }
                        Action {
                            text: qsTr("4x1")
                            onTriggered: {
                                optionView = 3
                                switchViews(optionView)
                            }
                        }
                    }

                    Menu {
                        title: qsTr("Camera")
                        Action {
                            text: qsTr("Add")
                            onTriggered: {
                            }
                        }

                        Action {
                            text: qsTr("Remove")
                            onTriggered: {
                            }
                        }

                        Action {
                            text: qsTr("Update")
                            onTriggered: {
                            }
                        }
                    }

                }
            }
        }

        Row {
            width: parent.width
            height: 0.8 * parent.height
            Rectangle {
                id : viewArena
                width: 0.7 * parent.width
                height: parent.height
                Component.onCompleted: {
                    switchViews(optionView)
                }
            }
            Rectangle {
                id : infoArena
                width: 0.3 * parent.width
                height: parent.height
            }
        }
    }
}
