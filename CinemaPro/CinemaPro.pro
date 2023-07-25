 QT       += sql printsupport serialport widgets multimedia core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=  c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    gabonnements.cpp \
    gesemployee.cpp \
    gesevenement.cpp \
    gesfilm.cpp \
    gesparking.cpp \
    gesproduit.cpp \
    gesprofil.cpp \
    gessalle.cpp \
    greservation.cpp \
    gsubscribers.cpp \
    main.cpp \
    mainwindow.cpp \
    statistics.cpp \
    welcomewidget.cpp

HEADERS += \
    database.h \
    gabonnements.h \
    gesemployee.h \
    gesevenement.h \
    gesfilm.h \
    gesparking.h \
    gesproduit.h \
    gesprofil.h \
    gessalle.h \
    greservation.h \
    gsubscribers.h \
    mainwindow.h \
    statistics.h \
    welcomewidget.h

FORMS += \
    statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/release/ -lcomponents
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/debug/ -lcomponents
else:unix: LIBS += -L$$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/ -lcomponents

INCLUDEPATH += $$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/debug
DEPENDPATH += $$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/debug

RESOURCES += \
    images/resources.qrc
