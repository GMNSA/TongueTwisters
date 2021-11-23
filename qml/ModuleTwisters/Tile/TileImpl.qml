import QtQuick 2.15
import QtQuick.Controls 2.5

import StyleConfig 1.0

Item {
    id: _root

    property string fText: "TESTING"
    property string fImage: "qrc:/resources/kitty.svg"
    property int fSize: 10

    signal customClick;

    Rectangle  {
        id: _tile

        width: parent.width
        height: parent.height * 0.8

        // color: "#993a2727"
        color: Style.fcolorTile
        border.width: 2
        border.color: "black"
        radius: 10

        Image {
            id: _image

            anchors.fill: parent
            anchors.margins: 10
            source: fImage
        }

        states: State {
            name: "toChangeColor"
            when: _mouseArea.pressed

            PropertyChanges {
                target: _tile
                color: Style.fcolorPress
            }
        }

        transitions: [
            Transition {
                to: "toChangeColor"
                ColorAnimation { duration: 500 }
            },
            Transition {
                from: "toChangeColor"
                ColorAnimation { duration: 200 }
            }
        ]

        MouseArea {
            id: _mouseArea
            anchors.fill: parent

            onClicked: {
                customClick()
            }
        }
    }

    Label {
        id: _text
        text: fText

        horizontalAlignment: Text.AlignHCenter
        anchors.bottom: parent.bottom
        anchors.top: _tile.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: Math.min(parent.width, parent.height) / 20
        font.pixelSize: fSize
    }
}
