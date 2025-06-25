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
    minimumHeight: 720
    minimumWidth: 1280
    flags: Qt.Window
    title: qsTr("DuMoulinette")

    /*Connections {
        target: conf // Specify the target to connect
        /* Declare and implement the function as a parameter
         * object and with a name similar to the name of the signal
         * The difference is that we add on at the beginning and then write
         * capitalized
         * *

    }*/

    GridLayout {
        id: gridLayout
        anchors.fill: parent
        anchors.leftMargin: 50
        anchors.rightMargin: 50
        anchors.topMargin: 50
        anchors.bottomMargin: 50
        columnSpacing: 150
        columns: 2
        rows: 1
        uniformCellWidths: true
        uniformCellHeights: true


        Button {
            id: fileDialogButton
            width: 200
            height: 50
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: qsTr("Choose a File")
            highlighted: true
            onClicked: fileDialog.open()
        }

        Rectangle {
            id: borderCadFileDropArea
            width: cadFileDropArea.width + 5
            height: cadFileDropArea.height + 5
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            DropArea {
                id: cadFileDropArea
                width: 200
                height: 200
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                //Layout.preferredHeight: 200
                //Layout.preferredWidth: 200
                Image {
                    id: dragDropImage
                    width: 200
                    height: 200
                    source: "qrc:///src/DragDrop.jpg"
                    anchors.centerIn: parent
                    fillMode: Image.PreserveAspectFit
                    sourceSize.height: 200
                    sourceSize.width: 200
                }
            }
        }


        Button {
            id: configButton
            width: 200
            height: 50
            text: qsTr("Configuration")
            Layout.columnSpan: 2
            Layout.rowSpan: 1
            Layout.preferredWidth: -1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
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
}

