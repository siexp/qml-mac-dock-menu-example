import QtQuick 2.14
import QtQuick.Window 2.14

import com.github.siexp 1.0


Window {
    width: 200
    height: 200
    visible: true

    property int _id: -1

    // We cannot use on<Signal> with singleton types but we can connect reaction to it
    Connections {
        target: DockMenu
        onItemClicked: {
            if (id === _id) {
                show()
                raise()
                requestActivate()
            }
        }
    }

    Component.onCompleted: {
        DockMenu.addItem(title, _id)
    }

    onClosing: {
        DockMenu.removeItem(_id)
    }
}
