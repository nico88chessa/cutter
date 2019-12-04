import QtQuick 2.12
import QtQuick.Controls 2.12

import Cutter.CoreController 1.0 as CoreCtrl
import Cutter.ApplicationData 1.0 as ApplicationData

Item {

    width: 200
    height: 200

    Button {
        id: button
        x: 10
        y: 10
        text: ApplicationData.ApplicationData.pApplicationName
        onClicked: CoreCtrl.CoreController.test()
    }

}
