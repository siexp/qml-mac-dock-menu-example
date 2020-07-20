import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12

import com.github.siexp 1.0

Window {
    id: root

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        width: 200
        height: 100

        anchors.centerIn: parent
        text: "Spawn window"

        onClicked: {
            const subWindowComponent = Qt.createComponent("qrc:/Subwindow.qml")

            const title = "Window" + _id
            const window = subWindowComponent.createObject(root, { 'title': title, '_id': _id++ })
        }
    }

    property int _id: 0
}
