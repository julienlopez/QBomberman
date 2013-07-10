#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T10:08:09
#
#-------------------------------------------------

QT       += core gui

TARGET = QBomberMan
TEMPLATE = app

INCLUDEPATH += .

QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += main.cpp\
        mainwindow.cpp \
    screen.cpp \
    entitymanager.cpp

HEADERS  += mainwindow.hpp \
    screen.hpp \
    components/component.hpp \
    utils/noncopiable.hpp \
    utils/singleton.hpp \
    utils/factory.hpp \
    utils/defaultfactoryerrorpolicy.hpp \
    entitymanager.hpp \
    utils/utils.hpp \
    utils/parametertrait.hpp \
    static_tests/test_parameter_traits.hpp
