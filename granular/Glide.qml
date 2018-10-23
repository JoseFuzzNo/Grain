import QtQuick 2.0
//import AudioControls 1.0 as Audio
import "../audiocontrols" as Audio

SubModule {
    id: root
    title: qsTr( "GLIDE" )

    content: Row {
        Audio.Knob {
            id: glideKnob
            from: 0
            decimals: 0
            label: " "
            units: "ms"
            decimalsOnKiloUnit: 1
            to: 2000
            size: 30
            onValueChanged: {
                root.statusChanged( "portamento", value );
            }
            color: mainColor
            secondColor: secondColor
        }
    }
}
