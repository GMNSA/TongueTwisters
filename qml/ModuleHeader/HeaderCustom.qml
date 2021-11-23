import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import StyleConfig 1.0

ToolBar {
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
            text: "Title"
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth: true
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
}

