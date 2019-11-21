import QtQuick 2.12
import QtQuick.Controls 2.12
import Cutter.CoreController 1.0 as CoreCtrl


ApplicationWindow {

    width: 1024
    height: 768
    opacity: 1

    visible: true
    title: qsTr("Test")

    Button {
        id: button
        x: 146
        y: 100
        text: qsTr("Button")
        onClicked: CoreCtrl.CoreController.test()
    }

    Item {
        Component.onCompleted: CoreCtrl.CoreController.test()
    }

//    CoreController {
//        id: coreCtrl
//    }

}
