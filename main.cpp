#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <Client>
#include <Processor>
#include <RingBuffer>


class MyProcessor : public QtJack::Processor {
public:
    MyProcessor( QtJack::Client& client ) : Processor( client )  {

    }

    void process( int samples ) {


    }


};


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":img/grain.png"));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QtJack::Client client;
    client.connectToServer( "Grain" );
    MyProcessor processor( client );
    client.setMainProcessor( &processor );
    client.activate();


    // Connect automatically to system playback.
    //client.connect(processor.outL, client.portByName("system:playback_1"));

    return app.exec( );
}
