import QtQuick 2.12
import QtQuick.Controls 2.12

import Cutter.CoreController 1.0 as CoreCtrl
import Cutter.ApplicationData 1.0 as ApplicationData
import QtQuick.Layouts 1.3
//import com.dv 1.0


ApplicationWindow {

    width: 1024
    height: 768
    opacity: 1

    visible: true
    title: ApplicationData.ApplicationData.pApplicationName + " - " + ApplicationData.ApplicationData.pApplicationVersion

    GridLayout {
        id: gridLayout
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent

        ListView {
            id: listView
            Layout.minimumWidth: 200
            Layout.fillHeight: true
            model: CoreCtrl.CoreController.pMenuModel
            clip: true

            delegate: Item {
                id: itemRow
                x: 5
                width: listView.width
                height: 36

                Row {
                    id: row
                    spacing: 10
                    anchors.fill: parent

                    Text {
                        id: textRow
                        text: "Ciao - " + pKeyRole + " - " + pLabelRole
                        verticalAlignment: Text.AlignVCenter
                        anchors.top: parent.top
                        height: parent.height
                        width: parent.width
                        font.bold: true
                        color: "red";
                    }

                }
                MouseArea {
                    id: mouseAreaRow
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked: { listView.currentIndex = pKeyRole }
                    onEntered: { textRow.color = "blue" }
                    onExited: { textRow.color = "red" }
                }

            }

            onCurrentIndexChanged: { stackLayout.currentIndex = listView.currentIndex }
            highlightFollowsCurrentItem: true
            focus: true
            highlight: Rectangle {
                radius: 10
                color: "lightGray"
                width: parent.width
                height: 36
            }
        }

        StackLayout {
            id: stackLayout
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: 0

            Setup {
                id: setup
            }

            SystemStatus {
                id: systemStatus
            }


        }




    }


}


















