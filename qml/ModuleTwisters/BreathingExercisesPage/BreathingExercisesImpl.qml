import QtQuick 2.15
import QtQuick.Controls 2.5

import alpha.modelbreathing 1.0
import ModuleTwisters.WrapperText 1.0


Page {
    id: _root

    ModelBreathing {
        id: _modelBreathing
    }

    ListView {
        id: _listView

        width: parent.width
        height: parent.height

        spacing: 50

        model: _modelBreathing
        delegate: WrapperTextImpl {
            width: _listView.width

        }
    }

    Button {
        text: "Up"

        opacity: 0.5

        onClicked: {
            _listView.positionViewAtBeginning()
        }

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: 20
    }
}
