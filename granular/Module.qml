import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item {
    id: root

    width: 420
    height: 184

    clip: true

    // COLORS
    property color mainColor: "orange"
    property color secondColor: "#444444"
    property color thirdColor: "yellow"
    property color fourthColor: "#393939"
    property color backgroundColor: "#333333"

    // TITLE AND TITLE BEHAVIOR
    property string title: "MODULE"
    property bool titleCheckEnabled: false
    property bool titleChecked: false

    // EDIT MODE
    property bool editMode: false
    onEditModeChanged: {
        state = editMode ? "EDIT_MODE" : "RUN_MODE";
    }

    // MODULE COMPONENTS
    property alias header1: header1Loader.sourceComponent
    property alias header2: header2Loader.sourceComponent
    property alias icon: iconLoader.sourceComponent

    // SIGNALS
    signal statusChanged( var message, var value )

    // DRAG BEHAVIOR
    //Drag.active: backgroundArea.drag.active
    Drag.hotSpot.x: 0
    Drag.hotSpot.y: 0
    //Drag.mimeData: { "text/plain": "Teststring" }
    Drag.dragType: Drag.Automatic
    Drag.onDragStarted: {
        visible = true
    }
    Drag.onDragFinished: {
        visible = false
    }

    // STATES
    states: [
        State {
            name: "EDIT_MODE"
            //PropertyChanges { target: backgroundShadow; opacity: 0.7 }
            PropertyChanges { target: background; border.width: 3 }
        },
        State {
            name: "RUN_MODE"
            //PropertyChanges { target: backgroundShadow; opacity: 0 }
            PropertyChanges { target: background; border.width: 1 }
        }

    ]
    state: "RUN_MODE"

    // TRANSITIONS
    transitions: [
        Transition {
            from: "RUN_MODE"
            to: "EDIT_MODE"
            SequentialAnimation {
                NumberAnimation {
                    target: root
                    property: "scale"
                    to: 1.1
                    duration: 50
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: root
                    property: "scale"
                    to: 1
                    duration: 100
                    easing.type: Easing.InOutQuad
                }
            }
        }
    ]

    // INITIALIZATION
    Component.onCompleted: {

    }

    // COMPONENTS

    Rectangle {
        id: background
        color: root.backgroundColor
        border.color: root.secondColor
        radius: 2
        anchors.fill: parent

    }

    Rectangle {
        //width: titleTxt.width + 20
        width: parent.width
        height: 20
        color: root.secondColor
        radius: 2

        MouseArea {
            id: titleBarArea
            anchors.fill: parent
            drag.target: root.editMode ? root : undefined

            /*onPressAndHold: {
                root.editMode = !editMode;
                root.state = editMode ? "EDIT_MODE" : "RUN_MODE";
            }*/

        }

        Item {
            id: iconRect
            width: 20
            height: width
            clip: true
            Loader {
                id: iconLoader
                anchors.centerIn: parent
                sourceComponent: Rectangle {
                    width: 15
                    height: width
                    radius: width / 2
                    color: root.backgroundColor
                }
            }
        }

        Item {
            id: header1Rect
            height: parent.height
            anchors.left: iconRect.right
            anchors.right: titleTxt.left
            clip: true
            Loader {
                id: header1Loader
            }
        }

        Text {
            id: titleTxt
            text: root.title
            anchors.centerIn: parent
            font.pointSize: 9
            //Layout.alignment: Qt.AlignCenter
            color: root.titleCheckEnabled ? ( root.titleChecked ? root.mainColor : root.backgroundColor ) : root.mainColor;
            Behavior on color {
                ColorAnimation {
                    duration: 30
                }
            }
            MouseArea {
                anchors.fill: parent
                //propagateComposedEvents: true   // Se permite la propagacion hacia el area de la barra de titulo (no funciona)
                onClicked: {
                    if ( root.titleCheckEnabled ) {
                        root.titleChecked = !root.titleChecked;
                        if ( root.titleChecked ) {
                            titlePushAnimation.stop( )
                            titlePushAnimation.start( )
                        }
                    }
                }
            }
            SequentialAnimation {
                id: titlePushAnimation
                NumberAnimation {
                    target: titleTxt
                    property: "scale"
                    to: 1.2
                    duration: 50
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    target: titleTxt
                    property: "scale"
                    to: 1
                    duration: 100
                    easing.type: Easing.InOutQuad
                }
            }
        }

        Item {
            id: header2Rect
            height: parent.height
            anchors.left: titleTxt.right
            anchors.right: parent.right
            clip: true
            Loader {
                id: header2Loader
            }
        }



    }


}
