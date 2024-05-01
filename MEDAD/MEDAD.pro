QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accessories.cpp \
    admin.cpp \
    allusers.cpp \
    books.cpp \
    checkout.cpp \
    clickablelabels.cpp \
    customer.cpp \
    discounts.cpp \
    loginwindow.cpp \
    main.cpp \
    productmanager.cpp \
    products.cpp \
    registerwindow.cpp \
    shoppingcart.cpp \
    techs.cpp \
    user.cpp

HEADERS += \
    accessories.h \
    admin.h \
    allusers.h \
    books.h \
    checkout.h \
    clickablelabels.h \
    customer.h \
    discounts.h \
    loginwindow.h \
    productmanager.h \
    products.h \
    registerwindow.h \
    shoppingcart.h \
    techs.h \
    user.h

FORMS += \
    checkout.ui \
    loginwindow.ui \
    productmanager.ui \
    registerwindow.ui \
    shoppingcart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Bags.qrc \
    BookMarks.qrc \
    Books.qrc \
    Resources.qrc \
    Techs.qrc \
    Tshirts.qrc
