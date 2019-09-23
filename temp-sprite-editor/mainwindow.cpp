#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include "thumbnail.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->brush_size_1_button->setCheckable(true);
    ui->brush_size_2_button->setCheckable(true);
    ui->brush_size_3_button->setCheckable(true);
    ui->brush_size_4_button->setCheckable(true);
    ui->brush_size_1_button->setChecked(true);
    ui->penButton->setCheckable(true);
    ui->eraserButton->setCheckable(true);
    ui->circleButton->setCheckable(true);
    ui->squareButton->setCheckable(true);
    ui->mirrorXButton->setCheckable(true);
    ui->mirrorYButton->setCheckable(true);
    ui->mirrorXYButton->setCheckable(true);

    ui->penButton->setChecked(true);

    ui->canvas->setStyleSheet("border: 1px solid black; background-image: url(:/images/canvas-background-light.png);background-repeat: repeat-xy;");

    animation_frame = 0;
    get_fps();
    animation_timer = new QTimer(this);
    animation_timer->setSingleShot(true);
    QObject::connect(animation_timer, SIGNAL(timeout()), this, SLOT(animate()));

    animate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animate()
{
    if(get_fps())
    {
        int h = ui->animation_preview->height();
        int w = ui->animation_preview->width();
        if (animation_frame < frames.size() -1)
        {
            animation_frame ++;
        }
        else
        {
            animation_frame = 0;
        }
        if(frames.size()>=1)
            ui->animation_preview->setPixmap(frames[animation_frame]->scaled(w,h,Qt::KeepAspectRatio));
    }
    animation_timer->start(animation_speed);
}

bool MainWindow::get_fps()
{
    animation_speed = 1000/ui->fps_slider->value();
    return true;
}


void MainWindow::create_thumbnail_view(QPixmap * map, int id){
    if(id > 1){
        int temp = (id - 1);
        QString previous_id = std::to_string(temp).c_str();
        Thumbnail * previous_thumbnail = ui->scrollAreaWidgetContents->findChild<Thumbnail*>(previous_id);
        previous_thumbnail->setStyleSheet("border: 0px solid red");
    }
    Thumbnail * label = new Thumbnail(ui->scrollAreaWidgetContents, Qt::WindowFlags(), id);
    int x = ui->add_frame_button->pos().x();
    int y = ui->add_frame_button->pos().y();
    label->setGeometry(x, y, 64, 64);
    const char * name =  std::to_string(id).c_str();
    label->setObjectName(name);
    label->setPixmap(map->scaled(64, 64));
    label->setParent(ui->scrollAreaWidgetContents);
    label->show();
    ui->add_frame_button->setGeometry(x+65,y, 64, 64);
    label->setStyleSheet("border: 1px solid red");
    thumbnails.push_back(label);
    frames.append(map);
    if(frames.size()>=1)
       emit send_connect_thumbnail_request(label);
}

void MainWindow::on_actionExport_GIF_triggered(){
    emit send_gif_export_request();
}

void MainWindow::reset_thumbnail_view(){
    for(int i = 0; i < thumbnails.size(); i++){
        thumbnails[i]->~Thumbnail();
    }
    thumbnails.clear();
    ui->add_frame_button->setGeometry(0, 0, 64, 64);
}

void MainWindow::update_thumbnail_view(QPixmap * map, int id){
    const char * name =  std::to_string(id).c_str();
    Thumbnail * label = ui->scrollAreaWidgetContents->findChild<Thumbnail*>(name);
    label->setPixmap(map->scaled(64, 64));
    //label->show();
}

void MainWindow::update_current_active_frame(int old_id, int new_id){
    QString previous_id = std::to_string(old_id).c_str();
    Thumbnail * previous_thumbnail = ui->scrollAreaWidgetContents->findChild<Thumbnail*>(previous_id);
    previous_thumbnail->setStyleSheet("border: 0px solid red");

    QString current_id = std::to_string(new_id).c_str();
    Thumbnail * current_thumbnail = ui->scrollAreaWidgetContents->findChild<Thumbnail*>(current_id);
    current_thumbnail->setStyleSheet("border: 1px solid red");
}


void MainWindow::on_add_frame_button_clicked(){
    request_new_frame();
}

void MainWindow::on_actionHelp_triggered()
{
    menu.help();
}

void MainWindow::on_actionSave_triggered()
{
    menu.save();
}

void MainWindow::on_actionLoad_triggered()
{
    frames.clear();
    menu.load();
}

void MainWindow::on_actionNew_Project_triggered()
{
    frames.clear();
    menu.new_sprite();
}

