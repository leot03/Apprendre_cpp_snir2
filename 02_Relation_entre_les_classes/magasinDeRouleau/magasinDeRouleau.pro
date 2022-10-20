TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        alveoleslibres.cpp \
        chariot.cpp \
        magasin.cpp \
        menu.cpp \
        rouleau.cpp \
        stock.cpp \
        testAlveole.cpp \
        teststock.cpp

HEADERS += \
    alveoleslibres.h \
    chariot.h \
    magasin.h \
    menu.h \
    rouleau.h \
    stock.h \
    teststock.h

DISTFILES += \
    menu.txt
