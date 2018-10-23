import QtQuick 2.0
//import AudioControls 1.0 as Audio
import "../audiocontrols" as Audio

SubModule {
    id: root
    title: "VIBRATO"
    content: Row {
        Audio.Knob {
            id: vibratoDepthKnob
            value: 0
            units: "%"
            from: 0
            to: 0.3
            label: "Depth"
            size: 30
            onValueChanged: {
                root.statusChanged( "vibratoDepth", value );
            }
            color: mainColor
            secondColor: secondColor
        }

        Audio.Knob {
            id: vibratoSpeedKnob
            value: 1
            units: "Hz"
            decimals: 1
            label: "Speed"
            to: 10
            size: 30
            onValueChanged: {
                root.statusChanged( "vibratoSpeed", value );
            }
            color: mainColor
            secondColor: secondColor
        }
    }
}
