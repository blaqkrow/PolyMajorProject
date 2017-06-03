/****************************************************************************
** Meta object code from reading C++ file 'changeipadd.h'
**
** Created: Fri Aug 23 05:20:49 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../changeipadd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changeipadd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChangeIpadd[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      30,   12,   12,   12, 0x08,
      48,   12,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ChangeIpadd[] = {
    "ChangeIpadd\0\0UpdateDefaults()\0"
    "on_back_clicked()\0on_Clear_clicked()\0"
    "on_Set_clicked()\0"
};

const QMetaObject ChangeIpadd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ChangeIpadd,
      qt_meta_data_ChangeIpadd, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChangeIpadd::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChangeIpadd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChangeIpadd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeIpadd))
        return static_cast<void*>(const_cast< ChangeIpadd*>(this));
    return QWidget::qt_metacast(_clname);
}

int ChangeIpadd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: UpdateDefaults(); break;
        case 1: on_back_clicked(); break;
        case 2: on_Clear_clicked(); break;
        case 3: on_Set_clicked(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
