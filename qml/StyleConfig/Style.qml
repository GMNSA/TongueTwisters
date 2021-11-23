pragma Singleton

import QtQuick 2.15

QtObject {
	id: _root

    property bool isDarkTheme: true

    property color fcolorPress: isDarkTheme ?  "#877B7B" : "#362A2A"

    property color fcolorTile: isDarkTheme ?  "#D9C3CC"  : "#877B7B"
                                           // : "#362A2A"
}
