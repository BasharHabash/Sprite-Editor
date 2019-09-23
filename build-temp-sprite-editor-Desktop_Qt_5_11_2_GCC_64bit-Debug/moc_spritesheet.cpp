/****************************************************************************
** Meta object code from reading C++ file 'spritesheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../temp-sprite-editor/spritesheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spritesheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SpriteSheet_t {
    QByteArrayData data[25];
    char stringdata0[432];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpriteSheet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpriteSheet_t qt_meta_stringdata_SpriteSheet = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SpriteSheet"
QT_MOC_LITERAL(1, 12, 18), // "send_new_thumbnail"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "QPixmap*"
QT_MOC_LITERAL(4, 41, 22), // "send_updated_thumbnail"
QT_MOC_LITERAL(5, 64, 25), // "send_updated_active_frame"
QT_MOC_LITERAL(6, 90, 29), // "send_reset_thumbnails_request"
QT_MOC_LITERAL(7, 120, 9), // "add_frame"
QT_MOC_LITERAL(8, 130, 15), // "view_thumbnails"
QT_MOC_LITERAL(9, 146, 25), // "recieve_new_frame_request"
QT_MOC_LITERAL(10, 172, 26), // "recieve_gif_export_request"
QT_MOC_LITERAL(11, 199, 16), // "set_active_frame"
QT_MOC_LITERAL(12, 216, 12), // "frame_number"
QT_MOC_LITERAL(13, 229, 33), // "recieve_connect_thumbnail_req..."
QT_MOC_LITERAL(14, 263, 10), // "Thumbnail*"
QT_MOC_LITERAL(15, 274, 13), // "recieve_color"
QT_MOC_LITERAL(16, 288, 7), // "QColor*"
QT_MOC_LITERAL(17, 296, 17), // "recieve_tool_size"
QT_MOC_LITERAL(18, 314, 12), // "recieve_tool"
QT_MOC_LITERAL(19, 327, 11), // "std::string"
QT_MOC_LITERAL(20, 339, 28), // "recieve_connect_menu_request"
QT_MOC_LITERAL(21, 368, 5), // "Menu*"
QT_MOC_LITERAL(22, 374, 17), // "setup_new_project"
QT_MOC_LITERAL(23, 392, 19), // "receive_save_signal"
QT_MOC_LITERAL(24, 412, 19) // "receive_load_signal"

    },
    "SpriteSheet\0send_new_thumbnail\0\0"
    "QPixmap*\0send_updated_thumbnail\0"
    "send_updated_active_frame\0"
    "send_reset_thumbnails_request\0add_frame\0"
    "view_thumbnails\0recieve_new_frame_request\0"
    "recieve_gif_export_request\0set_active_frame\0"
    "frame_number\0recieve_connect_thumbnail_request\0"
    "Thumbnail*\0recieve_color\0QColor*\0"
    "recieve_tool_size\0recieve_tool\0"
    "std::string\0recieve_connect_menu_request\0"
    "Menu*\0setup_new_project\0receive_save_signal\0"
    "receive_load_signal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpriteSheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       4,    2,  104,    2, 0x06 /* Public */,
       5,    2,  109,    2, 0x06 /* Public */,
       6,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  115,    2, 0x0a /* Public */,
       8,    0,  116,    2, 0x0a /* Public */,
       9,    0,  117,    2, 0x0a /* Public */,
      10,    0,  118,    2, 0x0a /* Public */,
      11,    1,  119,    2, 0x0a /* Public */,
      13,    1,  122,    2, 0x0a /* Public */,
      15,    1,  125,    2, 0x0a /* Public */,
      17,    1,  128,    2, 0x0a /* Public */,
      18,    1,  131,    2, 0x0a /* Public */,
      20,    1,  134,    2, 0x0a /* Public */,
      22,    1,  137,    2, 0x0a /* Public */,
      23,    0,  140,    2, 0x0a /* Public */,
      24,    0,  141,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SpriteSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpriteSheet *_t = static_cast<SpriteSheet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_new_thumbnail((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->send_updated_thumbnail((*reinterpret_cast< QPixmap*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->send_updated_active_frame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->send_reset_thumbnails_request(); break;
        case 4: _t->add_frame(); break;
        case 5: _t->view_thumbnails(); break;
        case 6: _t->recieve_new_frame_request(); break;
        case 7: _t->recieve_gif_export_request(); break;
        case 8: _t->set_active_frame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->recieve_connect_thumbnail_request((*reinterpret_cast< Thumbnail*(*)>(_a[1]))); break;
        case 10: _t->recieve_color((*reinterpret_cast< QColor*(*)>(_a[1]))); break;
        case 11: _t->recieve_tool_size((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->recieve_tool((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 13: _t->recieve_connect_menu_request((*reinterpret_cast< Menu*(*)>(_a[1]))); break;
        case 14: _t->setup_new_project((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->receive_save_signal(); break;
        case 16: _t->receive_load_signal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Thumbnail* >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Menu* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpriteSheet::*)(QPixmap * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteSheet::send_new_thumbnail)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SpriteSheet::*)(QPixmap * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteSheet::send_updated_thumbnail)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SpriteSheet::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteSheet::send_updated_active_frame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SpriteSheet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpriteSheet::send_reset_thumbnails_request)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SpriteSheet::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_SpriteSheet.data,
      qt_meta_data_SpriteSheet,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SpriteSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpriteSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpriteSheet.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int SpriteSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void SpriteSheet::send_new_thumbnail(QPixmap * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SpriteSheet::send_updated_thumbnail(QPixmap * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SpriteSheet::send_updated_active_frame(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SpriteSheet::send_reset_thumbnails_request()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
