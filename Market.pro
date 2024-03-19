QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UI/ListeFormlari/mtedarikcilistewidget.cpp \
    UI/ListeFormlari/murunlistesi.cpp \
    UI/VeriFormlari/Widgetlar/tedarikciduzenleme.cpp \
    UI/VeriFormlari/mtedarikciformu.cpp \
    UI/VeriFormlari/myeniuruntanimlamaformu.cpp \
    Veri/VeriSiniflari/malisfaturasi.cpp \
    Veri/VeriSiniflari/mmusteribilgileri.cpp \
    Veri/VeriSiniflari/msatisfaturasi.cpp \
    Veri/VeriSiniflari/mtedarikci.cpp \
    Veri/VeriSiniflari/murunalisbilgileri.cpp \
    Veri/VeriSiniflari/murunbilgileri.cpp \
    Veri/VeriSiniflari/murunsatisbilgileri.cpp \
    Veri/VeriYoneticileri/malisfaturasiyoneticisi.cpp \
    Veri/VeriYoneticileri/mmusteribilgileriyoneticisi.cpp \
    Veri/VeriYoneticileri/msatisfaturasiyoneticisi.cpp \
    Veri/VeriYoneticileri/mtedarikciyoneticisi.cpp \
    Veri/VeriYoneticileri/murunalisbilgisiyoneticisi.cpp \
    Veri/VeriYoneticileri/murunbilgisiyoneticisi.cpp \
    Veri/VeriYoneticileri/murunsatisbilgisiyoneticisi.cpp \
    Veri/mgenelveriyoneticisi.cpp \
    main.cpp \
    manapencere.cpp

HEADERS += \
    UI/ListeFormlari/mtedarikcilistewidget.h \
    UI/ListeFormlari/murunlistesi.h \
    UI/VeriFormlari/Widgetlar/tedarikciduzenleme.h \
    UI/VeriFormlari/mtedarikciformu.h \
    UI/VeriFormlari/myeniuruntanimlamaformu.h \
    Veri/VeriSiniflari/malisfaturasi.h \
    Veri/VeriSiniflari/mmusteribilgileri.h \
    Veri/VeriSiniflari/msatisfaturasi.h \
    Veri/VeriSiniflari/mtedarikci.h \
    Veri/VeriSiniflari/murunalisbilgileri.h \
    Veri/VeriSiniflari/murunbilgileri.h \
    Veri/VeriSiniflari/murunsatisbilgileri.h \
    Veri/VeriYoneticileri/malisfaturasiyoneticisi.h \
    Veri/VeriYoneticileri/mmusteribilgileriyoneticisi.h \
    Veri/VeriYoneticileri/msatisfaturasiyoneticisi.h \
    Veri/VeriYoneticileri/mtedarikciyoneticisi.h \
    Veri/VeriYoneticileri/murunalisbilgisiyoneticisi.h \
    Veri/VeriYoneticileri/murunbilgisiyoneticisi.h \
    Veri/VeriYoneticileri/murunsatisbilgisiyoneticisi.h \
    Veri/VeriYoneticileri/temel_veri_yoneticisi.h \
    Veri/mgenelveriyoneticisi.h \
    Veri/tanimlar.h \
    manapencere.h

FORMS += \
    UI/ListeFormlari/mtedarikcilistewidget.ui \
    UI/ListeFormlari/murunlistesi.ui \
    UI/VeriFormlari/Widgetlar/tedarikciduzenleme.ui \
    UI/VeriFormlari/mtedarikciformu.ui \
    UI/VeriFormlari/myeniuruntanimlamaformu.ui \
    manapencere.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
