/****************************************************************************
** Meta object code from reading C++ file 'qt1.h'
**
** Created: Wed Apr 17 15:01:19 2024
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qt1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qt1[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      16,    4,    4,    4, 0x0a,
      27,    4,    4,    4, 0x0a,
      42,    4,    4,    4, 0x0a,
      59,    4,    4,    4, 0x0a,
      77,    4,    4,    4, 0x0a,
     100,    4,    4,    4, 0x0a,
     115,    4,    4,    4, 0x0a,
     135,    4,    4,    4, 0x0a,
     149,    4,    4,    4, 0x0a,
     160,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qt1[] = {
    "Qt1\0\0fun_time()\0fun_open()\0fun_cap_open()\0"
    "fun_take_photo()\0fun_refresh_pic()\0"
    "update_show_Resistor()\0fun_change_t()\0"
    "fun_open_resistor()\0display_pic()\0"
    "fun_prev()\0fun_pic()\0"
};

const QMetaObject Qt1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qt1,
      qt_meta_data_Qt1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qt1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qt1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qt1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qt1))
        return static_cast<void*>(const_cast< Qt1*>(this));
    if (!strcmp(_clname, "Ui_Qt1"))
        return static_cast< Ui_Qt1*>(const_cast< Qt1*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qt1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fun_time(); break;
        case 1: fun_open(); break;
        case 2: fun_cap_open(); break;
        case 3: fun_take_photo(); break;
        case 4: fun_refresh_pic(); break;
        case 5: update_show_Resistor(); break;
        case 6: fun_change_t(); break;
        case 7: fun_open_resistor(); break;
        case 8: display_pic(); break;
        case 9: fun_prev(); break;
        case 10: fun_pic(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
