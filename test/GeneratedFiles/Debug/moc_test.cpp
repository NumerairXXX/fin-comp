/****************************************************************************
** Meta object code from reading C++ file 'test.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_test_t {
    QByteArrayData data[11];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_test_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_test_t qt_meta_stringdata_test = {
    {
QT_MOC_LITERAL(0, 0, 4), // "test"
QT_MOC_LITERAL(1, 5, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 22), // "on_excelButton_clicked"
QT_MOC_LITERAL(4, 49, 23), // "on_searchButton_clicked"
QT_MOC_LITERAL(5, 73, 35), // "on_groupComboBox_currentTextC..."
QT_MOC_LITERAL(6, 109, 4), // "text"
QT_MOC_LITERAL(7, 114, 31), // "on_groupTable_cellDoubleClicked"
QT_MOC_LITERAL(8, 146, 3), // "row"
QT_MOC_LITERAL(9, 150, 6), // "column"
QT_MOC_LITERAL(10, 157, 13) // "start_process"

    },
    "test\0on_okButton_clicked\0\0"
    "on_excelButton_clicked\0on_searchButton_clicked\0"
    "on_groupComboBox_currentTextChanged\0"
    "text\0on_groupTable_cellDoubleClicked\0"
    "row\0column\0start_process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_test[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    2,   50,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void,

       0        // eod
};

void test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        test *_t = static_cast<test *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_okButton_clicked(); break;
        case 1: _t->on_excelButton_clicked(); break;
        case 2: _t->on_searchButton_clicked(); break;
        case 3: _t->on_groupComboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_groupTable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->start_process(); break;
        default: ;
        }
    }
}

const QMetaObject test::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_test.data,
      qt_meta_data_test,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *test::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_test.stringdata0))
        return static_cast<void*>(const_cast< test*>(this));
    return QWidget::qt_metacast(_clname);
}

int test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
