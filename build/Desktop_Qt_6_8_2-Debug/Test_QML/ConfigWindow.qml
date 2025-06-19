import QtQuick
import QtQuick.Controls 2.15
import QtCore


Window {
    id: configWindow
    width: 1280
    height: 720
    visible: true
    color: "#ffffff"
    title: qsTr("Configuration Window")
    Grid {
        id: grid
        anchors.fill: parent
        anchors.leftMargin: 50
        anchors.rightMargin: 50
        anchors.topMargin: 50
        anchors.bottomMargin: 50
        spacing: 50
        verticalItemAlignment: Grid.AlignVCenter
        horizontalItemAlignment: Grid.AlignHCenter
        columns: 4
        columnSpacing: 100
        rows: 2
        rowSpacing: 300

        Rectangle {
            id: rect1
            width: 255
            height: 255
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            Image {
                width: 250
                height: 250
                source: "qrc:///src/offset.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 250
                sourceSize.width: 250
            }
        }
        
        Rectangle {
            id: rect2
            width: 255
            height: 255
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 50
            Image {
                width: 250
                height: 250
                source: "qrc:///src/mirror.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 250
                sourceSize.width: 250
            }
        }
        
        Rectangle {
            id: rect3
            width: 255
            height: 255
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 50
            anchors.top: parent.top
            anchors.topMargin: 5
            Image {
                width: 250
                height: 250
                source: "qrc:///src/zoom.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 250
                sourceSize.width: 250
            }
        }
        
        Rectangle {
            id: rect4
            width: 255
            height: 255
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: parent.right
            anchors.rightMargin: 5
            Image {
                width: 250
                height: 250
                source: "qrc:///src/rot.png"
                anchors.centerIn: parent
                fillMode: Image.PreserveAspectFit
                sourceSize.height: 250
                sourceSize.width: 250
            }
        }
        
        Column {
            id: decalageColumn
            spacing: 10
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            Rectangle {
                id: borderdecalageX
                width: 220
                height: 70
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                TextField {
                    id: decalageX
                    placeholderText: qsTr("decalage X")
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
                id: borderdecalageY
                width: 220
                height: 70
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                TextField {
                    id: decalageY
                    placeholderText: qsTr("decalage Y")
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
            width: 220
            height: 70
            color: "#00000000"
            radius: 10.0
            border.color: "#c30d1263"
            border.width: 1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 75
            CheckBox {
                id: mirror
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
            id: borderZoom
            width: 220
            height: 70
            color: "#00000000"
            radius: 10.0
            border.color: "#c30d1263"
            border.width: 1
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: 75
            TextField {
                id: zoom
                placeholderText: qsTr("Zoom")
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
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 5
            anchors.bottomMargin: 5
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
    }    
}
