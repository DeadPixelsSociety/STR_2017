TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

DEFINES += SFML_STATIC

PRECOMPILED_HEADER += stdafx.H

##SFML
LIBS += -LC:/SFML-2.4.2/lib

#-Add essential Windows libs
LIBS += -luser32 -ladvapi32

#-Add sfml dependencies in order to user SFML_STATIC
LIBS += -lfreetype -ljpeg -lopengl32 -lwinmm -lgdi32

#-Add sfml lib
CONFIG(release, debug|release): LIBS += -lsfml-graphics-s -lsfml-window-s -lsfml-system-s
CONFIG(debug, debug|release): LIBS += -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d

#-Include sfml headers
INCLUDEPATH += C:/SFML-2.4.2/include
DEPENDPATH += C:/SFML-2.4.2/include

##Sources
SOURCES += main.cpp \
    gameboard.cpp \
    tile.cpp \
    stdafx.cpp \
    drawmanager.cpp \
    inputmanager.cpp \
    cameramanager.cpp

HEADERS += \
    gameboard.h \
    tile.h \
    stdafx.h \
    drawmanager.h \
    inputmanager.h \
    cameramanager.h
