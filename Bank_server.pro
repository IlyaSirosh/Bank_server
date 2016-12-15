QT += core
QT += network
QT -= gui


CONFIG += c++11


TARGET = Bank_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    bank.cpp \
    session.cpp

HEADERS += \
    server.h \
    bank.h \
    session.h

DISTFILES += \
    Accounts.txt
