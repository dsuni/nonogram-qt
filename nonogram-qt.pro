TEMPLATE = app
TARGET = nonogram-qt
DEPENDPATH += .
INCLUDEPATH += .
lessThan(QT_MAJOR_VERSION, 6): error("nonogram-qt requires Qt 6")
QT += core gui widgets

# Input
HEADERS += linesolver.h mainwindow.h nonogram.h pushbutton.h solver.h
SOURCES += linesolver.cpp \
           main.cpp \
           mainwindow.cpp \
           nonogram.cpp \
           pushbutton.cpp \
           solver.cpp
TRANSLATIONS += translations/nonogram_sv.ts translations/nonogram_fi.ts
RESOURCES += nonogram-qt.qrc
