QT       += core gui
QT       += serialport

include(./QXlsx/QXlsx.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG -= winrt

QMAKE_PROJECT_DEPTH = 0

msvc {
    QMAKE_CXXFLAGS += /Zc:__cplusplus
    QMAKE_CXXFLAGS += /std:c++17  # 明确指定C++17标准
    LIBS += -luser32
}

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#win32 { QMAKE_MSC_VER = 1900 }  # VS2019: 1920，VS2022: 1930

RC_ICONS = TCL.ico
VERSION = 1.0.1.2
TARGET = TCLDebugTool
QMAKE_TARGET_COMPANY = "TCL泛智屏BU研发中心"
QMAKE_TARGET_PRODUCT = TCLDebugTool
QMAKE_TARGET_DESCRIPTION = "TCLDebugTool: Created by Qt5.14.1"
QMAKE_TARGET_COPYRIGHT = "TCL泛智屏BU研发中心 版权所有(2025.6)"
RC_LANG = 0x0004
CODECFORTR=UTF-8
CODECFORSRC=UTF-8

INCLUDEPATH += ./COM
INCLUDEPATH += ./RegRam
INCLUDEPATH += ./Quality
INCLUDEPATH += ./Algorithm
INCLUDEPATH += ./AgingTest
INCLUDEPATH += ./PackCheck
INCLUDEPATH += ./QXlsx/header
INCLUDEPATH += ./QXlsx

SOURCES += \
    AgingTest/DialogAgingTest.cpp \
    COM/LogToFile.cpp \
    DialogSpeacialRead.cpp \
    DialogToast.cpp \
    FrameGenGammaEdit.cpp \
    PackCheck/DialogConfigPack.cpp \
    PackCheck/DialogPackMaker.cpp \
    PackCheck/cJSON.c \
    PackCheck/cJSON_Utils.c \
    PackCheck/md5.c \
    PackCheck/norflash.c \
    Quality/FrameBLGamma.cpp \
    Quality/FrameBLGammaPanel.cpp \
    Quality/FrameBLPostProc.cpp \
    Quality/FrameCTGamma.cpp \
    Quality/FrameControl.cpp \
    Quality/FrameDemo.cpp \
    Quality/FrameEPCCBOOST.cpp \
    Quality/FrameEPCCPanel.cpp \
    Quality/FrameLocalDimmingProfile.cpp \
    Quality/FramePQGamma.cpp \
    Quality/FramePixelCompensation.cpp \
    Quality/FrameTPFilter.cpp \
    Quality/FrameTPFilterPanel.cpp \
    global.cpp \
    main.cpp \
    MainWindow.cpp \
    RegRam/DialogRegRamManager.cpp \
    RegRam/FrameRamManager.cpp \
    RegRam/FrameRegManager.cpp \
    COM/SerialTestDialog.cpp \
    COM/gencomport.cpp \
    COM/DialogLogView.cpp \
    Quality/DialogQualityManager.cpp

HEADERS += \
    AgingTest/DialogAgingTest.h \
    COM/LogToFile.h \
    DialogSpeacialRead.h \
    DialogToast.h \
    FrameGenGammaEdit.h \
    PackCheck/DialogConfigPack.h \
    PackCheck/DialogPackMaker.h \
    PackCheck/cJSON.h \
    PackCheck/cJSON_Utils.h \
    PackCheck/md5.h \
    PackCheck/norflash.h \
    Quality/FrameBLGammaPanel.h \
    Quality/FrameBLPostProc.h \
    Quality/FrameCTGamma.h \
    Quality/FrameEPCCPanel.h \
    Quality/FrameLocalDimmingProfile.h \
    Quality/FramePQGamma.h \
    Quality/FrameTPFilter.h \
    MainWindow.h \
    Quality/FrameBLGamma.h \
    Quality/FrameControl.h \
    Quality/FrameDemo.h \
    Quality/FrameEPCCBOOST.h \
    Quality/FramePixelCompensation.h \
    Quality/FrameTPFilterPanel.h \
    RegRam/DialogRegRamManager.h \
    RegRam/FrameRamManager.h \
    RegRam/FrameRegManager.h \
    COM/DialogLogView.h \
    COM/SerialTestDialog.h \
    COM/gencomport.h \
    Quality/DialogQualityManager.h \
    global.h

FORMS += \
    AgingTest/DialogAgingTest.ui \
    DialogSpeacialRead.ui \
    DialogToast.ui \
    FrameGenGammaEdit.ui \
    MainWindow.ui \
    PackCheck/DialogConfigPack.ui \
    PackCheck/DialogPackMaker.ui \
    Quality/FrameBLGammaPanel.ui \
    Quality/FrameBLPostProc.ui \
    Quality/FrameCTGamma.ui \
    Quality/FrameEPCCPanel.ui \
    Quality/FrameLocalDimmingProfile.ui \
    Quality/FramePQGamma.ui \
    Quality/FrameTPFilter.ui \
    Quality/FrameBLGamma.ui \
    Quality/FrameControl.ui \
    Quality/FrameDemo.ui \
    Quality/FrameEPCCBOOST.ui \
    Quality/FramePixelCompensation.ui \
    Quality/FrameTPFilterPanel.ui \
    RegRam/DialogRegRamManager.ui \
    RegRam/FrameRamManager.ui \
    RegRam/FrameRegManager.ui \
    COM/DialogLogView.ui \
    COM/SerialTestDialog.ui \
    Quality/DialogQualityManager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
