import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

import StyleConfig 1.0
import ModuleHeader 1.0
import ModuleTwisters.MainPage 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Material.theme: Style.isDarkTheme ? Material.Light :
                                        Material.Dark

    header: HeaderCustom {
        id: _header
    }

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
