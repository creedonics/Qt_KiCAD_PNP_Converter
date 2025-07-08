import QtCore
import QtQuick
import QtQuick.Controls 2.15
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

    Image {
        id: loremeImage
        z: -1
        source: "qrc:///src/Loreme.jpg"
        fillMode: Image.PreserveAspectFit
        sourceSize.height: 200
        sourceSize.width: 200
    }

    Rectangle {
        id: fileSelectionBorder
        anchors.fill: parent
        anchors.leftMargin: 280
        anchors.rightMargin: 280
        anchors.topMargin: 50
        anchors.bottomMargin: 50
        color: "#00000000"
        border.color: "#c30d1263"
        border.width: 1
        radius: 10.0
        ColumnLayout {
            id: fileSelection
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            anchors.fill: parent
            spacing: 50

            Text {
                id: fileDialogNote
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                text: qsTr("Select a KiCAD .pos file or a P-CAD .pnp file to generate the MYDATA manufacturig files")
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.Wrap
                Layout.maximumWidth: 700
                maximumLineCount: 3
                font.pointSize: 22
                font.family: "Arial"
                font.bold: true
            }

            Button {
                id: fileDialogButton
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                text: qsTr("Choose a File")
                highlighted: true
                onClicked: fileDialog.open()
            }

            FileDialog {
                id: fileDialog
                nameFilters: ["KiCAD Positioning files (*.pos)", "Pcad Pick and Place files (*.pnp)"]
                //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
                onAccepted: {
                    fileDialog.OpenFile
                    KiCADFile.getFilePathUrl(selectedFile);
                    R_Conf.readingMydataConfigFile();
                    LibFile.readingMydataLibFile();
                }
            }

            Text {
                id: cadFileDropAreaNote
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                text: qsTr("or drop it here :")
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.Wrap
                Layout.maximumWidth: 700
                maximumLineCount: 3
                font.pointSize: 22
                font.family: "Arial"
                font.bold: true
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
                    onDropped: {
                        parent.border.color = "#ad0e36"
                        //parent.border.width = 1
                        console.log(drop.text)
                        KiCADFile.getFilePathUrl(drop.text);
                        R_Conf.readingMydataConfigFile();
                        LibFile.readingMydataLibFile();
                    }
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
        }
    }

    Button {
        id: configButton
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 50
        text: qsTr("Configuration")
        onClicked: {
            var component = Qt.createComponent("ConfigWindow.qml");
            component.createObject();
        }
    }

}

