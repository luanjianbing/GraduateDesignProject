/****************************************************************************
** Meta object code from reading C++ file 'QLabelWithMouseEvent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MySubView/QLabelWithMouseEvent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QLabelWithMouseEvent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QLabelWithMouseEvent_t {
    QByteArrayData data[10];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabelWithMouseEvent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabelWithMouseEvent_t qt_meta_stringdata_QLabelWithMouseEvent = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QLabelWithMouseEvent"
QT_MOC_LITERAL(1, 21, 8), // "released"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 44, 2), // "ev"
QT_MOC_LITERAL(5, 47, 7), // "pressed"
QT_MOC_LITERAL(6, 55, 7), // "doubled"
QT_MOC_LITERAL(7, 63, 5), // "moved"
QT_MOC_LITERAL(8, 69, 6), // "filter"
QT_MOC_LITERAL(9, 76, 7) // "QEvent*"

    },
    "QLabelWithMouseEvent\0released\0\0"
    "QMouseEvent*\0ev\0pressed\0doubled\0moved\0"
    "filter\0QEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabelWithMouseEvent[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,
       8,    2,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 9,    2,    2,

       0        // eod
};

void QLabelWithMouseEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabelWithMouseEvent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->released((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->pressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->doubled((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->moved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: { bool _r = _t->filter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabelWithMouseEvent::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabelWithMouseEvent::released)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QLabelWithMouseEvent::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabelWithMouseEvent::pressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QLabelWithMouseEvent::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabelWithMouseEvent::doubled)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QLabelWithMouseEvent::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabelWithMouseEvent::moved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = bool (QLabelWithMouseEvent::*)(QObject * , QEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabelWithMouseEvent::filter)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabelWithMouseEvent::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_QLabelWithMouseEvent.data,
    qt_meta_data_QLabelWithMouseEvent,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabelWithMouseEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabelWithMouseEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabelWithMouseEvent.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int QLabelWithMouseEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QLabelWithMouseEvent::released(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLabelWithMouseEvent::pressed(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QLabelWithMouseEvent::doubled(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QLabelWithMouseEvent::moved(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
bool QLabelWithMouseEvent::filter(QObject * _t1, QEvent * _t2)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
