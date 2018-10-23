import QtQuick 2.0
import Qt.labs.calendar 1.0
import "../audiocontrols" as Audio

Module {
    id: root

    width: 420
    height: 184

    title: qsTr( "GRAIN" )
    //titleCheckEnabled: true

    property variant grain: []

    function cleanUrl( url ) {
        return url.replace(/(^\w+:|^)\/\//, '');
    }

    onTitleCheckedChanged: {
        statusChanged( "power", titleChecked );
    }

    icon: Image {
        source: "../img/grain.svg"
    }
    header1: Item {
    }
    header2: Item {
        Audio.Number2 {
            id: voicesNumber

            color: root.mainColor
            secondColor: root.backgroundColor
            label: qsTr( "VOICES:" )

            height: 18
            x: 125
            y: 1
           cornerShape: "square"

            stepSize: 0.05
            from: 1
            to: 4
            digits: 1

            onValueChanged: {
                root.statusChanged( "voices", value );
            }

        }
    }


    Audio.Knob {
        id: gainKnob
        x: 14
        y: 31
        label: "Gain"
        units: "dB"
        //decimals: 1
        from: 1
        to: 200
        curve: 5
        size: 30
        onValueChanged: {
            statusChanged( "gain", value );
        }
        color: root.mainColor
        secondColor: root.secondColor
    }

    Grain {
        id: grainSlider
        y: 31
        anchors.horizontalCenter: parent.horizontalCenter
        width: 287
        height: 55
        showValue: false
        stepSize: 0.01
        onValueChanged: {
            statusChanged( "initPoint", value );
        }
        onGrainSizeChanged: {
            statusChanged( "grainSize", grainSize );
        }

        color: mainColor
        secondColor: secondColor
        thirdColor: root.thirdColor
        grain: root.grain
        DropArea {
            anchors.fill: parent
            onDropped: {
                statusChanged( "soundFile", cleanUrl( drop.urls[0] ) );
            }
        }
    }

    Audio.Knob {
        id: masterKnob
        x: 366
        y: 31
        value: 0.5
        units: "dB"
        label: "Master"
        size: 30
        onValueChanged: {
            statusChanged( "master", value );
        }
        color: mainColor
        secondColor: secondColor
    }

    ADSR {
        x: 13
        y: 97

        mainColor: root.mainColor
        secondColor: root.secondColor
        thirdColor: root.thirdColor
        fourthColor: root.fourthColor

        editMode: root.editMode

        onStatusChanged: {
            root.statusChanged( message, value );
        }
    }

    Filter {
        x: 183
        y: 97

        mainColor: root.mainColor
        secondColor: root.secondColor
        thirdColor: root.thirdColor
        fourthColor: root.fourthColor

        editMode: root.editMode

        onStatusChanged: {
            root.statusChanged( message, value );
        }
    }

    Vibrato {
        x: 273
        y: 97

        mainColor: root.mainColor
        secondColor: root.secondColor
        thirdColor: root.thirdColor
        fourthColor: root.fourthColor

        editMode: root.editMode

        onStatusChanged: {
            root.statusChanged( message, value );
        }

    }

    Glide {
        x: 363
        y: 97

        mainColor: root.mainColor
        secondColor: root.secondColor
        thirdColor: root.thirdColor
        fourthColor: root.fourthColor

        editMode: root.editMode

        onStatusChanged: {
            root.statusChanged( message, value );
        }
    }
}
