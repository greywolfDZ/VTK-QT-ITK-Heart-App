/****************************************************************************
** Meta object code from reading C++ file 'MainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWidget_t {
    QByteArrayData data[19];
    char stringdata0[427];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWidget_t qt_meta_stringdata_MainWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWidget"
QT_MOC_LITERAL(1, 11, 21), // "on_action_X_triggered"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "on_openaction_triggered"
QT_MOC_LITERAL(4, 58, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(5, 91, 5), // "value"
QT_MOC_LITERAL(6, 97, 34), // "on_horizontalSlider_2_valueCh..."
QT_MOC_LITERAL(7, 132, 3), // "val"
QT_MOC_LITERAL(8, 136, 23), // "on_cropaction_triggered"
QT_MOC_LITERAL(9, 160, 24), // "on_actionvalue_triggered"
QT_MOC_LITERAL(10, 185, 22), // "on_actionmax_triggered"
QT_MOC_LITERAL(11, 208, 27), // "on_actionminvalue_triggered"
QT_MOC_LITERAL(12, 236, 26), // "on_actionvalue_2_triggered"
QT_MOC_LITERAL(13, 263, 28), // "on_actionvalue_max_triggered"
QT_MOC_LITERAL(14, 292, 28), // "on_actionvalue_min_triggered"
QT_MOC_LITERAL(15, 321, 26), // "on_actionslice_x_triggered"
QT_MOC_LITERAL(16, 348, 26), // "on_actionslice_y_triggered"
QT_MOC_LITERAL(17, 375, 26), // "on_actionslice_z_triggered"
QT_MOC_LITERAL(18, 402, 24) // "on_actionAbout_triggered"

    },
    "MainWidget\0on_action_X_triggered\0\0"
    "on_openaction_triggered\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_horizontalSlider_2_valueChanged\0"
    "val\0on_cropaction_triggered\0"
    "on_actionvalue_triggered\0"
    "on_actionmax_triggered\0"
    "on_actionminvalue_triggered\0"
    "on_actionvalue_2_triggered\0"
    "on_actionvalue_max_triggered\0"
    "on_actionvalue_min_triggered\0"
    "on_actionslice_x_triggered\0"
    "on_actionslice_y_triggered\0"
    "on_actionslice_z_triggered\0"
    "on_actionAbout_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    1,   91,    2, 0x08 /* Private */,
       6,    1,   94,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_X_triggered(); break;
        case 1: _t->on_openaction_triggered(); break;
        case 2: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_cropaction_triggered(); break;
        case 5: _t->on_actionvalue_triggered(); break;
        case 6: _t->on_actionmax_triggered(); break;
        case 7: _t->on_actionminvalue_triggered(); break;
        case 8: _t->on_actionvalue_2_triggered(); break;
        case 9: _t->on_actionvalue_max_triggered(); break;
        case 10: _t->on_actionvalue_min_triggered(); break;
        case 11: _t->on_actionslice_x_triggered(); break;
        case 12: _t->on_actionslice_y_triggered(); break;
        case 13: _t->on_actionslice_z_triggered(); break;
        case 14: _t->on_actionAbout_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWidget.data,
    qt_meta_data_MainWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
