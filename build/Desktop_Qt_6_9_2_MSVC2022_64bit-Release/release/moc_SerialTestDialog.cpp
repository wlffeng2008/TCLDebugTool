/****************************************************************************
** Meta object code from reading C++ file 'SerialTestDialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../COM/SerialTestDialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SerialTestDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN16SerialTestDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto SerialTestDialog::qt_create_metaobjectdata<qt_meta_tag_ZN16SerialTestDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SerialTestDialog",
        "COMStatusChanged",
        "",
        "bOpen",
        "COMDataIn",
        "data",
        "QWidget*",
        "pSender",
        "COMReplyTimeout",
        "COMModelChanged",
        "strModel",
        "COMReadHugeRamDone",
        "COMWriteHugeRamDone",
        "on_pushButtonScan_clicked",
        "on_pushButtonLoad_clicked",
        "on_pushButtonSave_clicked",
        "on_pushButtonSaveAs_clicked",
        "on_pushButtonHide_clicked",
        "on_checkBoxOpen_clicked",
        "on_comboBoxCOM_currentIndexChanged",
        "index",
        "on_pushButtonSend_clicked",
        "on_pushButtonNew_clicked",
        "on_pushButtonDel_clicked",
        "on_radioButtonRegRead_clicked",
        "on_radioButtonRegWrite_clicked",
        "on_radioButtonRamRead_clicked",
        "on_radioButtonRamWrite_clicked",
        "on_lineEditAddr_textChanged",
        "arg1",
        "on_lineEditLen_textChanged",
        "on_pushButtonLog_clicked",
        "on_lineEditReply_textEdited",
        "on_lineEditWrite_textChanged",
        "on_checkBoxHexData_clicked",
        "on_spinBoxPackIndex_valueChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'COMStatusChanged'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Signal 'COMDataIn'
        QtMocHelpers::SignalData<void(const QByteArray &, QWidget *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 5 }, { 0x80000000 | 6, 7 },
        }}),
        // Signal 'COMReplyTimeout'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'COMModelChanged'
        QtMocHelpers::SignalData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Signal 'COMReadHugeRamDone'
        QtMocHelpers::SignalData<void(const QByteArray &, QWidget *)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 5 }, { 0x80000000 | 6, 7 },
        }}),
        // Signal 'COMWriteHugeRamDone'
        QtMocHelpers::SignalData<void(QWidget *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'on_pushButtonScan_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonLoad_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonSave_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonSaveAs_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonHide_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_checkBoxOpen_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_comboBoxCOM_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 20 },
        }}),
        // Slot 'on_pushButtonSend_clicked'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonNew_clicked'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonDel_clicked'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButtonRegRead_clicked'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButtonRegWrite_clicked'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButtonRamRead_clicked'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_radioButtonRamWrite_clicked'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_lineEditAddr_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'on_lineEditLen_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'on_pushButtonLog_clicked'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_lineEditReply_textEdited'
        QtMocHelpers::SlotData<void(const QString &)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'on_lineEditWrite_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'on_checkBoxHexData_clicked'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_spinBoxPackIndex_valueChanged'
        QtMocHelpers::SlotData<void(int)>(35, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 29 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SerialTestDialog, qt_meta_tag_ZN16SerialTestDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SerialTestDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16SerialTestDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16SerialTestDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16SerialTestDialogE_t>.metaTypes,
    nullptr
} };

void SerialTestDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SerialTestDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->COMStatusChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->COMDataIn((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[2]))); break;
        case 2: _t->COMReplyTimeout(); break;
        case 3: _t->COMModelChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->COMReadHugeRamDone((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[2]))); break;
        case 5: _t->COMWriteHugeRamDone((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 6: _t->on_pushButtonScan_clicked(); break;
        case 7: _t->on_pushButtonLoad_clicked(); break;
        case 8: _t->on_pushButtonSave_clicked(); break;
        case 9: _t->on_pushButtonSaveAs_clicked(); break;
        case 10: _t->on_pushButtonHide_clicked(); break;
        case 11: _t->on_checkBoxOpen_clicked(); break;
        case 12: _t->on_comboBoxCOM_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_pushButtonSend_clicked(); break;
        case 14: _t->on_pushButtonNew_clicked(); break;
        case 15: _t->on_pushButtonDel_clicked(); break;
        case 16: _t->on_radioButtonRegRead_clicked(); break;
        case 17: _t->on_radioButtonRegWrite_clicked(); break;
        case 18: _t->on_radioButtonRamRead_clicked(); break;
        case 19: _t->on_radioButtonRamWrite_clicked(); break;
        case 20: _t->on_lineEditAddr_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->on_lineEditLen_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->on_pushButtonLog_clicked(); break;
        case 23: _t->on_lineEditReply_textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 24: _t->on_lineEditWrite_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->on_checkBoxHexData_clicked(); break;
        case 26: _t->on_spinBoxPackIndex_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SerialTestDialog::*)(bool )>(_a, &SerialTestDialog::COMStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialTestDialog::*)(const QByteArray & , QWidget * )>(_a, &SerialTestDialog::COMDataIn, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialTestDialog::*)()>(_a, &SerialTestDialog::COMReplyTimeout, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialTestDialog::*)(const QString & )>(_a, &SerialTestDialog::COMModelChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialTestDialog::*)(const QByteArray & , QWidget * )>(_a, &SerialTestDialog::COMReadHugeRamDone, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SerialTestDialog::*)(QWidget * )>(_a, &SerialTestDialog::COMWriteHugeRamDone, 5))
            return;
    }
}

const QMetaObject *SerialTestDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialTestDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16SerialTestDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SerialTestDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void SerialTestDialog::COMStatusChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SerialTestDialog::COMDataIn(const QByteArray & _t1, QWidget * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void SerialTestDialog::COMReplyTimeout()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SerialTestDialog::COMModelChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void SerialTestDialog::COMReadHugeRamDone(const QByteArray & _t1, QWidget * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void SerialTestDialog::COMWriteHugeRamDone(QWidget * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
