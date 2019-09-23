#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include "menu.h"
#include "animation.h"
#include <QFrame>
#include <QTimer>
#include "thumbnail.h"
#include <QVector>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Menu menu;
    QList<QPixmap*> frames;
private:
    Ui::MainWindow *ui;
    //QColorDialog pallete;
    Animation animation;
    QColor currentColor = Qt::white;
    void uncheck_other_brush_buttons(int);
    QVector<Thumbnail*> thumbnails;
    int animation_speed;
    int animation_frame;
    QTimer* animation_timer;
    bool get_fps();

private slots:
    void animate();
    void on_actionHelp_triggered();
    void on_actionNew_Project_triggered();
    void on_actionLoad_triggered();
    void on_actionSave_triggered();
    void on_actionExport_GIF_triggered();

    void on_colorButton_clicked();
    //void on_previewButton_clicked();
    void create_thumbnail_view(QPixmap*, int);
    void update_thumbnail_view(QPixmap*, int);
    void on_add_frame_button_clicked();
    void update_current_active_frame(int, int);

    void on_brush_size_1_button_clicked();

    void on_brush_size_2_button_clicked();

    void on_brush_size_3_button_clicked();

    void on_brush_size_4_button_clicked();
    void reset_thumbnail_view();

    void on_fps_slider_valueChanged(int value);

    void on_penButton_clicked();

    void on_eraserButton_clicked();

    void on_circleButton_clicked();

    void on_squareButton_clicked();

    void on_mirrorXButton_clicked();

    void on_mirrorYButton_clicked();

    void on_mirrorXYButton_clicked();

signals:
    void send_gif_export_request();
    //void test(QFrame &);
    void request_new_frame();
    void send_connect_thumbnail_request(Thumbnail*);
    void send_connect_menu_request(Menu*);
    void send_color(QColor*);
    void send_tool_size(int);
    void send_tool(std::string);

};

#endif // MAINWINDOW_H