void MainWindow::on_colorButton_clicked()
{
    currentColor = QColorDialog::getColor(currentColor,this);
    emit send_color(&currentColor);
}



void MainWindow::uncheck_other_brush_buttons(int newBrushSize)
{
    if(newBrushSize != 1 && ui->brush_size_1_button->isChecked())
    {
       ui->brush_size_1_button->setChecked(false);
    }
    if(newBrushSize != 2 && ui->brush_size_2_button->isChecked())
    {
       ui->brush_size_2_button->setChecked(false);
    }
    if(newBrushSize != 3 && ui->brush_size_3_button->isChecked())
    {
       ui->brush_size_3_button->setChecked(false);
    }
    if(newBrushSize != 4 && ui->brush_size_4_button->isChecked())
    {
       ui->brush_size_4_button->setChecked(false);
    }
}

void MainWindow::on_brush_size_1_button_clicked()
{
    emit send_tool_size(1);
    ui->brush_size_1_button->setChecked(true);
    uncheck_other_brush_buttons(1);
}

void MainWindow::on_brush_size_2_button_clicked()
{
    emit send_tool_size(2);
     ui->brush_size_2_button->setChecked(true);
    uncheck_other_brush_buttons(2);
}

void MainWindow::on_brush_size_3_button_clicked()
{
    emit send_tool_size(3);
    ui->brush_size_3_button->setChecked(true);
    uncheck_other_brush_buttons(3);
}

void MainWindow::on_brush_size_4_button_clicked()
{
    emit send_tool_size(4);
    ui->brush_size_4_button->setChecked(true);
    uncheck_other_brush_buttons(4);
}

void MainWindow::on_fps_slider_valueChanged(int value)
{
    QString s = QString::number(value);
    ui->fps_label->setText("FPS: " + s);
}

void MainWindow::on_penButton_clicked()
{
    emit send_tool("pen");
    ui->penButton->setChecked(true);
    ui->eraserButton->setChecked(false);
    ui->circleButton->setChecked(false);
    ui->squareButton->setChecked(false);
    ui->mirrorXYButton->setChecked(false);
    ui->mirrorXButton->setChecked(false);
    ui->mirrorYButton->setChecked(false);
}

void MainWindow::on_eraserButton_clicked()
{
    emit send_tool("eraser");
    ui->penButton->setChecked(false);
    ui->eraserButton->setChecked(true);
    ui->circleButton->setChecked(false);
    ui->squareButton->setChecked(false);
    ui->mirrorXYButton->setChecked(false);
    ui->mirrorYButton->setChecked(false);
    ui->mirrorXButton->setChecked(false);
}

void MainWindow::on_circleButton_clicked()
{
    emit send_tool("circle");
    ui->penButton->setChecked(false);
    ui->eraserButton->setChecked(false);
    ui->circleButton->setChecked(true);
    ui->squareButton->setChecked(false);
    ui->mirrorXYButton->setChecked(false);
    ui->mirrorXButton->setChecked(false);
    ui->mirrorYButton->setChecked(false);
}

void MainWindow::on_squareButton_clicked()
{
    emit send_tool("square");
    ui->penButton->setChecked(false);
    ui->eraserButton->setChecked(false);
    ui->circleButton->setChecked(false);
    ui->squareButton->setChecked(true);
    ui->mirrorXButton->setChecked(false);
    ui->mirrorYButton->setChecked(false);
    ui->mirrorXYButton->setChecked(false);
}

void MainWindow::on_mirrorXButton_clicked()
{
    emit send_tool("mirrorX");
    ui->penButton->setChecked(false);
    ui->eraserButton->setChecked(false);
    ui->circleButton->setChecked(false);
    ui->squareButton->setChecked(false);
    ui->mirrorXButton->setChecked(true);
    ui->mirrorYButton->setChecked(false);
    ui->mirrorXYButton->setChecked(false);
}


void MainWindow::on_mirrorYButton_clicked()
{
    emit send_tool("mirrorY");
    ui->penButton->setChecked(false);
    ui->eraserButton->setChecked(false);
    ui->circleButton->setChecked(false);
    ui->squareButton->setChecked(false);
    ui->mirrorYButton->setChecked(true);
    ui->mirrorXButton->setChecked(false);
    ui->mirrorXYButton->setChecked(false);
}

void MainWindow::on_mirrorXYButton_clicked()
{
    emit send_tool("mirrorXY");
    ui->penButton->setChecked(false);
    ui->eraserButton->setChecked(false);
    ui->circleButton->setChecked(false);
    ui->squareButton->setChecked(false);
    ui->mirrorYButton->setChecked(false);
    ui->mirrorXButton->setChecked(false);
    ui->mirrorXYButton->setChecked(true);
}
