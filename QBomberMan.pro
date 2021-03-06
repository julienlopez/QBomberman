#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T10:08:09
#
#-------------------------------------------------

QT       += core gui

TARGET = QBomberMan
TEMPLATE = app
CONFIG += no_keywords

greaterThan(QT_MAJOR_VERSION,4):QT+=widgets

INCLUDEPATH += .

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic -Wpointer-arith -Wcast-align -Wwrite-strings -Wredundant-decls -Winline -Wno-long-long -Wuninitialized
# -Wshadow -Wmissing-declarations

include(QBomberMan.pri)

SOURCES += main.cpp\
        mainwindow.cpp \
    screen.cpp \
    entitymanager.cpp \
    components/screenposition.cpp \
    components/velocity.cpp \
    components/graphic.cpp \
    entity.cpp \
    systems/system.cpp \
    systems/systemmanager.cpp \
    utils/utils.cpp \
    systems/movement.cpp \
    systems/screendisplay.cpp \
    systems/physics.cpp \
    systems/movementinputhandler.cpp \
    components/player.cpp \
    systems/dropbombinputhandler.cpp \
    components/collisionbox.cpp \
    components/lifetime.cpp \
    systems/lifetimemanager.cpp \
    systems/bombtrigger.cpp

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
    components/componentfactory.hpp \
    utils/noninstanciable.hpp \
    components/crtp_component.hpp \
    components/screenposition.hpp \
    utils/point.hpp \
    components/velocity.hpp \
    components/graphic.hpp \
    entity.hpp \
    systems/system.hpp \
    typedefs.hpp \
    systems/systemmanager.hpp \
    utils/factorywithautoid.hpp \
    utils/defaultfactorystoragepolicies.hpp \
    utils/clonable.hpp \
    systems/crtp_system.hpp \
    systems/systemfactory.hpp \
    systems/movement.hpp \
    systems/requirementmaker.hpp \
    static_tests/test_parameter_traits.hpp \
    systems/screendisplay.hpp \
    systems/updatepolicies.hpp \
    utils/safepointer.hpp \
    systems/physics.hpp \
    systems/movementinputhandler.hpp \
    components/player.hpp \
    systems/dropbombinputhandler.hpp \
    components/collisionbox.hpp \
    components/lifetime.hpp \
    systems/lifetimemanager.hpp \
    systems/bombtrigger.hpp
