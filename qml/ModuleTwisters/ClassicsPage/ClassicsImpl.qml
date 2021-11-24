import QtQuick 2.15
import QtQuick.Controls 2.5

import alpha.modelDataTongue 1.0
import ModuleTwisters.WrapperText 1.0

import ModuleHeader 1.0

Page {
    id: _root


    ModelDataTongue {
        id: _model
    }

    ListView {
        id: _listView

        width: parent.width
        height: parent.height

        spacing: 50

        model: _model
        delegate: WrapperTextImpl {
            width: _listView.width
        }
    }
}
