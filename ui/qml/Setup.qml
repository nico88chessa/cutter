import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

import Cutter.SetupController 1.0 as SetCtrl

Pane {
    id: setupItem
    //    width: 640
    implicitWidth: parent.width
    height: parent.height

    GridLayout {
        id: glSetup
        width: 6
        anchors.bottomMargin: 8
        anchors.topMargin: 8
        anchors.rightMargin: 8
        anchors.leftMargin: 8
        columnSpacing: 10
        rowSpacing: 10
        anchors.fill: parent
        columns: 2

        GroupBox {
            id: gbCutProperties
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            padding: 1
            rightPadding: 1
            leftPadding: 1
            bottomPadding: 1
            topPadding: 30
            Layout.fillWidth: true
            title: qsTr("Cut properties")
            implicitWidth: parent.width / glSetup.columns
            font.pointSize: 10

            GridLayout {
                id: gridLayout
                anchors.fill: parent
                columns: 2
                visible: true

                Label {
                    id: label
                    text: qsTr("Cut Height [mm]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    property int scale: 100
                    property int decimals: 2

                    id: tfCutHeight
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 0 * scale
                    to: 100 * scale
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    textFromValue: function(value, locale) {
                        return Number(value / scale).toLocaleString(locale, 'f', tfCutHeight.decimals)
                    }

                    valueFromText: function(text, locale) {
                        return Number.fromLocaleString(locale, text) * scale
                    }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pCutHeight = tfCutHeight.value / tfCutHeight.scale;
                    }

                    Binding {
                        target: tfCutHeight
                        property: "value"
                        value: { SetCtrl.SetupController.pData.pCutHeight * tfCutHeight.scale }
                    }

                }



                Label {
                    id: label1
                    text: qsTr("Start X [mm]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    property int scale: 100
                    property int decimals: 2

                    id: tfCutStartX
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 0 * scale
                    to: 100 * scale
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    textFromValue: function(value, locale) {
                        return Number(value / scale).toLocaleString(locale, 'f', tfCutStartX.decimals)
                    }

                    valueFromText: function(text, locale) {
                        return Number.fromLocaleString(locale, text) * scale
                    }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pXStart = tfCutStartX.value / tfCutStartX.scale;
                    }

                    Binding {
                        target: tfCutStartX
                        property: "value"
                        value: { SetCtrl.SetupController.pData.pXStart * tfCutStartX.scale }
                    }

                }

                Label {
                    id: label7
                    text: qsTr("Start Y [mm]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    property int scale: 100
                    property int decimals: 2

                    id: tfCutStartY
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 0 * scale
                    to: 100 * scale
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    textFromValue: function(value, locale) {
                        return Number(value / scale).toLocaleString(locale, 'f', tfCutStartY.decimals)
                    }

                    valueFromText: function(text, locale) {
                        return Number.fromLocaleString(locale, text) * scale
                    }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pYStart = tfCutStartY.value / tfCutStartY.scale;
                    }

                    Binding {
                        target: tfCutStartY
                        property: "value"
                        value: { SetCtrl.SetupController.pData.pYStart * tfCutStartY.scale }
                    }

                }


                Item {
                    id: element1
                    width: 0
                    height: 0
                    Layout.fillHeight: true
                }

            }
            background: Rectangle {
                border.width: 0
                color: "transparent"
            }

        }

        GroupBox {
            id: gbLaserProperties
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            padding: 1
            rightPadding: 1
            leftPadding: 1
            bottomPadding: 1
            topPadding: 30
            Layout.fillWidth: true
            font.pointSize: 10
            implicitWidth: parent.width / glSetup.columns
            title: qsTr("Laser properties")

            GridLayout {
                id: gridLayout1
                columns: 2
                anchors.fill: parent

                Label {
                    id: label2
                    text: qsTr("Laser Power [%]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfLaserPower
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 0
                    to: 100
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserPower = tfLaserPower.value;
                    }

                    Binding {
                        target: tfLaserPower
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserPower
                    }
                }

                Label {
                    id: label3
                    text: qsTr("Laser Duty [%]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfLaserDuty
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 0
                    to: 100
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserDuty = tfLaserDuty.value;
                    }

                    Binding {
                        target: tfLaserDuty
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserDuty
                    }
                }

                Label {
                    id: label4
                    text: qsTr("Jump Speed [mm/s]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfJumpSpeed
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 1
                    to: 12000
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserJumpSpeed = tfJumpSpeed.value;
                    }

                    Binding {
                        target: tfCutHeight
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserJumpSpeed
                    }

                }

                Label {
                    id: label5
                    text: qsTr("Mark Speed [mm/s]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfMarkSpeed
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 1
                    to: 15000
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserMarkSpeed = tfMarkSpeed.value;
                    }

                    Binding {
                        target: tfMarkSpeed
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserMarkSpeed
                    }

                }

                Item {
                    id: element2
                    width: 1
                    height: 1
                    Layout.fillHeight: true
                }
            }
            background: Rectangle {
                border.width: 0
                color: "transparent"
            }
        }

        GroupBox {
            id: gbOtherProperties
            Layout.columnSpan: 1
            padding: 1
            rightPadding: 1
            leftPadding: 1
            bottomPadding: 1
            topPadding: 30
            Layout.fillHeight: true
            Layout.fillWidth: true
            font.pointSize: 10
            title: qsTr("Others")

            GridLayout {
                id: gridLayout2
                columns: 2
                anchors.fill: parent

                Label {
                    id: label6
                    text: qsTr("Encoder Pulses")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfEncoderPulses
                    Layout.fillWidth: true
                    Layout.minimumHeight: 40
                    from: 0
                    to: 100000
                    editable: true
                    down.indicator: Item {}
                    up.indicator: Item {}

                    onValueModified: {
                        SetCtrl.SetupController.pData.pEncoderPulses = tfEncoderPulses.value;
                    }

                    Binding {
                        target: tfEncoderPulses
                        property: "value"
                        value: SetCtrl.SetupController.pData.pEncoderPulses
                    }
                }


                Item {
                    id: element3
                    width: 1
                    height: 1
                    Layout.fillHeight: true
                }

            }

            background: Rectangle {
                border.width: 0
                color: "transparent"
            }
        }

        Item {
            id: element
            Layout.fillHeight: true
        }

        RowLayout {
            id: rowLayout
            width: 100
            height: 30
            Layout.columnSpan: 2

            Item {
                id: element4
                width: 0
                height: 0
                Layout.fillWidth: true
            }

            Button {
                id: bSend
                text: qsTr("Send Parameters")
                onClicked: SetCtrl.SetupController.sendData()
            }

        }

    }

}

