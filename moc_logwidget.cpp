/****************************************************************************
** Meta object code from reading C++ file 'logwidget.h'
**
** Created: Tue Apr 16 20:49:46 2024
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "logwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      19,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   10,   10,   10, 0x0a,
      53,   10,   10,   10, 0x0a,
      70,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LogWidget[] = {
    "LogWidget\0\0login()\0close_window()\0"
    "pb_clear_clicked()\0pb_log_clicked()\0"
    "pb_0_clicked()\0"
};

const QMetaObject LogWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogWidget,
      qt_meta_data_LogWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogWidget))
        return static_cast<void*>(const_cast< LogWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int LogWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: login(); break;
        case 1: close_window(); break;
        case 2: pb_clear_clicked(); break;
        case 3: pb_log_clicked(); break;
        case 4: pb_0_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LogWidget::login()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LogWidget::close_window()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
