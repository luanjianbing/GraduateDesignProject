/****************************************************************************
** Meta object code from reading C++ file 'MyView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MyView/MyView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View__MyView_t {
    QByteArrayData data[11];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View__MyView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View__MyView_t qt_meta_stringdata_View__MyView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "View::MyView"
QT_MOC_LITERAL(1, 13, 11), // "signalClose"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20), // "onActionImageSetting"
QT_MOC_LITERAL(4, 47, 14), // "onActionSignal"
QT_MOC_LITERAL(5, 62, 19), // "onSignalCurRunModel"
QT_MOC_LITERAL(6, 82, 11), // "std::string"
QT_MOC_LITERAL(7, 94, 30), // "onListWidgetCamerasItemPressed"
QT_MOC_LITERAL(8, 125, 25), // "onButtonToLoadOrderNumber"
QT_MOC_LITERAL(9, 151, 30), // "onComboBoxLoadOrderNumberUsers"
QT_MOC_LITERAL(10, 182, 18) // "onButtonToLoadUser"

    },
    "View::MyView\0signalClose\0\0"
    "onActionImageSetting\0onActionSignal\0"
    "onSignalCurRunModel\0std::string\0"
    "onListWidgetCamerasItemPressed\0"
    "onButtonToLoadOrderNumber\0"
    "onComboBoxLoadOrderNumberUsers\0"
    "onButtonToLoadUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__MyView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void View::MyView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalClose(); break;
        case 1: _t->onActionImageSetting(); break;
        case 2: _t->onActionSignal(); break;
        case 3: _t->onSignalCurRunModel((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 4: _t->onListWidgetCamerasItemPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onButtonToLoadOrderNumber(); break;
        case 6: _t->onComboBoxLoadOrderNumberUsers((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onButtonToLoadUser(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyView::signalClose)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject View::MyView::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_View__MyView.data,
    qt_meta_data_View__MyView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *View::MyView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::MyView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View__MyView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::MyView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void View::MyView::signalClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
