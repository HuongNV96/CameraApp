import QtQuick
import QtQuick.Window
import ExtraModule 1.0

Window {
    width: 700
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var loginForm : null

    Component.onCompleted: {
        let component = Qt.createComponent("qrc:/App/QML/LoginForm.qml")

        if (component.status !== Component.Ready) {
            console.log("Error creating component")
            return;
        }

        loginForm = component.createObject(this ,{width : this.width, height : this.height})

        if (loginForm == null) {
            //Error Handling
            console.log("Error creating object")
            return;
        }
    }
    Component.onDestruction: {
        if (loginForm !== null) {
            loginForm.destroy()
        }
    }
}
