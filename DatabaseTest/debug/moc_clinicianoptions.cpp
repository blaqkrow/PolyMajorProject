/****************************************************************************
** Meta object code from reading C++ file 'clinicianoptions.h'
**
** Created: Fri Aug 23 05:20:42 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../clinicianoptions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clinicianoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ClinicianOptions[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      35,   17,   17,   17, 0x08,
      55,   17,   17,   17, 0x08,
      73,   17,   17,   17, 0x08,
      89,   17,   17,   17, 0x08,
     122,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ClinicianOptions[] = {
    "ClinicianOptions\0\0UpdateDefaults()\0"
    "on_Select_clicked()\0on_Back_clicked()\0"
    "ClinicianBack()\0ClinicianOptionRegisterPatient()\0"
    "ClinicianCheckHistory()\0"
};

const QMetaObject ClinicianOptions::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ClinicianOptions,
      qt_meta_data_ClinicianOptions, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ClinicianOptions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ClinicianOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ClinicianOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ClinicianOptions))
        return static_cast<void*>(const_cast< ClinicianOptions*>(this));
    return QWidget::qt_metacast(_clname);
}

int ClinicianOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateDefaults(); break;
        case 1: on_Select_clicked(); break;
        case 2: on_Back_clicked(); break;
        case 3: ClinicianBack(); break;
        case 4: ClinicianOptionRegisterPatient(); break;
        case 5: ClinicianCheckHistory(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
