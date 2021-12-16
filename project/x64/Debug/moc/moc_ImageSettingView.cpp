/****************************************************************************
** Meta object code from reading C++ file 'ImageSettingView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MyView/ImageSettingView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageSettingView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View__DetectTypeSettingWidget_t {
    QByteArrayData data[9];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View__DetectTypeSettingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View__DetectTypeSettingWidget_t qt_meta_stringdata_View__DetectTypeSettingWidget = {
    {
QT_MOC_LITERAL(0, 0, 29), // "View::DetectTypeSettingWidget"
QT_MOC_LITERAL(1, 30, 17), // "radioButtonSignal"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 6), // "status"
QT_MOC_LITERAL(4, 56, 14), // "lineEditSignal"
QT_MOC_LITERAL(5, 71, 5), // "index"
QT_MOC_LITERAL(6, 77, 5), // "value"
QT_MOC_LITERAL(7, 83, 23), // "radioButtonGroupToggled"
QT_MOC_LITERAL(8, 107, 28) // "lineEditGroupEditingFinished"

    },
    "View::DetectTypeSettingWidget\0"
    "radioButtonSignal\0\0status\0lineEditSignal\0"
    "index\0value\0radioButtonGroupToggled\0"
    "lineEditGroupEditingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__DetectTypeSettingWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    2,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   42,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    2,    2,
    QMetaType::Void,

       0        // eod
};

void View::DetectTypeSettingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DetectTypeSettingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->radioButtonSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->lineEditSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->radioButtonGroupToggled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->lineEditGroupEditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DetectTypeSettingWidget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DetectTypeSettingWidget::radioButtonSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DetectTypeSettingWidget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DetectTypeSettingWidget::lineEditSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject View::DetectTypeSettingWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_View__DetectTypeSettingWidget.data,
    qt_meta_data_View__DetectTypeSettingWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *View::DetectTypeSettingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::DetectTypeSettingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View__DetectTypeSettingWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int View::DetectTypeSettingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void View::DetectTypeSettingWidget::radioButtonSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void View::DetectTypeSettingWidget::lineEditSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_View__ImageSettingView_t {
    QByteArrayData data[19];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View__ImageSettingView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View__ImageSettingView_t qt_meta_stringdata_View__ImageSettingView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "View::ImageSettingView"
QT_MOC_LITERAL(1, 23, 17), // "signalCurRunModel"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 11), // "std::string"
QT_MOC_LITERAL(4, 54, 21), // "onLabelDisplayPressed"
QT_MOC_LITERAL(5, 76, 12), // "QMouseEvent*"
QT_MOC_LITERAL(6, 89, 22), // "onLabelDisplayReleased"
QT_MOC_LITERAL(7, 112, 19), // "onLabelDisplayMoved"
QT_MOC_LITERAL(8, 132, 20), // "onLabelDisplayFilter"
QT_MOC_LITERAL(9, 153, 7), // "QEvent*"
QT_MOC_LITERAL(10, 161, 30), // "onComboBoxCurrentCameraChanged"
QT_MOC_LITERAL(11, 192, 28), // "onCamerasDisplayTimerTimeOut"
QT_MOC_LITERAL(12, 221, 16), // "onButtonNewModel"
QT_MOC_LITERAL(13, 238, 17), // "onButtonLoadModel"
QT_MOC_LITERAL(14, 256, 19), // "onRadioButtonSignal"
QT_MOC_LITERAL(15, 276, 6), // "status"
QT_MOC_LITERAL(16, 283, 16), // "onLineEditSignal"
QT_MOC_LITERAL(17, 300, 5), // "index"
QT_MOC_LITERAL(18, 306, 5) // "value"

    },
    "View::ImageSettingView\0signalCurRunModel\0"
    "\0std::string\0onLabelDisplayPressed\0"
    "QMouseEvent*\0onLabelDisplayReleased\0"
    "onLabelDisplayMoved\0onLabelDisplayFilter\0"
    "QEvent*\0onComboBoxCurrentCameraChanged\0"
    "onCamerasDisplayTimerTimeOut\0"
    "onButtonNewModel\0onButtonLoadModel\0"
    "onRadioButtonSignal\0status\0onLineEditSignal\0"
    "index\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View__ImageSettingView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   72,    2, 0x08 /* Private */,
       6,    1,   75,    2, 0x08 /* Private */,
       7,    1,   78,    2, 0x08 /* Private */,
       8,    2,   81,    2, 0x08 /* Private */,
      10,    1,   86,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    1,   92,    2, 0x08 /* Private */,
      16,    2,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 9,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,

       0        // eod
};

void View::ImageSettingView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageSettingView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalCurRunModel((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->onLabelDisplayPressed((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->onLabelDisplayReleased((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->onLabelDisplayMoved((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: { bool _r = _t->onLabelDisplayFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->onComboBoxCurrentCameraChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onCamerasDisplayTimerTimeOut(); break;
        case 7: _t->onButtonNewModel(); break;
        case 8: _t->onButtonLoadModel(); break;
        case 9: _t->onRadioButtonSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onLineEditSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageSettingView::*)(std::string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageSettingView::signalCurRunModel)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject View::ImageSettingView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_View__ImageSettingView.data,
    qt_meta_data_View__ImageSettingView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *View::ImageSettingView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::ImageSettingView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View__ImageSettingView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int View::ImageSettingView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void View::ImageSettingView::signalCurRunModel(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
