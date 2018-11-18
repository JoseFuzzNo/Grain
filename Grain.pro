QT += quick svg multimedia
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    instrument.cpp \
    grainprocessor.cpp \
    engine/grain.cpp \
    engine/floatarray.cpp \
    engine/audiobuffer.cpp
INCLUDEPATH += engine

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


include(Grain.pri)

HEADERS += \
    instrument.h \
    grainprocessor.h \
    engine/oscillator.h \
    engine/sineoscillator.h \
    engine/grain.h \
    engine/window.h \
    engine/floatarray.h \
    engine/audiobuffer.h \
    engine/grainoscillator.h

OTHER_FILES = \
    README.md \
    LICENSE
