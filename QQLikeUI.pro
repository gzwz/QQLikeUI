#-------------------------------------------------
#
# Project created by QtCreator 2015-02-07T19:59:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQLikeUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/ui/loginform.cpp \
    src/ui/collapseview.cpp \
    src/ui/collapseviewitem.cpp \
    src/ui/litteriem.cpp \
    src/ui/moveableframelesswindow.cpp \
    src/ui/mainform.cpp \
    src/model/singleton.cpp \
    src/ui/colorpickform.cpp \
    src/model/config.cpp

HEADERS  += mainwindow.h \
    src/ui/loginform.h \
    src/ui/collapseview.h \
    src/ui/collapseviewitem.h \
    src/ui/litteriem.h \
    src/ui/moveableframelesswindow.h \
    src/ui/mainform.h \
    src/model/singleton.h \
    src/ui/colorpickform.h \
    src/model/config.h

FORMS    += mainwindow.ui \
    src/ui/loginform.ui \
    src/ui/collapseview.ui \
    src/ui/collapseviewitem.ui \
    src/ui/litteriem.ui \
    src/ui/mainform.ui \
    src/ui/colorpickform.ui

RESOURCES += \
    rs/rs.qrc
