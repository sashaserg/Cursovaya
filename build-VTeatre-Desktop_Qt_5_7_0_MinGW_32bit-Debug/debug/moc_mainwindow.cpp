/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../VTeatre/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 29), // "on_informationAbout_triggered"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 19), // "on_action_triggered"
QT_MOC_LITERAL(4, 62, 26), // "on_tableWidget_cellClicked"
QT_MOC_LITERAL(5, 89, 3), // "row"
QT_MOC_LITERAL(6, 93, 6), // "column"
QT_MOC_LITERAL(7, 100, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(8, 132, 5), // "index"
QT_MOC_LITERAL(9, 138, 25), // "on_tableSeans_cellClicked"
QT_MOC_LITERAL(10, 164, 23), // "on_dateEdit_dateChanged"
QT_MOC_LITERAL(11, 188, 4), // "date"
QT_MOC_LITERAL(12, 193, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(13, 215, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(14, 239, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(15, 270, 4), // "arg1"
QT_MOC_LITERAL(16, 275, 24), // "on_action_exit_triggered"
QT_MOC_LITERAL(17, 300, 34), // "on_action_statistic_sale_trig..."
QT_MOC_LITERAL(18, 335, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(19, 359, 25), // "on_options_room_triggered"
QT_MOC_LITERAL(20, 385, 28) // "on_action_addScene_triggered"

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
    "on_action_addScene_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    2,   86,    2, 0x08 /* Private */,
       7,    1,   91,    2, 0x08 /* Private */,
       9,    2,   94,    2, 0x08 /* Private */,
      10,    1,   99,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    1,  104,    2, 0x08 /* Private */,
      16,    0,  107,    2, 0x08 /* Private */,
      17,    0,  108,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,
      19,    0,  110,    2, 0x08 /* Private */,
      20,    0,  111,    2, 0x08 /* Private */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
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
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
