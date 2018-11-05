import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0
import "../audiocontrols" as AudioControls

Item {
    id: root

    property color color: "#aabbdd"
    property color secondColor: "#444444"
    property color thirdColor: "yellow"
    property double from: 0
    property double to: 1
    property double value: 0
    property double showedValue: value
    property double stepSize: 1
    property string label: ""
    property bool showValue: false
    property bool showWaveform: true
    property string units: ""
    property int decimals: 0
    property bool mouseEnabled: true
    property double grainSize: 0    // De 0 a 1 en %
    property double showedGrainSize: grainSize
    property var grainL: []
    property var grainR: []
    property double progress: 0

    onGrainSizeChanged: {
        // Para prevenir que el punto final del grano vaya fuera del slider
        if ( value > to * ( 1 - grainSize ) )
            value = to * ( 1 - grainSize );
    }

    width: 150
    height: 20

    Component.onCompleted: {
        if ( value < from )
            value = from;
        else if ( value > to )
            value = from;
    }

    Behavior on showedValue {
        PropertyAnimation {
            duration: 100
        }
    }
    Behavior on showedGrainSize {
        PropertyAnimation {
            duration: 100
        }
    }

    Item {
        id: grainItem
        anchors.fill: parent
        Rectangle {
            id: background
            anchors.fill: parent
            color: secondColor
            //border.color: "#2b2b2b"
            radius: 1
        }

        Rectangle {
            id: contentItem

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: {
                var adjustedMargin = root.width * ( root.showedValue  - from ) / ( to - from );
                if ( adjustedMargin >= root.width )
                    return root.width - 1;
                return adjustedMargin;
            }
            width: {
                var adjustedWidth = showedGrainSize * parent.width;
                if ( adjustedWidth < 1 )
                    return 1;
                if ( anchors.leftMargin + adjustedWidth > root.width ) {
                    return root.width - anchors.leftMargin
                }
                return adjustedWidth;
            }
            //height: root.height * ( root.value  - from ) / ( to - from )

            color: root.color
            radius: 1
        }

        Waveform {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height / 2
            wave: root.grainL
            color: root.thirdColor
        }
        Waveform {
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height / 2
            wave: root.grainR
            color: root.thirdColor
        }

        Rectangle {
            id: progressBar
            opacity: 0.4
            color: fourthColor
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: parent.height / 20
            Rectangle {
                color: root.thirdColor
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.top: parent.top
                width: parent.width * root.progress
            }

        }

        MouseArea {
            id: clickArea
            anchors.fill: parent
            onWheel: {
                if ( mouseEnabled ) {
                    var auxValue = value += ( wheel.angleDelta.y / 120 ) * stepSize
                    if ( auxValue > to * ( 1 - grainSize ) )
                        value = to * ( 1 - grainSize )
                    else if ( auxValue < from )
                        value = from
                    else
                        value = auxValue
                }

            }
            onPressed: {
                if ( mouseEnabled ) {
                    var auxValue = ( mouse.x / width - grainSize / 2 ) * ( to - from ) + from;
                    if ( auxValue > to * ( 1 - grainSize ) )
                        value = to * ( 1 - grainSize );
                    else if ( auxValue < from )
                        value = from;
                    else
                        value = auxValue;
                }
            }
            onPositionChanged: {
                if ( mouseEnabled ) {
                    var auxValue = ( mouse.x / width - grainSize / 2 ) * ( to - from ) + from;
                    if ( auxValue > to * ( 1 - grainSize ) )
                        value = to * ( 1 - grainSize );
                    else if ( auxValue < from )
                        value = from;
                    else
                        value = auxValue;
                }
            }
        }

        MouseArea {
            z: -1
            id: hoverArea
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.SizeHorCursor
            property bool hovered: false
            onEntered: {
                hovered = true
            }
            onExited: {
                hovered = false
            }
        }


        MouseArea {
            width: 10
            height: parent.height
            x: contentItem.x - 5
            cursorShape: Qt.SizeHorCursor
            property int mouseInit: 0

            onClicked: {
                mouseInit = mouseX
            }
            onPositionChanged: {
                if ( root.mouseEnabled ) {
                    var dx = mouseX - mouseInit
                    var auxValue = value + ( ( dx / root.width ) * ( root.to - root.from ) + root.from );
                    if ( auxValue > to * ( 1 - grainSize ) )
                        auxValue = to * ( 1 - grainSize );
                    else if ( auxValue < from )
                        auxValue = from;

                    grainSize = grainSize + ( value - auxValue - root.from ) / ( root.to - root.from );
                    value = auxValue

                }
            }
        }

        MouseArea {
            width: 10
            height: parent.height
            x: contentItem.x + contentItem.width - 5
            cursorShape: Qt.SizeHorCursor

            property int mouseInit: 0

            onPressed: {
                mouseInit = mouseX
            }

            onPositionChanged: {
                if ( root.mouseEnabled ) {

                    var dx = mouseX - mouseInit
                    var auxGrainSize = grainSize + ( dx / root.width );
                    if ( auxGrainSize > 1 - ( value  - root.from ) / ( root.to - root.from ) )
                        auxGrainSize = 1 - ( value  - root.from ) / ( root.to - root.from );

                    grainSize = auxGrainSize;
                }
            }
        }

    }

    Text {
        id: valueText
        visible: showValue
        text: {
            if ( units === "" )
                return value.toFixed( decimals )
            if ( units === "%" )
                return ( value * 100 ).toFixed( decimals ) + " %"
            else {
                var adjustedValue = value
                var adjustedUnit = units
                if ( value > 1000000 ) {
                    adjustedValue = value / 1000000
                    adjustedUnit = "M" + units
                } else if ( value > 1000 ) {
                    adjustedValue = value / 1000
                    adjustedUnit = "K" + units
                }

                return adjustedValue.toFixed( decimals ) + " " + adjustedUnit
            }
        }

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        z:102
        color: "white"
        font.pointSize: 8
    }

    Text {
        text: label
        color: root.color
        font.pointSize: 8
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -parent.height / 2 - font.pointSize
    }


}
