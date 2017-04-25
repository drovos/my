
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
FORMS   += MainWindow.ui \
    loginwindow.ui

HEADERS += MainWindow.h \
    loginwindow.h

SOURCES += \
           main.cpp \
    MainWindow.cpp \
    loginwindow.cpp
