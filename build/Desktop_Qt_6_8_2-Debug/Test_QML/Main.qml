//import QtCore
import QtQuick
import QtQuick.Controls 2.15
//import QtQuick.Layouts 2.15
import QtQuick.Dialogs
import QtQuick.Layouts
import QtQuick.Window

Window {
    id: mainWindow
    width: 1280
    height: 720
    visible: true
    title: qsTr("DuMoulinet")

    MenuBar {
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&New...") }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    Button {
        id: fileDialogButton
        width: 200
        height: 50
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 100
        anchors.bottom: parent.verticalCenter
        text: qsTr("Choose a File")
        onClicked: fileDialog.open()
    }


    Button {
        id: configButton
        width: 200
        height: 50
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 100
        anchors.bottom: parent.verticalCenter
        text: qsTr("Configuration")
        onClicked: {
            var component = Qt.createComponent("ConfigWindow.qml");
            component.createObject();
        }
    }

    FileDialog {
        id: fileDialog
        nameFilters: ["KiCAD Positioning files (*.pos)", "Pcad Pick and Place files (*.pnp)"]
        //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        onAccepted: fileDialog.OpenFile
    }

}

