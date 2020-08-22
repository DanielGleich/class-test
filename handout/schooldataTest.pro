QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_dataextraction.cpp \
  config.cpp \
  database.cpp \
  model.cpp

HEADERS += \
  config.h \
  database.h \
  model.h \
  test_data.h
