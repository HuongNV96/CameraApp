import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

Rect {
    id : loginWindow
    width: 657
    height: 394
    visible: true
    title: qsTr("Camera App")
    color: '#F9F9F9'

    onWidthChanged: {
        loginForm.scaleFactorX = width / 657;
        widthOld = width
    }
    onHeightChanged: {
        loginForm.scaleFactorY = height / 394;
        heightOld = height
    }
    Rectangle {
        id : loginForm
        width: 320 * scaleFactorX
        height: 334 * scaleFactorY
        anchors.centerIn: parent
        color: '#FFFFFF'
        property real scaleFactorX: 1;
        property real scaleFactorY: 1;

        Text {
            text: qsTr("Login")
            anchors.top: loginForm.top
            anchors.horizontalCenter: loginForm.horizontalCenter
            font.pixelSize : 24
            font.family: "Helvetica"
            color: '#111111'
        }
        Rectangle {
            anchors.bottom: loginForm.bottom
            anchors.left: loginForm.left
            anchors.right: loginForm.right
            height: 282 * loginForm.scaleFactorY
            Column {
                id : loginArea
                spacing: 20
                width: 272 * loginForm.scaleFactorX
                anchors.horizontalCenter: parent.horizontalCenter
                Column {
                    spacing: 5
                    Text {
                        text: qsTr("Email")
                        font.pixelSize : 14
                        font.family: "Helvetica"
                    }
                    TextField {
                        placeholderText: qsTr("example@email.com")
                        width: loginArea.width
                        font.pixelSize : 14
                        font.family: "Helvetica"
                        height: 32
                        placeholderTextColor  : '#EEEEEE'
                        verticalAlignment: Qt.AlignVCenter
                        horizontalAlignment: Qt.AlignLeftr
                    }
                }
                Column {
                   spacing: 5
                   RowLayout {
                       width: parent.width
                       Text {
                           text: qsTr("Password")
                           font.pixelSize : 14
                           font.family: "Helvetica"
                           Layout.alignment: Qt.AlignLeft
                       }
                       Text {
                           text: qsTr("Forgot password?")
                           font.pixelSize : 14
                           font.family: "Helvetica"
                           color: '#007AFF'
                           Layout.alignment: Qt.AlignRight
                       }
                   }
                   TextField {
                       placeholderText: qsTr("*********")
                       width: loginArea.width
                       font.pixelSize : 14
                       font.family: "Helvetica"
                       height: 32
                       placeholderTextColor  : '#EEEEEE'
                       echoMode: TextInput.Password
                       verticalAlignment: Qt.AlignVCenter
                       horizontalAlignment: Qt.AlignLeftr
                   }
                }

                Button {
                    text: 'Login'
                    Layout.alignment: Qt.AlignCenter
                    width: parent.width
                    height : 34
                    font.pixelSize : 16
                    font.family: "Helvetica"
                    background: Rectangle {
                            color: '#007AFF'
                    }
                }
                ColumnLayout {
                    width: parent.width
                    spacing: 5
                    Text {
                        text: qsTr("Don’t have account?")
                        font.pixelSize : 14
                        font.family: "Helvetica"
                        Layout.alignment: Qt.AlignCenter
                    }
                    Text {
                        text: qsTr("Create new account")
                        color: '#007AFF'
                        font.pixelSize : 14
                        font.family: "Helvetica"
                        Layout.alignment: Qt.AlignCenter
                    }
                }
            }
        }
    }
}
