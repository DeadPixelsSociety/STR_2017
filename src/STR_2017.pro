TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += SFML_STATIC
DEFINES += QT_DEPRECATED_WARNINGS

PRECOMPILED_HEADER += ../include/stdafx.h

#message($$QMAKESPEC)

##SFML
LIBS += -LC:/SFML-2.4.2/lib

#-Add essential Windows libs
LIBS += -luser32 -ladvapi32

#-Add sfml lib
CONFIG(release, debug|release): LIBS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s
CONFIG(debug, debug|release): LIBS += -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d

#-Add sfml dependencies in order to use SFML_STATIC
LIBS += -lfreetype -ljpeg -lopengl32 -lwinmm -lgdi32

#-Include sfml headers
INCLUDEPATH += C:/SFML-2.4.2/include
DEPENDPATH += C:/SFML-2.4.2/include

##Sources
SOURCES += main.cpp \
    gameboard.cpp \
    tile.cpp \
    stdafx.cpp \
    inputmanager.cpp \
    cameramanager.cpp \
    robot.cpp \
    drawableobject.cpp \
    gamestate.cpp \
    drawerobject.cpp \
    gameguitop.cpp

HEADERS += \
    ../include/gameboard.h \
    ../include/tile.h \
    ../include/stdafx.h \
    ../include/inputmanager.h \
    ../include/cameramanager.h \
    ../include/robot.h \
    ../include/drawableobject.h \
    ../include/gamestate.h \
    ../include/drawerobject.h \
    ../include/gameguitop.h
