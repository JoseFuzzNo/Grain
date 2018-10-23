#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>

#include <Client>
#include "grainprocessor.h"
#include "instrument.h"

int main( int argc, char *argv[] ) {
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );

    QGuiApplication app( argc, argv );
    app.setWindowIcon( QIcon( ":img/grain.png" ) );

    QtJack::Client client;
    client.connectToServer( "Grain" );
    GrainProcessor processor( client );
    client.setMainProcessor( &processor );
    client.activate( );
    //client.connect(processor.outL, client.portByName("system:playback_1"));       // Conexion automatica con la salida del sistema

    QQmlApplicationEngine engine;
    engine.rootContext( )->setContextProperty( "Instrument", Instrument::instance( ) );
    engine.load( QUrl( QStringLiteral( "qrc:/main.qml" ) ) );
    if ( engine.rootObjects( ).isEmpty( ) )
        return -1;

    return app.exec( );
}
