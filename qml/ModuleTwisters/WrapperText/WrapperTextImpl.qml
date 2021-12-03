import QtQuick 2.15
import QtQuick.Controls 2.5


Item {
    id: _root

    height: _separator.height + _text.height


    Rectangle {
        id: _wrapper
        anchors.fill: parent

        color: "transparent"

        Label {
            id: _text

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.margins: 20


            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.Wrap

            text: display
        }

        Text {
            id: _separator
            anchors.top: _text.bottom
            anchors.topMargin: 10

            width: parent.width

            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.Wrap

            text: "* * * * * * *"
        }
    }

}
