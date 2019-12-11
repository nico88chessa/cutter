import QtQuick 2.12
import QtQuick.Controls 2.12

import Cutter.CoreController 1.0 as CoreCtrl
import Cutter.ApplicationData 1.0 as ApplicationData
import QtQuick.Layouts 1.3

//import com.dv 1.0 // obbligato ad importarla in caso di uso ENUM


ApplicationWindow {

    width: 1024
    height: 768
    opacity: 1
    minimumWidth: 1024
    minimumHeight: 768

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

            delegate: Row {
                id: itemRow
                width: listView.width
                height: 36
                spacing: 10

                Text {
                    leftPadding: 10
                    rightPadding: leftPadding
                    id: textRow
                    text: pLabelRole /*+ " - " + CutterNS.NONE*/
                    font.pointSize: 14
                    verticalAlignment: Text.AlignVCenter
                    height: parent.height
                    width: parent.width

                    Rectangle {
                        id: textRect
                        anchors.fill: parent
                        anchors.left: parent.left
                        color: "transparent"
                        radius: 10
                    }

                    MouseArea {
                        id: mouseAreaRow
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: { listView.currentIndex = pKeyRole }
                        onEntered: { textRect.color = "#600000FF" }
                        onExited: { textRect.color = "transparent" }
                    }

                }

            }

            onCurrentIndexChanged: { stackLayout.currentIndex = listView.currentIndex }
            highlightFollowsCurrentItem: true
            focus: true
            highlight: Rectangle {
                id: hRect
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

            Item {
                id: iSetup
                anchors.fill: parent
                Setup {
                    id: setup
                }
            }

            Item {
                id: iStatus
                anchors.fill: parent

                SystemStatus {
                    id: systemStatus
                    anchors.fill: parent
                }
            }


        }




    }


}

/*##^## Designer {
    D{i:9;anchors_width:799}D{i:12;anchors_x:0;anchors_y:0}D{i:11;anchors_height:200;anchors_width:200}
}
 ##^##*/
