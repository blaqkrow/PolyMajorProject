/****************************************************************************
** Meta object code from reading C++ file 'administratorgui.h'
**
** Created: Fri Aug 23 05:20:47 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../administratorgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'administratorgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_administratorGui[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      35,   17,   17,   17, 0x08,
      60,   17,   17,   17, 0x08,
      83,   17,   17,   17, 0x08,
     107,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_administratorGui[] = {
    "administratorGui\0\0UpdateDefaults()\0"
    "AdminRegisterClinician()\0"
    "AdminChangeIPAddress()\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

const QMetaObject administratorGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_administratorGui,
      qt_meta_data_administratorGui, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &administratorGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *administratorGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *administratorGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_administratorGui))
        return static_cast<void*>(const_cast< administratorGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int administratorGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateDefaults(); break;
        case 1: AdminRegisterClinician(); break;
        case 2: AdminChangeIPAddress(); break;
        case 3: on_pushButton_clicked(); break;
        case 4: on_pushButton_2_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
