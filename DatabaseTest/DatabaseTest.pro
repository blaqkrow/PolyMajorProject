TEMPLATE = app
TARGET = DatabaseTest
QT += core \
    gui \
    sql
HEADERS += clinicianoptions.h \
    client.h \
    Regimen.h \
    drugoption.h \
    Algo.h \
    Common.h \
    DB_Api.h \
    Pump_Parameters.h \
    administratorgui.h \
    changeipadd.h \
    forFatah.h \
    gpio.h \
    infusion.h \
    infusionchangeregimen.h \
    logingui.h \
    myKeypadScanning.h \
    patientgui.h \
    regimenoption.h \
    registercliniciangui.h \
    sqlite3.h \
    sqlite3ext.h \
    myKeypadScanning.h 
SOURCES += clinicianoptions.cpp \
    client.c \
    drugoption.cpp \
    Algo.c \
    EventLog.c \
    administratorgui.cpp \
    changeipadd.cpp \
    infusion.cpp \
    infusionchangeregimen.cpp \
    logingui.cpp \
    main.cpp \
    mainFunction.c \
    patientgui.cpp \
    regimenoption.cpp \
    registercliniciangui.cpp \
    sqlite3.c
FORMS += clinicianoptions.ui \
    drugoption.ui \
    administratorgui.ui \
    changeipadd.ui \
    infusion.ui \
    infusionchangeregimen.ui \
    logingui.ui \
    patientgui.ui \
    regimenoption.ui \
    registercliniciangui.ui
RESOURCES += 
