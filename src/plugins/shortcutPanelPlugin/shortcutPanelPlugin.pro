
QT       += core gui widgets dbus

TEMPLATE = lib
CONFIG += plugin
CONFIG += c++11 link_pkgconfig
TARGET = shortcutPanel
DESTDIR = ../sidebar_shortcut_Panel_plugins
RESOURCES  += shortcutPanelPlugin.qrc
PKGCONFIG  += gsettings-qt
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customstyle_switchNormalStatus.cpp \
    swichButtonOpenStatus.cpp \
    bluetoothwidget.cpp \
    calculatorwidget.cpp \
    hotspotwidget.cpp \
    mainwidget.cpp \
    nodisturbwidget.cpp \
    padwidget.cpp \
    pushbutton.cpp \
    screenshotwidget.cpp \
    settingwidget.cpp \
    shortcutpanelplugin.cpp \
    switchbutton.cpp \
    wifiwidget.cpp

HEADERS += \
    customstyle_switchNormalStatus.h \
    swichButtonOpenStatus.h \
    bluetoothwidget.h \
    calculatorwidget.h \
    data.h \
    hotspotwidget.h \
    mainwidget.h \
    nodisturbwidget.h \
    padwidget.h \
    pushbutton.h \
    screenshotwidget.h \
    settingwidget.h \
    shortcutpanelplugin.h \
    switchbutton.h \
    wifiwidget.h

INCLUDEPATH    += ../../plugin-interface

DISTFILES += shortcutPanelPlugin.json

# Default rules for deployment.
unix {
    target.path = /usr/lib/ukui-sidebar/shortcutPanelPlugins
}
!isEmpty(target.path): INSTALLS += target
