import QtQuick
import QtQuick.Controls 2.15
import QtCore
import QtQuick.Layouts
import QtQuick.Dialogs

Window {
    id: configWindow
    width: 1280
    height: 720
    visible: true
    color: "#ffffff"
    minimumHeight: 720
    minimumWidth: 1280
    flags: Qt.SubWindow
    title: qsTr("Configuration Window")
    //property QString str;
    property int rot
    property bool mirror
    GridLayout {
        id: grid
        anchors.fill: parent
        anchors.leftMargin: 50
        anchors.rightMargin: 50
        anchors.topMargin: 50
        anchors.bottomMargin: 50
        uniformCellWidths: false
        uniformCellHeights: false
        columns: 4
        columnSpacing: 50
        rows: 3
        rowSpacing: 50

        Text {
            id: offsetText
            width: 200
            height: 50
            text: "Offset"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.italic: true
            font.bold: true
            font.pointSize: 26
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        }

        Text {
            id: mirrorText
            width: 200
            height: 50
            text: "Mirror effect"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.italic: true
            font.bold: true
            font.pointSize: 26
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Text {
            id: scaleText
            width: 200
            height: 50
            text: "Scaling"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.italic: true
            font.bold: true
            font.pointSize: 26
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Text {
            id: rotText
            width: 200
            height: 50
            text: "Rotation"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.italic: true
            font.bold: true
            font.pointSize: 26
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }

        Rectangle {
            id: borderOffsetImage
            width: offsetImage.width + 5
            height: offsetImage.height + 5
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.left: parent.left
            //anchors.leftMargin: 5
            //anchors.top: parent.top
            //anchors.topMargin: 5
            Image {
                id: offsetImage
                width: 200
                height: 200
                source: "qrc:///src/offset.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 200
                sourceSize.width: 200
            }
        }
        
        Rectangle {
            id: borderMirrorImage
            width: mirrorImage.width + 5
            height: mirrorImage.height + 5
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.top: parent.top
            //anchors.topMargin: 5
            //anchors.right: parent.horizontalCenter
            //anchors.rightMargin: 50
            Image {
                id: mirrorImage
                width: 200
                height: 200
                source: "qrc:///src/mirror.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 200
                sourceSize.width: 200
            }
        }
        
        Rectangle {
            id: borderScaleImage
            width: scaleImage.width + 5
            height: scaleImage.height + 5
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.left: parent.horizontalCenter
            //anchors.leftMargin: 50
            //anchors.top: parent.top
            //anchors.topMargin: 5
            Image {
                id: scaleImage
                width: 200
                height: 200
                source: "qrc:///src/zoom.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 200
                sourceSize.width: 200
            }
        }
        
        Rectangle {
            id: borderRotImage
            width: rotImage.width + 5
            height: rotImage.height + 5
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.top: parent.top
            //anchors.topMargin: 5
            //anchors.right: parent.right
            //anchors.rightMargin: 5
            Image {
                id: rotImage
                width: 200
                height: 200
                source: "qrc:///src/rot.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 200
                sourceSize.width: 200
            }
        }
        
        Column {
            id: offsetColumn
            spacing: 10
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.left: parent.left
            //anchors.leftMargin: 5
            //anchors.bottom: parent.bottom
            //anchors.bottomMargin: 5
            Rectangle {
                id: borderOffsetXTextField
                width: offsetXTextField.width + 20
                height: offsetXTextField.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                TextField {
                    id: offsetXTextField
                    placeholderText: qsTr("Offset X Axis")
                    anchors.centerIn: parent
                    width: 200
                    height: 50
                    color: "#ffffff"
                    font.pixelSize: 32
                    verticalAlignment: Text.AlignVCenter
                    mouseSelectionMode: TextInput.SelectWords
                    placeholderTextColor: "#7fffffff"
                    inputMask: ""
                    font.italic: true
                    validator: DoubleValidator {
                        decimals: 6
                        notation: DoubleValidator.StandardNotation
                    }
                }
            }

            Rectangle {
                id: borderOffsetYTextField
                width: offsetYTextField.width + 20
                height: offsetYTextField.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                TextField {
                    id: offsetYTextField
                    placeholderText: qsTr("Offset Y Axis")
                    anchors.centerIn: parent
                    width: 200
                    height: 50
                    color: "#ffffff"
                    font.pixelSize: 32
                    verticalAlignment: Text.AlignVCenter
                    mouseSelectionMode: TextInput.SelectWords
                    placeholderTextColor: "#7fffffff"
                    inputMask: ""
                    font.italic: true
                    validator: DoubleValidator {
                        decimals: 6
                        notation: DoubleValidator.StandardNotation
                    }
                }
            }
        }
        
        Rectangle {
            id: borderMirror
            width: mirrorCheckBox.width + 20
            height: mirrorCheckBox.height + 20
            color: "#00000000"
            radius: 10.0
            border.color: "#c30d1263"
            border.width: 1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.bottom: parent.bottom
            //anchors.bottomMargin: 5
            //anchors.right: parent.horizontalCenter
            //anchors.rightMargin: 75
            CheckBox {
                id: mirrorCheckBox
                anchors.centerIn: parent
                width: 200
                height: 50
                text: qsTr("Mirror")
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                font.weight: Font.ExtraLight
                font.italic: true
                font.pointSize: 32
                anchors.right: parent.horizontalCenter
                anchors.rightMargin: 100
            }
        }
        
        Rectangle {
            id: borderScaleTextField
            width: scaleTextField.width + 20
            height: scaleTextField.height + 20
            color: "#00000000"
            radius: 10.0
            border.color: "#c30d1263"
            border.width: 1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.bottom: parent.bottom
            //anchors.bottomMargin: 5
            //anchors.left: parent.horizontalCenter
            //anchors.leftMargin: 75
            TextField {
                id: scaleTextField
                placeholderText: qsTr("Scale")
                anchors.centerIn: parent
                width: 200
                height: 50
                color: "#ffffff"
                font.pixelSize: 32
                verticalAlignment: Text.AlignVCenter
                mouseSelectionMode: TextInput.SelectWords
                placeholderTextColor: "#7fffffff"
                inputMask: ""
                font.italic: true
                validator: DoubleValidator {
                    decimals: 6
                    notation: DoubleValidator.StandardNotation
                }
            }
        }
        
        Rectangle {
            id: borderRadioButtonsColumn
            width: 220
            height: 250
            color: "#00000000"
            radius: 10.0
            border.color: "#c30d1263"
            border.width: 1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            //anchors.right: parent.right
            //anchors.bottom: parent.bottom
            //anchors.rightMargin: 5
            //anchors.bottomMargin: 5
            Column {
                id: radioButtonsColumn
                anchors.centerIn: parent
                spacing: 10

                RadioButton {
                    id: pos0
                    width: 200
                    height: 50
                    checked: true
                    text: qsTr("0°")
                    font.weight: Font.Normal
                    font.italic: true
                    font.pointSize: 32
                }

                RadioButton {
                    id: pos90
                    width: 200
                    height: 50
                    text: qsTr("90°")
                    font.weight: Font.Normal
                    font.italic: true
                    font.pointSize: 32
                }
                RadioButton {
                    id: pos180
                    width: 200
                    height: 50
                    text: qsTr("180°")
                    font.weight: Font.Normal
                    font.italic: true
                    font.pointSize: 32
                }
                RadioButton {
                    id: pos270
                    width: 200
                    height: 50
                    text: qsTr("270°")
                    font.weight: Font.Normal
                    font.italic: true
                    font.pointSize: 32
                }
            }


        }


        Button {
            id: clearButton
            width: 200
            height: 50
            text: qsTr("Clear")
            //Layout.columnSpan: 2
            //Layout.rowSpan: 1
            Layout.preferredWidth: -1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: {
                scaleTextField.clear()
                offsetXTextField.clear()
                offsetYTextField.clear()
                pos0.checked = true
                mirrorCheckBox.checked = false
            }
        }

        Button {
            id: validationButton
            width: 200
            height: 50
            text: qsTr("Validate")
            //Layout.columnSpan: 2
            //Layout.rowSpan: 1
            Layout.preferredWidth: -1
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: {
                scaleTextField.accepted()
                offsetXTextField.accepted()
                offsetYTextField.accepted()
                if (pos0.checked) rot = 0
                if (pos90.checked) rot = 90
                if (pos180.checked) rot = 180
                if (pos270.checked) rot = 270
                W_Conf.getConfigParameters(offsetXTextField.text, offsetYTextField.text, scaleTextField.text, rot, mirrorCheckBox.checked);

            }
        }

        FileDialog {
            id: configFileDialog
            nameFilters: ["MYDATA Configuration File (*.ini)"]
            //currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            onAccepted: {
                configFileDialog.OpenFile

            }
        }

        Button {
            id: configFileDialogButton
            width: 200
            height: 50
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            text: qsTr("Choose a Config file")
            highlighted: true
            onClicked: configFileDialog.open()
        }
    }    
}
