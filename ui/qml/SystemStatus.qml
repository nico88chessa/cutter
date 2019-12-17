import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

import Cutter.SystemStatusController 1.0 as SystemStatusCtrl
import QtQuick.Window 2.10

Pane {

    Component.onCompleted: {
        SystemStatusCtrl.SystemStatusController.initQML();
    }

    GridLayout {

        id: gridLayout
        columns: 1
        anchors.fill: parent

        TabBar {
            id: tBar
            width: 240
            currentIndex: 2
            Layout.minimumHeight: 50
            Layout.fillWidth: true

            Component.onCompleted: {
                tBar.currentIndex = 0
            }

            TabButton {
                id: tButIO
                text: qsTr("IO")
            }

            TabButton {
                id: tButSystem
                text: qsTr("System")
            }

            TabButton {
                id: tButStatus
                text: qsTr("Status")
            }
        }

        StackLayout {
            id: stackLayout
            x: 63
            y: 94
            width: 100
            height: 100
            currentIndex: tBar.currentIndex
            Layout.fillHeight: true
            Layout.fillWidth: true

            Frame {
                background: Rectangle {
                    border.width: 0
                }

                id: frIO
                width: 200
                height: 200
                padding: 0
                clip: true

                GridLayout {
                    id: glIO
                    anchors.rightMargin: 5
                    anchors.leftMargin: 5
                    anchors.bottomMargin: 5
                    anchors.topMargin: 5
                    columns: 2
                    columnSpacing: 80
                    rowSpacing: 0
                    anchors.fill: parent

                    Item {
                        id: iAuxGPI1
                        Layout.fillWidth: true
                        clip: true
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50

                        GridLayout {
                            id: glAuxGPI1
                            height: 40
                            clip: true
                            anchors.fill: parent

                            Label {
                                id: lAuxGPI1
                                text: qsTr("Aux GPI1")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPI1
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPI1 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPI2
                        Layout.fillWidth: true
                        clip: true
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50

                        GridLayout {
                            id: glAuxGPI2
                            height: 40
                            clip: true
                            anchors.fill: parent

                            Label {
                                id: lAuxGPI2
                                text: qsTr("Aux GPI2")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPI2
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPI2 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPI3
                        clip: true
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxGPI3
                            height: 40
                            clip: true
                            anchors.fill: parent

                            Label {
                                id: lAuxGPI3
                                text: qsTr("Aux GPI3")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPI3
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPI3 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPI4
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxGPI4
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lAuxGPI4
                                text: qsTr("Aux GPI4")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPI4
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPI4 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxStart
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxStart
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lAuxStart
                                text: qsTr("Aux Start")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxStart
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxStart ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iStart
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glStart
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lStart
                                text: qsTr("Start")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectStart
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pStart ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iInterlock1
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glInterlock1
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lInterlock1
                                text: qsTr("Interlock 1")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectInterlock1
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pInterlock1 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iInterlock2
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glInterlock2
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lInterlock2
                                text: qsTr("Interlock 2")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectInterlock2
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pInterlock2 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iInterlock3
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glInterlock3
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lInterlock3
                                text: qsTr("Interlock 3")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectInterlock3
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pInterlock3 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iInterlock4
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glInterlock4
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lInterlock4
                                text: qsTr("Interlock 4")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectInterlock4
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pInterlock4 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPO1
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxGPO1
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lAuxGPO1
                                text: qsTr("Aux GPO1")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPO1
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPO1 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPO2
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxGPO2
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lAuxGPO2
                                text: qsTr("Aux GPO2")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPO2
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPO2 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPO3
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxGPO3
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lAuxGPO3
                                text: qsTr("Aux GPO3")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPO3
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPO3 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iAuxGPO4
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAuxGPO4
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lAuxGPO4
                                text: qsTr("Aux GPO4")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectAuxGPO4
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pAuxGPO4 ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iJobactive
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glJobactive
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lJobactive
                                text: qsTr("Job Active")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectJobactive
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pJobActive ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iErrorNready
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glErrorNready
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lErrorNready
                                text: qsTr("Error/NotReady")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectErrorNready
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pErrorNready ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iBusy
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glBusy
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lBusy
                                text: qsTr("Busy")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectBusy
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pBusy ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: iLasing
                        Layout.rightMargin: 50
                        Layout.leftMargin: 50
                        Layout.preferredHeight: 50
                        Layout.minimumHeight: 50
                        Layout.fillWidth: true

                        GridLayout {
                            id: glLasing
                            height: 40
                            anchors.fill: parent

                            Label {
                                id: lLasing
                                text: qsTr("Lasing")
                                Layout.fillWidth: true
                            }

                            Rectangle {
                                id: rectLasing
                                width: 30
                                height: 30
                                color: SystemStatusCtrl.SystemStatusController.pData.pLasing ? "#03a9f4" : "#00000000"
                                radius: 15
                                border.width: 2
                            }

                        }

                    }

                    Item {
                        id: element1
                        width: 0
                        height: 0
                        Layout.fillWidth: true
                        Layout.columnSpan: 2
                        Layout.fillHeight: true
                    }


                }
            }


            Frame {
                background: Rectangle {
                    border.width: 0
                }
                id: frSystem
                width: 200
                height: 200
                padding: 0
                clip: true

                GridLayout {
                    id: glStatus
                    rowSpacing: 0
                    columnSpacing: 10
                    columns: 2
                    anchors.fill: parent

                    Item {
                        id: iMSN
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glMSN
                            anchors.fill: parent

                            Label {
                                id: lMSN
                                text: qsTr("MSN")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfMSN
                                text: SystemStatusCtrl.SystemStatusController.pData.pMsn
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iPVer
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glPVer
                            anchors.fill: parent

                            Label {
                                id: lPVer
                                text: qsTr("PVer")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfPVer
                                text: SystemStatusCtrl.SystemStatusController.pData.pPVer
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iAVer
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glAVer
                            anchors.fill: parent

                            Label {
                                id: lAVer
                                text: qsTr("AVer")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfAVer
                                text: SystemStatusCtrl.SystemStatusController.pData.pAVer
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iObjExtVer
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glObjExtVer
                            anchors.fill: parent

                            Label {
                                id: lObjExtVer
                                text: qsTr("ObjExtVer")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfObjExtVer
                                text: SystemStatusCtrl.SystemStatusController.pData.pObjextVer
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iFPGAFirmVer
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glFPGAFirmVer
                            anchors.fill: parent

                            Label {
                                id: lFPGAFirmVer
                                text: qsTr("FPGAFirmVer")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfFPGAFirmVer
                                text: SystemStatusCtrl.SystemStatusController.pData.pFpgaFirmVer
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iStateCode
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glStateCode
                            anchors.fill: parent

                            Label {
                                id: lStateCode
                                text: qsTr("StateCode")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfStateCode
                                text: SystemStatusCtrl.SystemStatusController.pData.pStateCode
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iLastError
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glLastError
                            anchors.fill: parent

                            Label {
                                id: lLastError
                                text: qsTr("LastError")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfLastError
                                text: SystemStatusCtrl.SystemStatusController.pData.pLastError
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iFreeTempStorage
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glFreeTempStorage
                            anchors.fill: parent

                            Label {
                                id: lFreeTempStorage
                                text: qsTr("FreeTempStorage")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfFreeTempStorage
                                text: SystemStatusCtrl.SystemStatusController.pData.pFreeTempStorage
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iPermStoragePath
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glPermStoragePath
                            anchors.fill: parent

                            Label {
                                id: lPermStoragePath
                                text: qsTr("PermStoragePath")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfPermStoragePath
                                text: SystemStatusCtrl.SystemStatusController.pData.pPermStoragePath
                                Layout.preferredWidth: 160
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                            }
                        }
                    }

                    Item {
                        id: iFreePermStorage
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glFreePermStorage
                            anchors.fill: parent

                            Label {
                                id: lFreePermStorage
                                text: qsTr("FreePermStorage")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfFreePermStorage
                                text: SystemStatusCtrl.SystemStatusController.pData.pFreePermStorage
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iFreeUSBStorage
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glFreeUSBStorage
                            anchors.fill: parent

                            Label {
                                id: lFreeUSBStorage
                                text: qsTr("FreeUSBStorage")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfFreeUSBStorage
                                text: SystemStatusCtrl.SystemStatusController.pData.pFreeUsbStorage
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iMAC
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glMAC
                            anchors.fill: parent

                            Label {
                                id: lMAC
                                text: qsTr("MAC")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfMAC
                                text: SystemStatusCtrl.SystemStatusController.pData.pMac
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iNetMask
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glNetMask
                            anchors.fill: parent

                            Label {
                                id: lNetMask
                                text: qsTr("NetMask")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfNetMask
                                text: SystemStatusCtrl.SystemStatusController.pData.pNetmask
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iNetAssign
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glNetAssign
                            anchors.fill: parent

                            Label {
                                id: lNetAssign
                                text: qsTr("NetAssign")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfNetAssign
                                text: SystemStatusCtrl.SystemStatusController.pData.pNetassign
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iIP
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glIP
                            anchors.fill: parent

                            Label {
                                id: lIP
                                text: qsTr("IP")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfIP
                                text: SystemStatusCtrl.SystemStatusController.pData.pIp
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iConnectIP
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glConnectIP
                            anchors.fill: parent

                            Label {
                                id: lConnectIP
                                text: qsTr("ConnectIP")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfConnectIP
                                text: SystemStatusCtrl.SystemStatusController.pData.pConnectIp
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iFriendlyName
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glFriendlyName
                            anchors.fill: parent

                            Label {
                                id: lFriendlyName
                                text: qsTr("FriendlyName")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfFriendlyName
                                text: SystemStatusCtrl.SystemStatusController.pData.pFriendlyName
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iConnectJob
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glConnectJob
                            anchors.fill: parent

                            Label {
                                id: lConnectJob
                                text: qsTr("ConnectJob")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfConnectJob
                                text: SystemStatusCtrl.SystemStatusController.pData.pConnectJob
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iPort
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glPort
                            anchors.fill: parent

                            Label {
                                id: lPort
                                text: qsTr("Port")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfPort
                                text: SystemStatusCtrl.SystemStatusController.pData.pPort
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iHSN
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glHSN
                            anchors.fill: parent

                            Label {
                                id: lHSN
                                text: qsTr("HSN")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfHSN
                                text: SystemStatusCtrl.SystemStatusController.pData.pHsn
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }



                    Item {
                        id: element3
                        width: 200
                        height: 200
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                    }

                }
            }
            Frame {
                background: Rectangle {
                    border.width: 0
                }
                id: frStatus
                width: 200
                height: 200
                Layout.fillHeight: true
                Layout.fillWidth: true
                padding: 0
                clip: true

                GridLayout {
                    id: glSystem
                    columns: 2
                    columnSpacing: 10
                    rowSpacing: 0
                    anchors.fill: parent
                    clip: true

                    Item {
                        id: iXPosAck
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glXPosAck
                            anchors.fill: parent

                            Label {
                                id: lXPosAck
                                text: qsTr("XPosAck")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfXPosAck
                                text: SystemStatusCtrl.SystemStatusController.pData.pXPosAck ? "TRUE" : "FALSE"
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iYPosAck
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glYPosAck
                            anchors.fill: parent

                            Label {
                                id: lYPosAck
                                text: qsTr("YPosAck")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfYPosAck
                                text: SystemStatusCtrl.SystemStatusController.pData.pYPosAck ? "TRUE" : "FALSE"
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iXpos
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glXpos
                            anchors.fill: parent

                            Label {
                                id: lXpos
                                text: qsTr("Xpos")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfXpos
                                text: SystemStatusCtrl.SystemStatusController.pData.pXPos
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iYpos
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glYpos
                            anchors.fill: parent

                            Label {
                                id: lYpos
                                text: qsTr("Ypos")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfYpos
                                text: SystemStatusCtrl.SystemStatusController.pData.pYPos
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iXActPos
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glXActPos
                            anchors.fill: parent

                            Label {
                                id: lXActPos
                                text: qsTr("XActPos")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfXActPos
                                text: SystemStatusCtrl.SystemStatusController.pData.pXActPos
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iYActPos
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glYActPos
                            anchors.fill: parent

                            Label {
                                id: lYActPos
                                text: qsTr("YActPos")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfYActPos
                                text: SystemStatusCtrl.SystemStatusController.pData.pYActPos
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iXTemp
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glXTemp
                            anchors.fill: parent

                            Label {
                                id: lXTemp
                                text: qsTr("XTemp")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfXTemp
                                text: SystemStatusCtrl.SystemStatusController.pData.pXTemp ? "TRUE" : "FALSE"
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iYTemp
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glYTemp
                            anchors.fill: parent

                            Label {
                                id: lYTemp
                                text: qsTr("YTemp")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfYTemp
                                text: SystemStatusCtrl.SystemStatusController.pData.pYTemp ? "TRUE" : "FALSE"
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iContrlTemp
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glContrlTemp
                            anchors.fill: parent

                            Label {
                                id: lContrlTemp
                                text: qsTr("ContrlTemp")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfContrlTemp
                                text: SystemStatusCtrl.SystemStatusController.pData.pContrlTemp
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iXStatus
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glXStatus
                            anchors.fill: parent

                            Label {
                                id: lXStatus
                                text: qsTr("XStatus")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfXStatus
                                text: SystemStatusCtrl.SystemStatusController.pData.pXStatus.toString(16)
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iYStatus
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glYStatus
                            anchors.fill: parent

                            Label {
                                id: lYStatus
                                text: qsTr("YStatus")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfYStatus
                                text: SystemStatusCtrl.SystemStatusController.pData.pYStatus.toString(16)
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iXPower
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glXPower
                            anchors.fill: parent

                            Label {
                                id: lXPower
                                text: qsTr("XPower")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfXPower
                                text: SystemStatusCtrl.SystemStatusController.pData.pXPower ? "TRUE" : "FALSE"
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iYPower
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glYPower
                            anchors.fill: parent

                            Label {
                                id: lYPower
                                text: qsTr("YPower")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfYPower
                                text: SystemStatusCtrl.SystemStatusController.pData.pYPower ? "TRUE" : "FALSE"
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iInterlock
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glInterlock
                            anchors.fill: parent

                            Label {
                                id: lInterlock
                                text: qsTr("Interlock")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfInterlock
                                text: SystemStatusCtrl.SystemStatusController.pData.pInterlock.toString(16)
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iCurrentDIO
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glCurrentDIO
                            anchors.fill: parent

                            Label {
                                id: lCurrentDIO
                                text: qsTr("CurrentDIO")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfCurrentDIO
                                text: SystemStatusCtrl.SystemStatusController.pData.pCurrentDIO.toString(16)
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iJobMarker
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glJobMarker
                            anchors.fill: parent

                            Label {
                                id: lJobMarker
                                text: qsTr("JobMarker")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfJobMarker
                                text: SystemStatusCtrl.SystemStatusController.pData.pJobMarker
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }
                    }

                    Item {
                        id: iJobDataCntr
                        width: 200
                        height: 50
                        clip: true
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20
                        Layout.fillWidth: true

                        GridLayout {
                            id: glJobDataCntr
                            anchors.fill: parent

                            Label {
                                id: lJobDataCntr
                                text: qsTr("JobDataCntr")
                                Layout.fillWidth: true
                            }

                            TextField {
                                id: tfJobDataCntr
                                text: SystemStatusCtrl.SystemStatusController.pData.pJobDataCntr
                                horizontalAlignment: Text.AlignRight
                                readOnly: true
                                Layout.preferredWidth: 160
                            }
                        }

                    }

                    Item {
                        id: element2
                        width: 0
                        height: 0
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        Layout.columnSpan: 2
                    }

                }
            }
        }

    }


}








/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
