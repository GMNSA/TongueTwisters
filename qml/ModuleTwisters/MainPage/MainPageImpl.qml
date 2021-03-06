import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import ModuleTwisters.BreathingExercisesPage 1.0
import ModuleTwisters.Tile 1.0
import ModuleTwisters.ClassicsPage 1.0
import ModuleTwisters.VoicePage 1.0
import ModuleTwisters.PoemsPage 1.0

Page {
    id: _root

    property real fwidth: 100
    property int fspacing: 10
    property int fPixelSize: 22

    property alias fpoems: _poemsPage
    property alias fvoice: _VoicePage
    property alias fclassics: _classicsPage
    property alias fbreathing: _breathingPage


    BreathingExercisesImpl {
        id: _breathingPage
        visible: false

    }

    ClassicsImpl {
        id: _classicsPage
        visible: false
    }

    VoiceImpl {
        id: _VoicePage
        visible: false

    }

    PoemsImpl {
        id: _poemsPage
        visible: false

    }

    Item {
        id: _wrapper

        anchors.fill: parent
        anchors.topMargin: parent.height * 0.1

        anchors.margins: Math.min(parent.width, parent.height) * 0.05


        Grid {
            id: _grid

            columns: 2

            spacing: fspacing

            anchors.fill: parent
            anchors.centerIn: parent


            TileImpl {
                id: _tile1
                width: Math.min(parent.width, parent.height) / 2 - (fspacing / 2)
                height: Math.min(parent.width, parent.height) / 2

                fSize: Math.min(parent.width, parent.height) / fPixelSize

                // fImage: "qrc:/resources/cauldron.svg"
                fImage: "qrc:/resources/coughing_cough.png"
                fText: "Классика"

                onCustomClick: {
                    _header.ftext = "Classics"
                    _stack.push(_classicsPage)
                }
            }

            TileImpl {
                id: _tile2
                width: Math.min(parent.width, parent.height) / 2 - (fspacing / 2)
                height: Math.min(parent.width, parent.height) / 2

                fSize: Math.min(parent.width, parent.height) / fPixelSize

                // fImage: "qrc:/resources/kitty.svg"
                fImage: "qrc:/resources/dizziness_dizzy_custom.png"
                fText: "Стихи"

                onCustomClick: {
                    _header.ftext = "Poems"
                    _stack.push(_poemsPage)
                }
            }

            TileImpl {
                id: _tile3
                width: Math.min(parent.width, parent.height) / 2 - (fspacing / 2)
                height: Math.min(parent.width, parent.height) / 2

                fSize: Math.min(parent.width, parent.height) / fPixelSize

                // fImage: "qrc:/resources/mask.svg"
                fImage: "qrc:/resources/headache_head_custom.png"
                fText: "Дыхательная \n гимнастика"

                onCustomClick: {
                    _header.ftext = "BreathingExercises"
                    _stack.push(_breathingPage)
                }
            }

            TileImpl {
                id: _tile4
                width: Math.min(parent.width, parent.height) / 2 - (fspacing / 2)
                height: Math.min(parent.width, parent.height) / 2

                fSize: Math.min(parent.width, parent.height) / fPixelSize

                // fImage: "qrc:/resources/spider.svg"
                fImage: "qrc:/resources/sneezing_spread_custom.png"
                fText: "Голос"

                onCustomClick: {
                    _header.ftext = "Voice"
                    _stack.push(_VoicePage)
                }
            }

        }
    }
}

