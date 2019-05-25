TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        commandlineparser.cpp \
        main.cpp \
        tests.cpp

HEADERS += \
    catch.hpp \
    commandlineparser.h
