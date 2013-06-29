TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

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
