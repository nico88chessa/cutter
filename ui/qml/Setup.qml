import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

import Cutter.SetupController 1.0 as SetCtrl

Pane {
    id: setupItem
    //    width: 640
    implicitWidth: parent.width
    height: parent.height

    Dialog {
        id: operationDialog
        standardButtons: Dialog.Ok
        width: 500
        height: 200
        modal: true
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        Text {
            id: operationDialogText
            anchors.centerIn: parent
            text: ""
            font.pointSize: 12
        }

    }

    Connections {
        target: SetCtrl.SetupController
        onNotifyDialog: {
            operationDialogText.text = msg
            operationDialog.visible = true
        }
    }

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
                    to: 90 * scale
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
                    from: -45 * scale
                    to: 45 * scale
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
                    from: -45 * scale
                    to: 45 * scale
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
                color: "#00000000"
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
                        target: tfJumpSpeed
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


                Label {
                    id: label8
                    text: qsTr("Mark Delay [us]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfMarkDelay
                    Layout.minimumHeight: 40
                    Layout.fillWidth: true
                    from: -15000
                    to: 15000
                    editable: true
                    down.indicator: Item { }
                    up.indicator: Item { }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserMarkDelay = tfMarkDelay.value;
                    }

                    Binding {
                        target: tfMarkDelay
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserMarkDelay
                    }
                }

                Label {
                    id: label9
                    text: qsTr("Jump Delay [us]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfJumpDelay
                    Layout.minimumHeight: 40
                    Layout.fillWidth: true
                    from: -15000
                    to: 15000
                    editable: true
                    down.indicator: Item { }
                    up.indicator: Item { }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserJumpDelay = tfJumpDelay.value;
                    }

                    Binding {
                        target: tfJumpDelay
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserJumpDelay
                    }
                }

                Label {
                    id: label10
                    text: qsTr("Poly Delay [us]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfPolyDelay
                    Layout.minimumHeight: 40
                    Layout.fillWidth: true
                    from: -15000
                    to: 15000
                    editable: true
                    down.indicator: Item { }
                    up.indicator: Item { }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserPolyDelay = tfPolyDelay.value;
                    }

                    Binding {
                        target: tfPolyDelay
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserPolyDelay
                    }
                }

                Label {
                    id: label11
                    text: qsTr("On Delay [us]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfOnDelay
                    Layout.minimumHeight: 40
                    Layout.fillWidth: true
                    from: -15000
                    to: 15000
                    editable: true
                    down.indicator: Item { }
                    up.indicator: Item { }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserOnDelay = tfOnDelay.value;
                    }

                    Binding {
                        target: tfOnDelay
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserOnDelay
                    }
                }

                Label {
                    id: label12
                    text: qsTr("Off Delay [us]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfOffDelay
                    Layout.minimumHeight: 40
                    Layout.fillWidth: true
                    from: -15000
                    to: 15000
                    editable: true
                    down.indicator: Item { }
                    up.indicator: Item { }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserOffDelay = tfOffDelay.value;
                    }

                    Binding {
                        target: tfOffDelay
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserOffDelay
                    }
                }


                Label {
                    id: label13
                    text: qsTr("Pipeline Delay [us]")
                    Layout.minimumWidth: 100
                }

                SpinBox {
                    id: tfPipelineDelay
                    Layout.minimumHeight: 40
                    Layout.fillWidth: true
                    from: -15000
                    to: 15000
                    editable: true
                    down.indicator: Item { }
                    up.indicator: Item { }

                    onValueModified: {
                        SetCtrl.SetupController.pData.pLaserPipelineDelay = tfPipelineDelay.value;
                    }

                    Binding {
                        target: tfPipelineDelay
                        property: "value"
                        value: SetCtrl.SetupController.pData.pLaserPipelineDelay
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
                color: "#00000000"
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
                color: "#00000000"
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
                font.pointSize: 10
                rightPadding: 16
                leftPadding: 16
                Layout.minimumWidth: 80
                Layout.minimumHeight: 36
                enabled: SetCtrl.SetupController.pData.pIsSendButtonEnabled

                contentItem: Text {
                    text: bSend.text
                    font: bSend.font
                    color: "#FFFFFF"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    color: "#455a64"
                    opacity: bSend.enabled ? 1.00 : 0.38
                    radius: 4
                }
            }

        }

    }

}

