#-------------------------------------------------
#
# Project created by QtCreator 2019-05-02T20:07:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Clonium
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    cellcontainer.cpp \
    cellcontainervalue.cpp \
    cloniumgame.cpp \
    cloniumgrid.cpp \
    game.cpp \
    grid.cpp \
        main.cpp \
    cloniummenu.cpp \
    mainmenu.cpp \
    cloniumparameters.cpp \
    about.cpp \
    pawn.cpp \
    player.cpp \
    squaregrid.cpp \
    widgetmanager.cpp

HEADERS += \
    cellcontainer.h \
    cellcontainervalue.h \
    cloniumgame.h \
    cloniumgrid.h \
    cloniummenu.h \
    game.h \
    grid.h \
    mainmenu.h \
    cloniumparameters.h \
    about.h \
    pawn.h \
    player.h \
    squaregrid.h \
    widgetmanager.h

FORMS +=

RESOURCES += ressources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
