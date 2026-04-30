/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[2];
    char stringdata5[14];
    char stringdata6[4];
    char stringdata7[9];
    char stringdata8[6];
    char stringdata9[23];
    char stringdata10[22];
    char stringdata11[22];
    char stringdata12[28];
    char stringdata13[15];
    char stringdata14[8];
    char stringdata15[10];
    char stringdata16[26];
    char stringdata17[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 9),  // "affichage"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 8),  // "Etudiant"
        QT_MOC_LITERAL(31, 1),  // "e"
        QT_MOC_LITERAL(33, 13),  // "voirListeMenu"
        QT_MOC_LITERAL(47, 3),  // "pos"
        QT_MOC_LITERAL(51, 8),  // "Chercher"
        QT_MOC_LITERAL(60, 5),  // "texte"
        QT_MOC_LITERAL(66, 22),  // "on_btnNettoyer_clicked"
        QT_MOC_LITERAL(89, 21),  // "on_btnAjouter_clicked"
        QT_MOC_LITERAL(111, 21),  // "on_btnEffacer_clicked"
        QT_MOC_LITERAL(133, 27),  // "on_btnToutSupprimer_clicked"
        QT_MOC_LITERAL(161, 14),  // "enregistrerCSV"
        QT_MOC_LITERAL(176, 7),  // "fichier"
        QT_MOC_LITERAL(184, 9),  // "ouvrirCSV"
        QT_MOC_LITERAL(194, 25),  // "on_btnEnregistrer_clicked"
        QT_MOC_LITERAL(220, 20)   // "on_btnOuvrir_clicked"
    },
    "MainWindow",
    "affichage",
    "",
    "Etudiant",
    "e",
    "voirListeMenu",
    "pos",
    "Chercher",
    "texte",
    "on_btnNettoyer_clicked",
    "on_btnAjouter_clicked",
    "on_btnEffacer_clicked",
    "on_btnToutSupprimer_clicked",
    "enregistrerCSV",
    "fichier",
    "ouvrirCSV",
    "on_btnEnregistrer_clicked",
    "on_btnOuvrir_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       1,    1,   87,    2, 0x08,    2 /* Private */,
       5,    1,   90,    2, 0x08,    4 /* Private */,
       7,    1,   93,    2, 0x08,    6 /* Private */,
       9,    0,   96,    2, 0x08,    8 /* Private */,
      10,    0,   97,    2, 0x08,    9 /* Private */,
      11,    0,   98,    2, 0x08,   10 /* Private */,
      12,    0,   99,    2, 0x08,   11 /* Private */,
      13,    1,  100,    2, 0x08,   12 /* Private */,
      15,    1,  103,    2, 0x08,   14 /* Private */,
      16,    0,  106,    2, 0x08,   16 /* Private */,
      17,    0,  107,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'affichage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'affichage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Etudiant &, std::false_type>,
        // method 'voirListeMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'Chercher'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_btnNettoyer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAjouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnEffacer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnToutSupprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enregistrerCSV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'ouvrirCSV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_btnEnregistrer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnOuvrir_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->affichage(); break;
        case 1: _t->affichage((*reinterpret_cast< std::add_pointer_t<Etudiant>>(_a[1]))); break;
        case 2: _t->voirListeMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 3: _t->Chercher((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_btnNettoyer_clicked(); break;
        case 5: _t->on_btnAjouter_clicked(); break;
        case 6: _t->on_btnEffacer_clicked(); break;
        case 7: _t->on_btnToutSupprimer_clicked(); break;
        case 8: _t->enregistrerCSV((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->ouvrirCSV((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->on_btnEnregistrer_clicked(); break;
        case 11: _t->on_btnOuvrir_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
