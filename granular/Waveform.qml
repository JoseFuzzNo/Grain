import QtQuick 2.0


Item {
    id: root

    property color color: "yellow"
    property var wave: []
    onWaveChanged: {
        waveformCanvas.requestPaint( );
    }


    Canvas {
        id: waveformCanvas
        anchors.fill: parent
        antialiasing: true
        onPaint: {
            var ctx = getContext( "2d" )
            ctx.reset( )


            ctx.strokeStyle = root.color
            ctx.beginPath( );

            // linea central
            //ctx.lineWidth = 0.1
            //ctx.moveTo( 0, height / 2 );
            //tx.lineTo( width, height / 2 );


            // forma de onda
            ctx.moveTo( 0, height / 2 );
            ctx.lineWidth = 1

            var pointsPerPixel = parseInt( wave.length / width );
            var max = 0;
            var min = 0;
            for ( var i = 0; i < width; i++ ) {
                var valuePlus = 0;
                var valueMinus = 0;
                for ( var j = i * pointsPerPixel; j < ( i + 1 ) * pointsPerPixel; j++ ) {
                    if ( wave[j] > valuePlus )
                        valuePlus = wave[j];
                    if ( wave[j] < valueMinus )
                        valueMinus = wave[j];
                }

                ctx.moveTo( i, ( 1 - valueMinus ) * height / 2 );
                ctx.lineTo( i, ( 1 - valuePlus ) * height / 2 );
            }
            ctx.stroke( )

        }
    }
}
