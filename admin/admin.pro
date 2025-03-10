QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    vd/vdmenu.cpp \
    vd/vdmenuitem.cpp \
    vd/vdswitch.cpp \
    widget.cpp \
    widget/basewidget.cpp \
    widget/testbtnwidget.cpp

HEADERS += \
    vd/data/vdmenutree.h \
    vd/vdmenu.h \
    vd/vdmenudata.h \
    vd/vdmenuitem.h \
    vd/vdswitch.h \
    widget.h \
    widget/basewidget.h \
    widget/testbtnwidget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    vd/resource/vd_resource.qrc \
    widget/resources.qrc
