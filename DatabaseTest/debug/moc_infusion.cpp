/****************************************************************************
** Meta object code from reading C++ file 'infusion.h'
**
** Created: Fri Aug 23 05:20:52 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infusion.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infusion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Infusion[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,
      64,    9,    9,    9, 0x08,
      90,    9,    9,    9, 0x08,
     117,    9,    9,    9, 0x08,
     134,    9,    9,    9, 0x0a,
     142,    9,    9,    9, 0x0a,
     149,    9,    9,    9, 0x0a,
     157,    9,    9,    9, 0x0a,
     182,    9,    9,    9, 0x0a,
     204,    9,    9,    9, 0x0a,
     225,    9,    9,    9, 0x0a,
     249,    9,    9,    9, 0x0a,
     270,    9,    9,    9, 0x0a,
     290,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Infusion[] = {
    "Infusion\0\0on_PauseInfusion_clicked()\0"
    "on_ChangeRegimen_clicked()\0"
    "on_StopInfuison_clicked()\0"
    "on_StartInfusion_clicked()\0UpdateDefaults()\0"
    "start()\0stop()\0pause()\0UpdateInfusingDataFreq()\0"
    "UpdatePauseDataFreq()\0UpdateStopDataFreq()\0"
    "UpdateInfusingDataTCP()\0UpdatePauseDataTCP()\0"
    "UpdateStopDataTCP()\0StopInfusion()\0"
};

const QMetaObject Infusion::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Infusion,
      qt_meta_data_Infusion, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Infusion::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Infusion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Infusion::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Infusion))
        return static_cast<void*>(const_cast< Infusion*>(this));
    return QWidget::qt_metacast(_clname);
}

int Infusion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_PauseInfusion_clicked(); break;
        case 1: on_ChangeRegimen_clicked(); break;
        case 2: on_StopInfuison_clicked(); break;
        case 3: on_StartInfusion_clicked(); break;
        case 4: UpdateDefaults(); break;
        case 5: start(); break;
        case 6: stop(); break;
        case 7: pause(); break;
        case 8: UpdateInfusingDataFreq(); break;
        case 9: UpdatePauseDataFreq(); break;
        case 10: UpdateStopDataFreq(); break;
        case 11: UpdateInfusingDataTCP(); break;
        case 12: UpdatePauseDataTCP(); break;
        case 13: UpdateStopDataTCP(); break;
        case 14: StopInfusion(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
