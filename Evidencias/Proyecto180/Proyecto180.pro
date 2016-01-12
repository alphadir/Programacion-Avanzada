TARGET = Proyecto180 #what you want to call your exe

SOURCES += \
    button.cpp \
    calculator.cpp \
    main.cpp    #add the name of your source files

HEADERS += \
    button.h \
    calculator.h

#HEADERS += headername.h # add the name of your header file



QT       += core gui   #for using qtcore and qtgui stuff

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  #for qt5
