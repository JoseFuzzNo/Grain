import QtQuick 2.0
//import AudioControls 1.0 as Audio
import "../audiocontrols" as Audio

SubModule {
    id: root
    title: qsTr( "FILTER" )
    content: Row {
        Audio.Knob {
            id: highPassKnob
            decimalsOnKiloUnit: 1
            to: 20000
            decimals: 0
            from: 10
            label: "HP"
            units: "Hz"
            size: 30
            onValueChanged: {
                root.statusChanged( "hpCutoff", value );
            }
            color: mainColor
            curve: 6
            secondColor: secondColor
        }

        Audio.Knob {
            id: lowPassKnob
            value: 20000
            decimals: 0
            units: "Hz"
            label: "LP"
            from: 10
            to: 20000
            decimalsOnKiloUnit: 1
            size: 30
            onValueChanged: {
                root.statusChanged( "lpCutoff", value );
            }
            color: mainColor
            secondColor: secondColor
            curve: 6
        }
    }
}
