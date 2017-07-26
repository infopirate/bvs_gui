QT += widgets

TARGET = bvs
TEMPLATE = app

SOURCES += \
    main.cpp \
    bvs_wallet.cpp \
    ausfuehrendialog.cpp \
    projekteauswahl.cpp \
    Classes/Domain/Model/project.cpp \
    Classes/Domain/projectRepository.cpp \
    Classes/Controller/projectcontroller.cpp \
    settingsdialog.cpp \
    Classes/Domain/Model/node.cpp \
    Classes/Controller/nodecontroller.cpp \
    Classes/Service/libgnupg.cpp \
    Classes/Controller/ballotcontroller.cpp \
    Classes/Domain/ballotrepository.cpp \
    ballotformwidget.cpp \
    Classes/Service/convert.cpp

HEADERS += \
    bvs_wallet.h \
    ausfuehrendialog.h \
    projekteauswahl.h \
    Classes/Domain/Model/project.h \
    Classes/Domain/projectRepository.h \
    Classes/Controller/projectController.h \
    settingsdialog.h \
    Classes/Domain/Model/node.h \
    Classes/Controller/nodecontroller.h \
    Classes/Service/libgnupg.h \
    Classes/Controller/ballotcontroller.h \
    Classes/Domain/ballotrepository.h \
    ballotformwidget.h \
    Classes/Service/convert.h

FORMS += \
    bvs_wallet.ui \
    ausfuehrendialog.ui \
    projekteauswahl.ui \
    settingsdialog.ui \
    ballotformwidget.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target

DISTFILES += \
    README.md
