TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        capteurhumidite.cpp \
        main.cpp \
        vanne.cpp \
        zonearrosage.cpp

HEADERS += \
    capteurhumidite.h \
    vanne.h \
    zonearrosage.h
