import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

import "audiocontrols" as AudioControls
import "granular" as Granular

Window {
    id: root
    visible: true
    width: 440
    height: 300
    color: "#333333"
    title: qsTr("Grain")

    minimumWidth: 440
    minimumHeight:  250

    Granular.Granular {
        x: 10
        y: 10

        grain: Instrument.grainBuffer

        onStatusChanged: {
            switch ( message ) {
            case "master":
                Instrument.outputVolume = value;
                break;
            case "soundFile":
                Instrument.soundFile = value;
                break;
            }

            //console.log( message + " " + value )
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
        anchors.left: parent.left
        anchors.bottomMargin: 10
        anchors.leftMargin: 10

        color: "orange"
        secondColor: "#444444"
        thirdColor: "yellow"
    }
    AudioControls.Slider {
        mouseEnabled: false
        value: Instrument.initPoint
        from: 0
        to: 1
        label: "Posicion:"
        units: "%"
        decimals: 1

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.bottomMargin: 10
        anchors.rightMargin: 10

        color: "orange"
        secondColor: "#444444"
        thirdColor: "yellow"
    }

}
