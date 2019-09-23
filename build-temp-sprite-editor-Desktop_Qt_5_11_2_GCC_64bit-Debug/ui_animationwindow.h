/********************************************************************************
** Form generated from reading UI file 'animationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANIMATIONWINDOW_H
#define UI_ANIMATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AnimationWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *AnimationWindow)
    {
        if (AnimationWindow->objectName().isEmpty())
            AnimationWindow->setObjectName(QStringLiteral("AnimationWindow"));
        AnimationWindow->resize(400, 300);
        label = new QLabel(AnimationWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 401, 251));
        label->setStyleSheet(QStringLiteral("background-color: rgb(52, 101, 164);"));

        retranslateUi(AnimationWindow);

        QMetaObject::connectSlotsByName(AnimationWindow);
    } // setupUi

    void retranslateUi(QDialog *AnimationWindow)
    {
        AnimationWindow->setWindowTitle(QApplication::translate("AnimationWindow", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnimationWindow: public Ui_AnimationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANIMATIONWINDOW_H
