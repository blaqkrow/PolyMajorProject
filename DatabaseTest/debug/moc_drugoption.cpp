/****************************************************************************
** Meta object code from reading C++ file 'drugoption.h'
**
** Created: Fri Aug 23 05:20:45 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../drugoption.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drugoption.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DrugOption[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      46,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DrugOption[] = {
    "DrugOption\0\0on_Back_clicked()\0"
    "on_Ok_clicked()\0UpdateDefaults()\0"
};

const QMetaObject DrugOption::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrugOption,
      qt_meta_data_DrugOption, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DrugOption::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DrugOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DrugOption::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrugOption))
        return static_cast<void*>(const_cast< DrugOption*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrugOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Back_clicked(); break;
        case 1: on_Ok_clicked(); break;
        case 2: UpdateDefaults(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
