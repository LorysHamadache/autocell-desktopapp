#-------------------------------------------------
#
# Project created by QtCreator 2018-05-11T11:44:48
#
#-------------------------------------------------

QT       += core
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutoCell
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


SOURCES += \
        main.cpp \
        sources/ui/autocell.cpp \
        sources/ui/creation_automate.cpp \
        sources/automate/cellule.cpp \
        sources/automate/grille.cpp \
        sources/automate/automate.cpp \
        sources/automate/regle.cpp \
        sources/automate/simulateur.cpp

HEADERS += \
        headers/ui/autocell.h \
        headers/ui/creation_automate.h \
        headers/automate/cellule.h \
        headers/automate/grille.h \
        headers/automate/automate.h \
        headers/automate/regle.h \
        headers/automate/simulateur.h \



FORMS += \
    forms/autocell.ui \
    forms/creation_automate.ui
