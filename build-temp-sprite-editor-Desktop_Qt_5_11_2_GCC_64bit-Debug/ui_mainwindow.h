/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *actionSave;
    QAction *actionExport_GIF;
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionHelp;
    QWidget *centralWidget;
    QPushButton *brush_size_1_button;
    QPushButton *brush_size_2_button;
    QPushButton *brush_size_3_button;
    QPushButton *brush_size_4_button;
    QScrollArea *frames_scroll_area;
    QWidget *scrollAreaWidgetContents;
    QPushButton *add_frame_button;
    QLabel *tool_size_label;
    QGroupBox *groupBox;
    QPushButton *penButton;
    QPushButton *eraserButton;
    QPushButton *circleButton;
    QPushButton *squareButton;
    QPushButton *mirrorXButton;
    QPushButton *mirrorYButton;
    QPushButton *mirrorXYButton;
    QFrame *canvas;
    QLabel *animation_preview;
    QSlider *fps_slider;
    QLabel *fps_label;
    QLabel *label_3;
    QPushButton *colorButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(581, 444);
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExport_GIF = new QAction(MainWindow);
        actionExport_GIF->setObjectName(QStringLiteral("actionExport_GIF"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        brush_size_1_button = new QPushButton(centralWidget);
        brush_size_1_button->setObjectName(QStringLiteral("brush_size_1_button"));
        brush_size_1_button->setGeometry(QRect(10, 20, 31, 26));
        brush_size_2_button = new QPushButton(centralWidget);
        brush_size_2_button->setObjectName(QStringLiteral("brush_size_2_button"));
        brush_size_2_button->setGeometry(QRect(40, 20, 31, 26));
        brush_size_3_button = new QPushButton(centralWidget);
        brush_size_3_button->setObjectName(QStringLiteral("brush_size_3_button"));
        brush_size_3_button->setGeometry(QRect(70, 20, 31, 26));
        brush_size_4_button = new QPushButton(centralWidget);
        brush_size_4_button->setObjectName(QStringLiteral("brush_size_4_button"));
        brush_size_4_button->setGeometry(QRect(100, 20, 31, 26));
        frames_scroll_area = new QScrollArea(centralWidget);
        frames_scroll_area->setObjectName(QStringLiteral("frames_scroll_area"));
        frames_scroll_area->setGeometry(QRect(10, 300, 561, 81));
        frames_scroll_area->setAutoFillBackground(true);
        frames_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frames_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        frames_scroll_area->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 559, 65));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        scrollAreaWidgetContents->setSizeIncrement(QSize(64, 0));
        add_frame_button = new QPushButton(scrollAreaWidgetContents);
        add_frame_button->setObjectName(QStringLiteral("add_frame_button"));
        add_frame_button->setGeometry(QRect(0, 0, 64, 64));
        add_frame_button->setCursor(QCursor(Qt::CrossCursor));
        frames_scroll_area->setWidget(scrollAreaWidgetContents);
        tool_size_label = new QLabel(centralWidget);
        tool_size_label->setObjectName(QStringLiteral("tool_size_label"));
        tool_size_label->setGeometry(QRect(10, 0, 121, 18));
        tool_size_label->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 50, 111, 241));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(238, 238, 236, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(246, 246, 245, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(119, 119, 118, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(159, 159, 157, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        groupBox->setPalette(palette);
        groupBox->setAutoFillBackground(true);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        penButton = new QPushButton(groupBox);
        penButton->setObjectName(QStringLiteral("penButton"));
        penButton->setGeometry(QRect(10, 30, 89, 25));
        eraserButton = new QPushButton(groupBox);
        eraserButton->setObjectName(QStringLiteral("eraserButton"));
        eraserButton->setGeometry(QRect(10, 60, 89, 25));
        circleButton = new QPushButton(groupBox);
        circleButton->setObjectName(QStringLiteral("circleButton"));
        circleButton->setGeometry(QRect(10, 90, 89, 25));
        squareButton = new QPushButton(groupBox);
        squareButton->setObjectName(QStringLiteral("squareButton"));
        squareButton->setGeometry(QRect(10, 120, 89, 25));
        mirrorXButton = new QPushButton(groupBox);
        mirrorXButton->setObjectName(QStringLiteral("mirrorXButton"));
        mirrorXButton->setGeometry(QRect(10, 150, 89, 25));
        mirrorYButton = new QPushButton(groupBox);
        mirrorYButton->setObjectName(QStringLiteral("mirrorYButton"));
        mirrorYButton->setGeometry(QRect(10, 180, 89, 25));
        mirrorXYButton = new QPushButton(groupBox);
        mirrorXYButton->setObjectName(QStringLiteral("mirrorXYButton"));
        mirrorXYButton->setGeometry(QRect(10, 210, 89, 25));
        canvas = new QFrame(centralWidget);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setGeometry(QRect(140, 20, 256, 256));
        canvas->setCursor(QCursor(Qt::CrossCursor));
        canvas->setFrameShape(QFrame::StyledPanel);
        canvas->setFrameShadow(QFrame::Raised);
        animation_preview = new QLabel(centralWidget);
        animation_preview->setObjectName(QStringLiteral("animation_preview"));
        animation_preview->setGeometry(QRect(420, 40, 131, 91));
        animation_preview->setAutoFillBackground(false);
        animation_preview->setStyleSheet(QStringLiteral("border: 1px solid #000000;"));
        animation_preview->setAlignment(Qt::AlignCenter);
        animation_preview->setWordWrap(true);
        fps_slider = new QSlider(centralWidget);
        fps_slider->setObjectName(QStringLiteral("fps_slider"));
        fps_slider->setGeometry(QRect(410, 180, 160, 16));
        fps_slider->setMinimum(1);
        fps_slider->setMaximum(12);
        fps_slider->setSliderPosition(2);
        fps_slider->setOrientation(Qt::Horizontal);
        fps_label = new QLabel(centralWidget);
        fps_label->setObjectName(QStringLiteral("fps_label"));
        fps_label->setGeometry(QRect(410, 160, 161, 20));
        fps_label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 0, 256, 18));
        label_3->setAlignment(Qt::AlignCenter);
        colorButton = new QPushButton(centralWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setGeometry(QRect(440, 250, 101, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 581, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_Project);
        menuFile->addSeparator();
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport_GIF);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Project->setText(QApplication::translate("MainWindow", "New Project", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save Project", nullptr));
        actionExport_GIF->setText(QApplication::translate("MainWindow", "Export GIF", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load Project", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", nullptr));
        brush_size_1_button->setText(QApplication::translate("MainWindow", "x1", nullptr));
        brush_size_2_button->setText(QApplication::translate("MainWindow", "x2", nullptr));
        brush_size_3_button->setText(QApplication::translate("MainWindow", "x3", nullptr));
        brush_size_4_button->setText(QApplication::translate("MainWindow", "x4", nullptr));
        add_frame_button->setText(QApplication::translate("MainWindow", "New\n"
"Frame", nullptr));
        tool_size_label->setText(QApplication::translate("MainWindow", "Tool Size:", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        penButton->setText(QApplication::translate("MainWindow", "Pen", nullptr));
        eraserButton->setText(QApplication::translate("MainWindow", "Eraser", nullptr));
        circleButton->setText(QApplication::translate("MainWindow", "Circle", nullptr));
        squareButton->setText(QApplication::translate("MainWindow", "Square", nullptr));
        mirrorXButton->setText(QApplication::translate("MainWindow", "MirrorX", nullptr));
        mirrorYButton->setText(QApplication::translate("MainWindow", "MirrorY", nullptr));
        mirrorXYButton->setText(QApplication::translate("MainWindow", "MirrorXY", nullptr));
        animation_preview->setText(QString());
        fps_label->setText(QApplication::translate("MainWindow", "FPS: 2", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Canvas", nullptr));
        colorButton->setText(QApplication::translate("MainWindow", "Choose Color", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
