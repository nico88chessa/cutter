import QtQuick 2.12
import QtQuick.Controls 2.12

import Cutter.CoreController 1.0 as CoreCtrl
import Cutter.ApplicationData 1.0 as ApplicationData
import QtQuick.Layouts 1.3


ApplicationWindow {

    width: 1024
    height: 768
    opacity: 1

    visible: true
    title: ApplicationData.ApplicationData.pApplicationName + " - " + ApplicationData.ApplicationData.pApplicationVersion

    GridLayout {
        id: gridLayout
        anchors.fill: parent

        ListView {
            id: listView
            width: 110
            height: 160
            model: CoreCtrl.CoreController.pMenuModel

            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    spacing: 10

                    Text {
                        text: "Ciao - " + pLabel + " - " + pIconPath
                        anchors.verticalCenter: parent.verticalCenter
                        font.bold: true
                    }
                }
            }
        }

        Button {
            id: button
            text: qsTr("Button")
        }

        StackLayout {
            id: stackLayout
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true
        }




    }


}

















/*##^## Designer {
    D{i:1;anchors_height:100;anchors_width:100}
}
 ##^##*/
