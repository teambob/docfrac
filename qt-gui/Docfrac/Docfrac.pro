#-------------------------------------------------
#
# Project created by QtCreator 2012-09-28T11:04:18
#
#-------------------------------------------------

QT       += core gui

TARGET = qt-docfrac
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    about.cpp \
    propertiesdialog.cpp \
    progressdialog.cpp \
    batchmodel.cpp \
    batchentry.cpp \
    ../../core/FormatToExtensionMap.cpp \
    ../../core/ExtensionToFormatMap.cpp \
    conversionthread.cpp

HEADERS  += mainwindow.h \
    about.h \
    propertiesdialog.h \
    progressdialog.h \
    batchmodel.h \
    batchentry.h \
    conversionthread.h

FORMS    += mainwindow.ui \
    about.ui \
    propertiesdialog.ui \
    progressdialog.ui

OTHER_FILES +=

RESOURCES += \
    common.qrc

unix|win32: LIBS += -lboost_filesystem -lboost_system
unix|win32: INCLUDEPATH += ../../core/


unix|win32: LIBS += -L$$PWD/../../core/ -ldox

isEmpty(PREFIX) {
 PREFIX = /usr/local
}
unix: target.path = $$PREFIX/bin
unix: INSTALLS += target

