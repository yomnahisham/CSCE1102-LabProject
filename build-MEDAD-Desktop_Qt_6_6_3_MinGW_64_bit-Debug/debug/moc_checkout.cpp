/****************************************************************************
** Meta object code from reading C++ file 'checkout.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MEDAD/checkout.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'checkout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCheckoutENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCheckoutENDCLASS = QtMocHelpers::stringData(
    "Checkout",
    "on_enterCredit_clicked",
    "",
    "on_ReTurnHome_clicked",
    "on_enterAddress_clicked",
    "on_ConfirmButton_clicked",
    "on_enterDiscount_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCheckoutENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[9];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[24];
    char stringdata5[25];
    char stringdata6[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCheckoutENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCheckoutENDCLASS_t qt_meta_stringdata_CLASSCheckoutENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "Checkout"
        QT_MOC_LITERAL(9, 22),  // "on_enterCredit_clicked"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 21),  // "on_ReTurnHome_clicked"
        QT_MOC_LITERAL(55, 23),  // "on_enterAddress_clicked"
        QT_MOC_LITERAL(79, 24),  // "on_ConfirmButton_clicked"
        QT_MOC_LITERAL(104, 24)   // "on_enterDiscount_clicked"
    },
    "Checkout",
    "on_enterCredit_clicked",
    "",
    "on_ReTurnHome_clicked",
    "on_enterAddress_clicked",
    "on_ConfirmButton_clicked",
    "on_enterDiscount_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCheckoutENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Checkout::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCheckoutENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCheckoutENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCheckoutENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Checkout, std::true_type>,
        // method 'on_enterCredit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ReTurnHome_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enterAddress_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ConfirmButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enterDiscount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Checkout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Checkout *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_enterCredit_clicked(); break;
        case 1: _t->on_ReTurnHome_clicked(); break;
        case 2: _t->on_enterAddress_clicked(); break;
        case 3: _t->on_ConfirmButton_clicked(); break;
        case 4: _t->on_enterDiscount_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Checkout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Checkout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCheckoutENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Checkout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
