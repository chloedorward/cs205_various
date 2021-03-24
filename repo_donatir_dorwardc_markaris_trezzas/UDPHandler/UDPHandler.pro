TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    HDate.cpp \
    HBoard.cpp \
    HTime.cpp \
    DataAnalyzer.cpp \
    RealTimeSimulator.cpp \
    UDPHandler.cpp \
    UDPMessageData.cpp

HEADERS += \
    HTime.h \
    HDate.h \
    HBoard.h \
    DataAnalyzer.h \
    RealTimeSimulator.h \
    UDPHandler.h \
    UDPMessageData.h
