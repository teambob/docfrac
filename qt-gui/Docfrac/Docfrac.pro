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
    conversionthread.cpp \
    donatedialog.cpp

HEADERS  += mainwindow.h \
    about.h \
    propertiesdialog.h \
    progressdialog.h \
    batchmodel.h \
    batchentry.h \
    conversionthread.h \
    donatedialog.h
	
win32: INCLUDEPATH += "c:/Program Files/boost/boost_1_51"
win32: QMAKE_LIBDIR += "c:/Program Files/boost/boost_1_51/lib"

FORMS    += mainwindow.ui \
    about.ui \
    propertiesdialog.ui \
    progressdialog.ui \
    donatedialog.ui

OTHER_FILES +=

RESOURCES += \
    common.qrc

unix: LIBS += -lboost_filesystem -lboost_system -lboost_regex
#win32: LIBS += -lboost_filesystem-vc100-mt-1_51 -lboost_system-vc100-mt-1_51
unix|win32: INCLUDEPATH += ../../core

unix: LIBS += -ldox
win32: LIBS += -llibdox

win32: QMAKE_LIBDIR += ../../core/Release
unix: QMAKE_LIBDIR += ../../core

isEmpty(PREFIX) {
 PREFIX = /usr/local
}
unix: target.path = $$PREFIX/bin
unix: INSTALLS += target

