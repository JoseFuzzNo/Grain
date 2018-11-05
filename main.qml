import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import Qt.labs.settings 1.0

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

    Settings {
        property alias width: root.width
        property alias height: root.height
        property alias x: root.x
        property alias y: root.y
    }

    Granular.Granular {
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        grainR: Instrument.bufferR
        grainL: Instrument.bufferL
        progress: Instrument.playbackHeadPosition === NaN ? 0 : Instrument.playbackHeadPosition

        onStatusChanged: {
            switch ( message ) {
            case "master":
                Instrument.outputVolume = value;
                break;
            case "soundFile":
                Instrument.soundFile = value;
                break;
            case "tune":
                Instrument.tune = value;
                break;
            case "initPoint":
                Instrument.initPoint = value;
                break;
            case "grainSize":
                Instrument.grainSize = value;
                break;
            }

            console.log( message + " " + value )
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
}

/*##^## Designer {
    D{i:2;anchors_x:10;anchors_y:10}
}
 ##^##*/
