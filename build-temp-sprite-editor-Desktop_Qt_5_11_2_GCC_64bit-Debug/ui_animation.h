/********************************************************************************
** Form generated from reading UI file 'animation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATION_H
#define UI_ANIMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_animation
{
public:

    void setupUi(QWidget *animation)
    {
        if (animation->objectName().isEmpty())
            animation->setObjectName(QStringLiteral("animation"));
        animation->resize(400, 300);

        retranslateUi(animation);

        QMetaObject::connectSlotsByName(animation);
    } // setupUi

    void retranslateUi(QWidget *animation)
    {
        animation->setWindowTitle(QApplication::translate("animation", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class animation: public Ui_animation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATION_H
