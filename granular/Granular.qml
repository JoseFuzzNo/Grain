import QtQuick 2.0
import Qt.labs.calendar 1.0
import "../audiocontrols" as Audio

Item {
    id: root

    width: 420
    height: 184

    // COLORS
    property color mainColor: "orange"
    property color secondColor: "#444444"
    property color thirdColor: "yellow"
    property color fourthColor: "#393939"
    property color backgroundColor: "#333333"

    property var grainL: []
    property var grainR: []
    property double initPoint: 0
    property double progress: 0

    // SIGNALS
    signal statusChanged( var message, var value )


    function cleanUrl( url ) {
        return url.replace(/(^\w+:|^)\/\//, '');
    }

    /*Audio.Number2 {
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

    }*/

    Rectangle {
        id: background
        color: root.backgroundColor
        border.color: root.secondColor
        radius: 2
        anchors.fill: parent

    }

    Audio.Knob {
        id: tuneKnob
        y: 31
        anchors.left: parent.left
        anchors.leftMargin: 14
        label: "Tune"
        units: "ct"
        //decimals: 1
        from: -12
        to: 12
        steps: 24
        curve: 0
        mode: "centered"
        size: 30
        onValueChanged: {
            statusChanged( "tune", value );
        }
        color: root.mainColor
        secondColor: root.secondColor
    }

    Grain {
        id: grainSlider
        //width: 287
        showValue: false
        stepSize: 0.01
        value: initPoint
        progress: root.progress
        onValueChanged: {
            statusChanged( "initPoint", value );
        }
        onGrainSizeChanged: {
            statusChanged( "grainSize", grainSize );
        }

        color: mainColor
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 98
        anchors.top: parent.top
        anchors.topMargin: 11
        anchors.left: parent.left
        anchors.leftMargin: 67
        anchors.right: parent.right
        anchors.rightMargin: 67
        secondColor: secondColor
        thirdColor: root.thirdColor
        grainR: root.grainR
        grainL: root.grainL
        DropArea {
            anchors.fill: parent
            onDropped: {
                statusChanged( "soundFile", cleanUrl( drop.urls[0] ) );
            }
        }
    }

    Audio.Knob {
        id: masterKnob
        y: 31
        anchors.right: parent.right
        anchors.rightMargin: 14
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

    Row {
        y: 97
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 12
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        ADSR {

            mainColor: root.mainColor
            secondColor: root.secondColor
            thirdColor: root.thirdColor
            fourthColor: root.fourthColor

            onStatusChanged: {
                root.statusChanged( message, value );
            }
        }

        Filter {
            mainColor: root.mainColor
            secondColor: root.secondColor
            thirdColor: root.thirdColor
            fourthColor: root.fourthColor

            onStatusChanged: {
                root.statusChanged( message, value );
            }
        }

        Vibrato {
            mainColor: root.mainColor
            secondColor: root.secondColor
            thirdColor: root.thirdColor
            fourthColor: root.fourthColor

            onStatusChanged: {
                root.statusChanged( message, value );
            }

        }

        Glide {
            mainColor: root.mainColor
            secondColor: root.secondColor
            thirdColor: root.thirdColor
            fourthColor: root.fourthColor

            onStatusChanged: {
                root.statusChanged( message, value );
            }
        }

    }
}

/*##^## Designer {
    D{i:21;anchors_height:75;anchors_y:11}
}
 ##^##*/
