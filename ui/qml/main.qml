import QtQuick 2.12
import QtQuick.Controls 2.12

import Cutter.CoreController 1.0 as CoreCtrl
import Cutter.ApplicationData 1.0 as ApplicationData


ApplicationWindow {

    width: 1024
    height: 768
    opacity: 1

    visible: true
    title: ApplicationData.ApplicationData.pApplicationName + " - " + ApplicationData.ApplicationData.pApplicationVersion

    Button {
        id: button
        x: 146
        y: 100
        text: ApplicationData.ApplicationData.pApplicationName
        onClicked: CoreCtrl.CoreController.test()
    }

    Button {
        id: button3
        x: 497
        y: 100
        text: ApplicationData.ApplicationData.pApplicationVersion
        onClicked: CoreCtrl.CoreController.test()
    }

    Item {
        Component.onCompleted: CoreCtrl.CoreController.test()
    }

    CutConfiguration {
        id: cutConfiguration
        x: 237
        y: 232
    }


//    CoreController {
//        id: coreCtrl
//    }

}
