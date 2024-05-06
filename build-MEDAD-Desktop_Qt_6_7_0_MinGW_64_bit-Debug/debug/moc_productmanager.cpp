/****************************************************************************
** Meta object code from reading C++ file 'productmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MEDAD/productmanager.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSProductManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSProductManagerENDCLASS = QtMocHelpers::stringData(
    "ProductManager",
    "onCartClicked",
    "",
    "onSignOutClicked",
    "onAddToCartClicked",
    "onNextClicked",
    "onPrevClicked",
    "searchProducts",
    "keyword",
    "createProductWidget",
    "QWidget*",
    "Products*",
    "product",
    "resizeImage",
    "originalPixmap",
    "maxWidth",
    "maxHeight",
    "onRegisterAdminClicked",
    "onRegisterSellerClicked",
    "sortPage",
    "QLayout*",
    "layout",
    "arg1",
    "vector<Products*>&",
    "products",
    "startIndex",
    "maxBooksToShow",
    "on_filterBox_currentTextChanged",
    "updateLayout",
    "sortProducts"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSProductManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    1,  103,    2, 0x08,    6 /* Private */,
       9,    1,  106,    2, 0x08,    8 /* Private */,
      13,    3,  109,    2, 0x08,   10 /* Private */,
      17,    0,  116,    2, 0x08,   14 /* Private */,
      18,    0,  117,    2, 0x08,   15 /* Private */,
      19,    5,  118,    2, 0x08,   16 /* Private */,
      27,    1,  129,    2, 0x08,   22 /* Private */,
      28,    1,  132,    2, 0x08,   24 /* Private */,
      29,    2,  135,    2, 0x08,   26 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    0x80000000 | 10, 0x80000000 | 11,   12,
    QMetaType::QPixmap, QMetaType::QPixmap, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QString, 0x80000000 | 23, QMetaType::Int, QMetaType::Int,   21,   22,   24,   25,   26,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 23, QMetaType::QString,   24,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject ProductManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSProductManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSProductManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSProductManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ProductManager, std::true_type>,
        // method 'onCartClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSignOutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddToCartClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onNextClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPrevClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'searchProducts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'createProductWidget'
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        QtPrivate::TypeAndForceComplete<Products *, std::false_type>,
        // method 'resizeImage'
        QtPrivate::TypeAndForceComplete<QPixmap, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPixmap &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onRegisterAdminClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRegisterSellerClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLayout *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<Products*> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_filterBox_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'updateLayout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QLayout *, std::false_type>,
        // method 'sortProducts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<Products*> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void ProductManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCartClicked(); break;
        case 1: _t->onSignOutClicked(); break;
        case 2: _t->onAddToCartClicked(); break;
        case 3: _t->onNextClicked(); break;
        case 4: _t->onPrevClicked(); break;
        case 5: _t->searchProducts((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: { QWidget* _r = _t->createProductWidget((*reinterpret_cast< std::add_pointer_t<Products*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 7: { QPixmap _r = _t->resizeImage((*reinterpret_cast< std::add_pointer_t<QPixmap>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QPixmap*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->onRegisterAdminClicked(); break;
        case 9: _t->onRegisterSellerClicked(); break;
        case 10: _t->sortPage((*reinterpret_cast< std::add_pointer_t<QLayout*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<vector<Products*>&>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 11: _t->on_filterBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->updateLayout((*reinterpret_cast< std::add_pointer_t<QLayout*>>(_a[1]))); break;
        case 13: _t->sortProducts((*reinterpret_cast< std::add_pointer_t<vector<Products*>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLayout* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLayout* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *ProductManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSProductManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProductManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
