import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

import StyleConfig 1.0
import ModuleHeader 1.0
import ModuleTwisters.MainPage 1.0

import alpha.modelclassics 1.0
import alpha.modelbreathing 1.0
import alpha.modelpoems 1.0
import alpha.modelvoice 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Material.theme: Style.isDarkTheme ? Material.Light :
                                        Material.Dark

    menuBar: HeaderCustom {
        id: _header
    }

    // --- models ---

    ModelClassics {
        id: _modelClassics
    }

    ModelBreathing {
        id: _modelBreathing
    }

    ModelPoems {
        id: _modelPoems
    }

    ModelVoice {
        id: _modelVoice
    }

    // ---        ---

    StackView {
        id: _stack
        anchors.fill: parent
        initialItem: _mainPage
    }

    MainPageImpl {
        id: _mainPage
        visible: false
    }

    onClosing: {
        if(_stack.depth > 1){
            close.accepted = false
            _stack.pop();
        }else{
            return;
        }
    }
}
