/****************************************************************************
** Meta object code from reading C++ file 'DestructibleBlock.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../DestructibleBlock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DestructibleBlock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DestructibleBlock_t {
    const uint offsetsAndSize[2];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DestructibleBlock_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DestructibleBlock_t qt_meta_stringdata_DestructibleBlock = {
    {
QT_MOC_LITERAL(0, 17) // "DestructibleBlock"

    },
    "DestructibleBlock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DestructibleBlock[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void DestructibleBlock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject DestructibleBlock::staticMetaObject = { {
    QMetaObject::SuperData::link<MapCell::staticMetaObject>(),
    qt_meta_stringdata_DestructibleBlock.offsetsAndSize,
    qt_meta_data_DestructibleBlock,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DestructibleBlock_t
, QtPrivate::TypeAndForceComplete<DestructibleBlock, std::true_type>



>,
    nullptr
} };


const QMetaObject *DestructibleBlock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DestructibleBlock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DestructibleBlock.stringdata0))
        return static_cast<void*>(this);
    return MapCell::qt_metacast(_clname);
}

int DestructibleBlock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MapCell::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
