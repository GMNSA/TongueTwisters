import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import StyleConfig 1.0
import QtQuick.Controls.Material 2.3
import QtGraphicalEffects 1.15


ToolBar {
    property string ftext: "anonim"


    RowLayout {
        anchors.fill: parent

        ToolButton {
            enabled: _stack.depth === 1 ? false : true
            text: _stack.depth === 1 ? qsTr("TongueTwister") :
                                      qsTr("‹")
            onClicked: {
                console.log("depth: " << _stack.depth)
                _stack.pop()
            }
        }

        Label {
            // text: "Title"
            text: _stack.depth === 1 ? "" : ftext
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true

            font.bold: true
            opacity: 0.5
        }

        ToolButton {

            visible: _stack.depth > 1 ? true : false
            Image {
                id: _imageSort
                anchors.fill: parent
                source: "qrc:/sorting.svg"
                scale: 0.5
                smooth: true
            }

            ColorOverlay {
                anchors.fill:  Style.isDarkTheme ? _imageSort : _imageSort
                source: _imageSort
                color: "#8E9597"
                scale: 0.5
                antialiasing: true
            }


            onClicked: _menuSort.open()
        }


        ToolButton {
            text: qsTr("⋮")
            onClicked: _menu.open()
        }

    }

    Item {
        anchors.right: parent.right
        width: _menu.width
        height: _menu.height

        Menu {
            id: _menu

            MenuItem {
                text: Style.isDarkTheme ? "Light" :
                                          "Black"

                onTriggered: {
                    Style.isDarkTheme = Style.isDarkTheme ? false :
                                                            true
                }
            }

            MenuItem {
                text: qsTr("Exit")

                onTriggered: {
                    Qt.quit()
                }
            }
        }
    }

    Item {
        anchors.right: parent.right
        width: _menu.width
        height: _menu.height

        Menu {
            id: _menuSort

            MenuItem {
                text: qsTr("Sorting")

                onTriggered: {
                    console.log("SORTING")
                }
            }
        }
    }

    /*          ***** ***** ***** *****          */
    /*                                           */

    background: Rectangle {
        implicitWidth: 40
        implicitHeight: 50
        // color: Qt.darker("#33333333", control.enabled && (control.checked || control.highlighted) ? 1.5 : 1.0)
        color: Style.fheaderColor
        opacity: enabled ? 1 : 0.3
        // visible: control.down || (control.enabled && (control.checked || control.highlighted))
    }
}

