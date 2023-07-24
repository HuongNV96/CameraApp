import QtQuick
import QtQuick.Window
import QtQuick.Controls
import ExtraModule 1.0
import App 1.0

Window {
    title: qsTr("Camera Manager")
    width: 640
    height: 480
    visible: true
    id : mainWindow

    property var loginView: null
    property var cameraView: null

    property QtObject loginPresenter: LoginPresenter {
        onLoginedStatus : (status) => {
            if (!status) {
                let component = Qt.createComponent("qrc:/App/QML/LoginForm.qml")
                if (component.status !== Component.Ready) {
                    console.log("Error create LoginForm.qml")
                    return;
                } else {
                    if (loginView === null) {
                        loginView = component.createObject(mainWindow, { width : mainWindow.width,
                                                               height : mainWindow.height,
                                                               loginPresenter : mainWindow.loginPresenter});
                        if (loginView === null) {
                            console.log("Error create loginForm object")
                        }
                    }
                }

                if (cameraView !== null) {
                    cameraView.destroy()
                }
            } else {
                let component = Qt.createComponent("qrc:/App/QML/CameraView.qml")
                if (component.status !== Component.Ready) {
                    console.log("Error create CameraView.qml")
                    return;
                } else {
                    if (cameraView == null) {
                        cameraView = component.createObject(mainWindow, { width : mainWindow.width,
                                                         height : mainWindow.height});
                        if (cameraView == null) {
                            console.log("Error create cameraView object")
                        }
                    }
                }

                if (loginView !== null) {
                  loginView.destroy()
                }
            }

            console.log("onLoginedStatus " + status)
        }

        onLoggingStatus: (status) => {
            loginStatus.running = status
            console.log("onLoggingStatus " + status)
        }
    }

    BusyIndicator {
        id : loginStatus
        width: 60
        height: 60
        anchors.centerIn: parent
        running: false
        z : 1
    }
}
