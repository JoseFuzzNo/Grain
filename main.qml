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

        onStatusChanged: {
            if ( message === "master" ) {
                Instrument.outputVolume = value;
            }

            console.log( message + " " + value.toFixed( 2 ) )
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
