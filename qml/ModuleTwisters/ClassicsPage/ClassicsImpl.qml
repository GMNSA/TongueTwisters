import QtQuick 2.15
import QtQuick.Controls 2.5

import alpha.modelDataTongue 1.0

Page {

    ModelDataTongue {
        id: _model
    }

    ListView {
     width: parent.width
     height: parent.height

     model: _model
     delegate: Rectangle {

         width: parent.width
         height: 20
         clip: true

         color: Qt.rgba(Math.random(), Math.random(), Math.random())

         Text {
             text: display
         }
     }
 }
}
