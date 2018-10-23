import QtQuick 2.0
//import AudioControls 1.0 as Audio
import "../audiocontrols" as Audio

SubModule {
    id: root
    title: qsTr( "ADSR" )

    content: Row {
        Audio.Knob {
            id: attackKnob
            decimalsOnKiloUnit: 1
            units: "ms"
            decimals: 0
            label: "Attack"
            from: 0
            to: 2000
            size: 30
            onValueChanged: {
                root.statusChanged( "attack", value );
            }
            color: mainColor
            secondColor: secondColor
        }

        Audio.Knob {
            id: decayKnob
            decimalsOnKiloUnit: 1
            decimals: 0
            from: 0
            label: "Decay"
            units: "ms"
            to: 2000
            size: 30
            onValueChanged: {
                root.statusChanged( "decay", value );
            }
            color: mainColor
            secondColor: secondColor
        }

        Audio.Knob {
            id: sustainKnob
            value: 1
            decimals: 0
            units: "%"
            label: "Sustain"
            size: 30
            onValueChanged: {
                root.statusChanged( "sustain", value );
            }
            color: mainColor
            secondColor: secondColor
        }

        Audio.Knob {
            id: releaseKnob
            decimalsOnKiloUnit: 1
            decimals: 0
            from: 0
            label: "Release"
            units: "ms"
            to: 10000
            size: 30
            onValueChanged: {
                root.statusChanged( "release", value );
            }
            color: mainColor
            secondColor: secondColor
        }
    }
}
