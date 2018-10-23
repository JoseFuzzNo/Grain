import QtQuick 2.0

Item {
    id: root
    width: column.width
    height: column.height

    // COLORS
    property color mainColor: "orange"
    property color secondColor: "#444444"
    property color thirdColor: "yellow"
    property color fourthColor: "#393939"
    property color backgroundColor: "#333333"

    // CONFIG
    property string title: "SUBMODULE"

    // SIGNALS
    signal statusChanged( var message, var value )

    // MODULE COMPONENTS
    property alias content: contentLoader.sourceComponent

    // EDIT MODE
    property bool editMode: false
    onEditModeChanged: {
        state = editMode ? "EDIT_MODE" : "RUN_MODE";
    }

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
            //PropertyChanges { target: background; border.width: 3 }
        },
        State {
            name: "RUN_MODE"
            //PropertyChanges { target: background; border.width: 1 }
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



    Column {
        id: column
        spacing: -1
        Rectangle {
            //width: titleTxt.width + 10
            width: parent.width
            height: 16
            color: root.secondColor
            radius: 2
            Text {
                id: titleTxt
                text: root.title
                color: root.backgroundColor
                anchors.centerIn: parent
                font.pointSize: 7
            }

            MouseArea {
                id: titleArea
                anchors.fill: parent
                drag.target: root.editMode ? root : undefined
            }
        }

        Rectangle {
            width: contentLoader.width
            height: contentLoader.height
            color: root.fourthColor
            radius: 2
            Loader {
                id: contentLoader
            }
        }
    }


}
