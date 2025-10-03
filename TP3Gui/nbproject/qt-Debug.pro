# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = TP3Gui
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += DialogAjoutCheque.cpp DialogAjoutEpargne.cpp DialogSupprimer.cpp GestionCompteGUI.cpp main.cpp
HEADERS += DialogAjoutCheque.h DialogAjoutEpargne.h DialogSupprimer.h GestionCompteGUI.h
FORMS += DialogAjoutCheque.ui DialogAjoutEpargne.ui DialogSupprimer.ui GestionCompteGUI.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../TP3Sources 
LIBS += ../TP3Sources/dist/Debug/GNU-Linux/libtp3sources.a  
