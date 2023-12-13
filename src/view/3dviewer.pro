QT       += core gui opengl
mac: QT += openglwidgets
# linux: QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include (qtgifimage/gifimage/qtgifimage.pri)

SOURCES += \
    ../main.cc \
    s21_scene.cc \
    s21_viewer.cc \
    ../model/s21_aff_transform.cc \
    ../model/s21_facade_obj.cc \
    ../model/s21_parser_obj.cc

HEADERS += \
    s21_scene.h \
    s21_viewer.h \
    s21_strategy.h \
    s21_strategy_r.h \
    ../controller/s21_controller_obj.h \
    ../model/s21_aff_transform.h \
    ../model/s21_facade_obj.h \
    ../model/s21_parser_obj.h

FORMS += \
    s21_viewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
