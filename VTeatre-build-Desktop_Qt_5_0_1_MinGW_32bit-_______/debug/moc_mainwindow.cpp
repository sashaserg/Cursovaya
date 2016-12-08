/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VTeatre/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[433];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 29),
QT_MOC_LITERAL(2, 41, 0),
QT_MOC_LITERAL(3, 42, 19),
QT_MOC_LITERAL(4, 62, 26),
QT_MOC_LITERAL(5, 89, 3),
QT_MOC_LITERAL(6, 93, 6),
QT_MOC_LITERAL(7, 100, 31),
QT_MOC_LITERAL(8, 132, 5),
QT_MOC_LITERAL(9, 138, 25),
QT_MOC_LITERAL(10, 164, 23),
QT_MOC_LITERAL(11, 188, 4),
QT_MOC_LITERAL(12, 193, 21),
QT_MOC_LITERAL(13, 215, 23),
QT_MOC_LITERAL(14, 239, 30),
QT_MOC_LITERAL(15, 270, 4),
QT_MOC_LITERAL(16, 275, 24),
QT_MOC_LITERAL(17, 300, 34),
QT_MOC_LITERAL(18, 335, 23),
QT_MOC_LITERAL(19, 359, 25),
QT_MOC_LITERAL(20, 385, 28),
QT_MOC_LITERAL(21, 414, 17)
    },
    "MainWindow\0on_informationAbout_triggered\0"
    "\0on_action_triggered\0on_tableWidget_cellClicked\0"
    "row\0column\0on_comboBox_currentIndexChanged\0"
    "index\0on_tableSeans_cellClicked\0"
    "on_dateEdit_dateChanged\0date\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "on_action_exit_triggered\0"
    "on_action_statistic_sale_triggered\0"
    "on_pushButton_3_clicked\0"
    "on_options_room_triggered\0"
    "on_action_addScene_triggered\0"
    "on_action_hovered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08,
       3,    0,   95,    2, 0x08,
       4,    2,   96,    2, 0x08,
       7,    1,  101,    2, 0x08,
       9,    2,  104,    2, 0x08,
      10,    1,  109,    2, 0x08,
      12,    0,  112,    2, 0x08,
      13,    0,  113,    2, 0x08,
      14,    1,  114,    2, 0x08,
      16,    0,  117,    2, 0x08,
      17,    0,  118,    2, 0x08,
      18,    0,  119,    2, 0x08,
      19,    0,  120,    2, 0x08,
      20,    0,  121,    2, 0x08,
      21,    0,  122,    2, 0x08,
       7,    1,  123,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::QDate,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_informationAbout_triggered(); break;
        case 1: _t->on_action_triggered(); break;
        case 2: _t->on_tableWidget_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_tableSeans_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_dateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_action_exit_triggered(); break;
        case 10: _t->on_action_statistic_sale_triggered(); break;
        case 11: _t->on_pushButton_3_clicked(); break;
        case 12: _t->on_options_room_triggered(); break;
        case 13: _t->on_action_addScene_triggered(); break;
        case 14: _t->on_action_hovered(); break;
        case 15: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
