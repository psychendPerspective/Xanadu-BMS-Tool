/****************************************************************************
** Meta object code from reading C++ file 'parameditdouble.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "widgets/parameditdouble.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parameditdouble.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParamEditDouble_t {
    QByteArrayData data[13];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamEditDouble_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamEditDouble_t qt_meta_stringdata_ParamEditDouble = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ParamEditDouble"
QT_MOC_LITERAL(1, 16, 18), // "paramChangedDouble"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "src"
QT_MOC_LITERAL(4, 40, 4), // "name"
QT_MOC_LITERAL(5, 45, 8), // "newParam"
QT_MOC_LITERAL(6, 54, 17), // "percentageChanged"
QT_MOC_LITERAL(7, 72, 1), // "p"
QT_MOC_LITERAL(8, 74, 13), // "doubleChanged"
QT_MOC_LITERAL(9, 88, 1), // "d"
QT_MOC_LITERAL(10, 90, 21), // "on_readButton_clicked"
QT_MOC_LITERAL(11, 112, 28), // "on_readDefaultButton_clicked"
QT_MOC_LITERAL(12, 141, 21) // "on_helpButton_clicked"

    },
    "ParamEditDouble\0paramChangedDouble\0\0"
    "src\0name\0newParam\0percentageChanged\0"
    "p\0doubleChanged\0d\0on_readButton_clicked\0"
    "on_readDefaultButton_clicked\0"
    "on_helpButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamEditDouble[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,
       8,    1,   54,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,
      11,    0,   58,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar, QMetaType::QString, QMetaType::Double,    3,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParamEditDouble::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParamEditDouble *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paramChangedDouble((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: _t->percentageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->doubleChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_readButton_clicked(); break;
        case 4: _t->on_readDefaultButton_clicked(); break;
        case 5: _t->on_helpButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParamEditDouble::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ParamEditDouble.data,
    qt_meta_data_ParamEditDouble,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ParamEditDouble::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamEditDouble::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParamEditDouble.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ParamEditDouble::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
