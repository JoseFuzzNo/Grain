import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

import "audiocontrols" as AudioControls


Window {
    id: root

    visible: true
    width: 800
    height: 300
    color: "#333333"

    title: qsTr("Grain")
    ColumnLayout {
        anchors.centerIn: parent
        AudioControls.Knob {
            id: knob
            size: 40
            decimals: 1
            units: "dB"
            curve: 1
            to: 10

            value: 1
            onValueChanged: Instrument.outputVolume = value
        }

    }

    AudioControls.Slider {
        mouseEnabled: false
        value: Instrument.cpuLoad
        from: 0
        to: 1
        label: "CPU:"
        units: "%"
        decimals: 1

        anchors.bottom: parent.bottom
        anchors.right: parent.right
    }


}
