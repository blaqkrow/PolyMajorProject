/****************************************************************************
** Meta object code from reading C++ file 'infusionchangeregimen.h'
**
** Created: Fri Aug 23 05:20:54 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infusionchangeregimen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infusionchangeregimen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_infusionChangeRegimen[] = {

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
      23,   22,   22,   22, 0x08,
      45,   22,   22,   22, 0x08,
      67,   22,   22,   22, 0x08,
      89,   22,   22,   22, 0x08,
     107,   22,   22,   22, 0x08,
     129,  124,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_infusionChangeRegimen[] = {
    "infusionChangeRegimen\0\0on_Regimen1_clicked()\0"
    "on_Regimen2_clicked()\0on_Regimen3_clicked()\0"
    "on_Back_clicked()\0UpdateDefaults()\0"
    "arg1\0on_doubleSpinBox_valueChanged(QString)\0"
};

const QMetaObject infusionChangeRegimen::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_infusionChangeRegimen,
      qt_meta_data_infusionChangeRegimen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &infusionChangeRegimen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *infusionChangeRegimen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *infusionChangeRegimen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_infusionChangeRegimen))
        return static_cast<void*>(const_cast< infusionChangeRegimen*>(this));
    return QWidget::qt_metacast(_clname);
}

int infusionChangeRegimen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Regimen1_clicked(); break;
        case 1: on_Regimen2_clicked(); break;
        case 2: on_Regimen3_clicked(); break;
        case 3: on_Back_clicked(); break;
        case 4: UpdateDefaults(); break;
        case 5: on_doubleSpinBox_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
