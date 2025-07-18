import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Window {

    id: libraryWindow
    visible: true
    color: "#ffffff"
    visibility: "Maximized"
    minimumHeight: 720
    minimumWidth: 1280
    flags: Qt.SubWindow
    title: qsTr("Library Window")

    Row {
        id: row
        anchors.fill: parent
        anchors.margins: 50
        spacing: 25
        // height: 720
        // width: 1280
        Rectangle {
            id: borderFoundCompLib
            width: (row.width / 3)
            height: row.height
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            ScrollView {
                id: foundCompLib
                width: (row.width / 3) - 50
                height: row.height - 50
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                TextEdit {
                    id: editFoundCompLib
                    width: (row.width / 3) - 50
                    height: row.height - 50
                    focus: true
                    wrapMode: TextEdit.Wrap
                }
            }
        }

        Rectangle {
            id: borderNotFoundCompLib
            width: (row.width / 3)
            height: row.height
            color: "#00000000"
            border.color: "#c30d1263"
            border.width: 1
            radius: 10.0
            ScrollView {
                id: notFoundCompLib
                width: (row.width / 3) - 50
                height: row.height - 50
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                TextEdit {
                    id: editNotFoundCompLib
                    width: (row.width / 3) - 50
                    height: row.height - 50
                    focus: true
                    wrapMode: TextEdit.Wrap
                }
            }
        }
        
        GridLayout {
            uniformCellWidths: true
            uniformCellHeights: true
            rowSpacing: 50
            columnSpacing: 50
            rows: 4
            columns: 2
            Rectangle {
                id: borderPackageCADTextField
                width: packageCADTextField.width + 20
                height: packageCADTextField.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                TextField {
                    id: packageCADTextField
                    placeholderText: qsTr("CAD Package")
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
                }
            }

            Rectangle {
                id: borderValueCADTextField
                width: valueCADTextField.width + 20
                height: valueCADTextField.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                TextField {
                    id: valueCADTextField
                    placeholderText: qsTr("CAD Value")
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
                }
            }

            Rectangle {
                id: borderNameMyDATATextField
                width: nameMyDATATextField.width + 20
                height: nameMyDATATextField.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.columnSpan: 2
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                TextField {
                    id: nameMyDATATextField
                    placeholderText: qsTr("Name MYDATA")
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
                }
            }

            Rectangle {
                id: borderCollageCheckBox
                width: collageCheckBox.width + 20
                height: collageCheckBox.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                CheckBox {
                    id: collageCheckBox
                    anchors.centerIn: parent
                    width: 200
                    height: 50
                    text: qsTr("Collage")
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
                id: borderMontageCheckBox
                width: montageCheckBox.width + 20
                height: montageCheckBox.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                CheckBox {
                    id: montageCheckBox
                    anchors.centerIn: parent
                    width: 200
                    height: 50
                    text: qsTr("Montage")
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
                id: borderPriorityComboBox
                width: priorityComboBox.width + priorityText.contentWidth + 20
                height: priorityComboBox.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Text {
                    id: priorityText
                    text: qsTr("Priority")
                    anchors.verticalCenter: parent.verticalCenter

                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.right: priorityComboBox.left
                    anchors.rightMargin: 10
                    font.pointSize: 22
                }
                ComboBox {
                    id: priorityComboBox
                    width: 75
                    height: 50
                    anchors.verticalCenter: parent.verticalCenter
                    // anchors.left: priorityText.right
                    anchors.right: parent.right
                    anchors.rightMargin: 10
                    //leftPadding: priorityComboBox.width / 2.5
                    font.pointSize: 32
                    textRole: "key"
                    //ToolTip.visible: hovered
                    ToolTip.visible: down
                    ToolTip.text: qsTr("7ambouk")
                    model: ListModel {
                        ListElement { key: "0"}
                        ListElement { key: "1"}
                        ListElement { key: "2"}
                        ListElement { key: "3"}
                        ListElement { key: "4"}
                        ListElement { key: "5"}
                        ListElement { key: "6"}
                        ListElement { key: "7"}
                        ListElement { key: "8"}
                    }
                }
            }


            Rectangle {
                id: borderCompAngleComboBox
                width: compAngleComboBox.width + 20
                height: compAngleComboBox.height + 20
                color: "#00000000"
                radius: 10.0
                border.color: "#c30d1263"
                border.width: 1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                ComboBox {
                    id: compAngleComboBox
                    width: 150
                    height: 50
                    font.pointSize: 32
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    // leftPadding: compAngleComboBox.width / 2.5
                    textRole: "key"
                    model: ListModel {
                        ListElement { key: "0°"; value: 0 }
                        ListElement { key: "90°"; value: 90 }
                        ListElement { key: "180°"; value: 180 }
                        ListElement { key: "270°"; value: 270 }
                    }
                }
            }
        }
    }
}
