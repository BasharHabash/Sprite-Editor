#include "spritesheet.h"
#include "frame.h"
#include <vector>
#include <QPainter>
#include <iostream>
#include <QTransform>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QColor>
#include <QInputDialog>
#include "gifexporter.h"
#include "thumbnail.h"
#include "menu.h"

SpriteSheet::SpriteSheet(QWidget * parent, int height, int width): QLabel (parent){
    number_of_frames = 0;
    this->canvas_height = parent->geometry().height();
    this->canvas_width = parent->geometry().width();
    this->setGeometry(0, 0, canvas_height, canvas_width);
    scale_factor = (static_cast<double>(canvas_height)/static_cast<double>(height));
    this->height = height;
    this->width = width;

    recieve_new_frame_request();
    rubberband = new QRubberBand(QRubberBand::Rectangle, this);
    //add_frame();
}

SpriteSheet::~SpriteSheet(){

}

std::vector<Frame *> SpriteSheet::get_all_frames_as_a_vector(){
    return frames;
}

void SpriteSheet::add_frame(){
    number_of_frames++;
    active_frame = new Frame(height, width, number_of_frames);
    frames.push_back(active_frame);

    this->setPixmap(active_frame->thumbnail.scaled(canvas_height, canvas_width));
    this->show();
    emit send_new_thumbnail(&active_frame->thumbnail, active_frame->id);
}

void SpriteSheet::view_thumbnails(){
    emit send_new_thumbnail(&active_frame->thumbnail, active_frame->id);
}

void SpriteSheet::recieve_new_frame_request(){
    add_frame();
}

//Saves project data to a .ssp file
void SpriteSheet::receive_save_signal()
{
    //Get the desired file name and location from the user
    QString myFile = QFileDialog::getSaveFileName(this, ("Name of project"), (".ssp"));
    QFile file(myFile);
    if(myFile.isEmpty())
        return;
    file.open(QIODevice::WriteOnly);

    //Write data to the file and then close
    QTextStream output(&file);
    output << height << " " << width << endl;
    output << number_of_frames << endl;
    for (Frame* f : frames)
    {
        for (int y = 0; y < f->image.height(); y++)
        {
            for (int x = 0; x < f->image.width(); x++)
            {
                //If the pixel exists, write the rgb data to the file
                if (f->image.pixel(y, x) != 0)
                {
                    QColor pixel(f->image.pixel(y, x));
                    output << pixel.red() << " " << pixel.green() << " " << pixel.blue() << " " << pixel.alpha() << " ";
                }
                //else use -1 as a place holder
                else
                {
                    output << -1 << " " << -1 << " " << -1 << " " << -1 << " ";
                }
            }
            output << endl;
        }
    }
    file.close();
}

//Loads a project from a .ssp file
void SpriteSheet::receive_load_signal()
{
    //Get file name and location from user and then open
    QString myFile = QFileDialog::getOpenFileName(this, ("Load Project"), (".ssp"));
    QFile file(myFile);
    if(myFile.isEmpty())
        return;
    file.open(QIODevice::ReadOnly);

    //Read data from file
    QTextStream input(&file);
    int h, w, frames;
    input >> h >> w >> frames;

    //update spritesheet data and set up new project
    height = h;
    width = w;
    scale_factor = (static_cast<double>(canvas_height)/static_cast<double>(height));
    setup_new_project(true);

    //Color the sprite
    for (int f = 0; f < frames; f++)
    {
        for (int y = 0; y < h; y++)
        {
            for (int x = 0; x < w; x++)
            {
                int red, green, blue, alpha;
                input >> red >> green >> blue >> alpha;
                if (red != -1)
                {
                    QColor col(red, green, blue, alpha);
                    this->frames[static_cast<unsigned long>(f)]->image.setPixelColor(y, x, col);
                }
            }
        }
        set_active_frame(f + 1);
        active_frame->thumbnail = QPixmap();
        active_frame->thumbnail = active_frame->thumbnail.fromImage(active_frame->image);
        this->setPixmap(active_frame->thumbnail.scaled(canvas_height, canvas_width));
        this->show();
        send_updated_thumbnail(&active_frame->thumbnail, active_frame->id);
        if (f < frames - 1)
        {
            add_frame();
        }
    }
    file.close();
}

void SpriteSheet::recieve_gif_export_request(){
    //GifExporter gif(this, "test.gif"); testing gif exporting...
    GifExporter gif(this, "newGif.gif");
}

void SpriteSheet::set_active_frame(int frame_number){
    std::cout << "new active frame" << std::endl;
    int temp = active_frame->id;
    active_frame = frames[static_cast<unsigned long>(frame_number - 1)];
    send_updated_active_frame(temp, active_frame->id);
    this->setPixmap(active_frame->thumbnail.scaled(canvas_height, canvas_width));
    this->show();
}

void SpriteSheet::recieve_connect_thumbnail_request(Thumbnail* tn){
    QObject::connect(tn, SIGNAL(send_thumbnail_click_event(int)), this, SLOT(set_active_frame(int)));
}

void SpriteSheet::recieve_connect_menu_request(Menu * menu){
    QObject::connect(menu, SIGNAL(send_new_project_signal()), this, SLOT(setup_new_project()));
    std::cout << "Connected the menu" << std::endl;
}

void SpriteSheet::setup_new_project(bool load){
    emit send_reset_thumbnails_request();

    //Get number of pixels from user
    if (!load)
    {
        label1:
        int pixels = QInputDialog::getInt(nullptr, "input", "How many Pixels? (8,16,32,64,128, or 256");

        if (pixels != 32 && pixels != 64 && pixels != 128 && pixels != 8 && pixels != 16 && pixels != 256)
        {
            goto label1;
        }

        height = static_cast<int>(pixels);
        width = static_cast<int>(pixels);
        scale_factor = (static_cast<double>(canvas_height)/static_cast<double>(height));
    }
    for(int i = 0; i < number_of_frames; i++){
        frames[static_cast<unsigned long>(i)]->~Frame();
    }
    number_of_frames = 0;
    frames.clear();
    recieve_new_frame_request();
}
void SpriteSheet::recieve_color(QColor* color)
{
    currentColor = *color;
}
void SpriteSheet::recieve_tool_size(int size)
{
    toolSize = size;
}
void SpriteSheet::recieve_tool(std::string toolClick)
{
    tool = toolClick;
}
void SpriteSheet::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = static_cast<QPointF>(event->pos()) / scale_factor;
        drawing = true;
    }
}
void SpriteSheet::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
        drawLineTo(static_cast<QPointF>(event->pos()) / scale_factor);
    if(tool == "circle" || tool == "square")
        rubberband->show();
}
void SpriteSheet::mouseReleaseEvent(QMouseEvent *event)
{
    rubberband->hide();
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
        drawLineTo(static_cast<QPointF>(event->pos()) / scale_factor);
    }
}
void SpriteSheet::drawLineTo(const QPointF &endPoint)
{
    QPainter painter(&active_frame->image);
    if(tool == "pen")
    {
        QPen pen(currentColor,toolSize,Qt::SolidLine);
        painter.setPen(pen);
        painter.drawLine(lastPoint, endPoint);

    }
    if(tool == "mirrorX" || tool == "mirrorXY")
    {
        QPen pen(currentColor,toolSize,Qt::SolidLine);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawLine(lastPoint, endPoint);
        flippedEndPoint = endPoint;
        flippedLastPoint = lastPoint;
        flippedEndPoint.setX(canvas_width/scale_factor - endPoint.x());
        flippedLastPoint.setX(canvas_width/scale_factor - lastPoint.x());
        painter.drawLine(flippedLastPoint,flippedEndPoint);
    }
    if(tool == "mirrorY" || tool == "mirrorXY")
    {
        QPen pen(currentColor,toolSize,Qt::SolidLine);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(pen);
        painter.drawLine(lastPoint, endPoint);
        flippedEndPoint = endPoint;
        flippedLastPoint = lastPoint;
        flippedEndPoint.setY(canvas_height/scale_factor - endPoint.y());
        flippedLastPoint.setY(canvas_height/scale_factor - lastPoint.y());
        painter.drawLine(flippedLastPoint,flippedEndPoint);
    }
    if(tool == "mirrorXY")
    {
        flippedEndPoint.setY(canvas_height/scale_factor - endPoint.y());
        flippedLastPoint.setY(canvas_height/scale_factor - lastPoint.y());
        flippedEndPoint.setX(canvas_width/scale_factor - endPoint.x());
        flippedLastPoint.setX(canvas_width/scale_factor - lastPoint.x());
        painter.drawLine(flippedLastPoint,flippedEndPoint);
    }
    if(tool == "eraser")
    {
        QRect rec(endPoint.x(), endPoint.y(), toolSize, toolSize);
        painter.setCompositionMode (QPainter::CompositionMode_Source);
        painter.fillRect(rec, Qt::transparent);
        painter.setCompositionMode (QPainter::CompositionMode_SourceOver);
    }
    if(tool == "circle" || tool == "square")
    {
        this->setCursor(Qt::SizeFDiagCursor);
        painter.setPen(Qt::NoPen);
        QBrush brush(currentColor);
        painter.setBrush(brush);
        if (lastPoint.x()>endPoint.x())
        {
             QRect rubberBandX(endPoint.toPoint()*scale_factor,lastPoint.toPoint()*scale_factor);
             rubberband->setGeometry(rubberBandX);
         }
         else
         {
             QRect rubberBandY(lastPoint.toPoint()*scale_factor,endPoint.toPoint()*scale_factor);
             rubberband->setGeometry(rubberBandY);
         }
        if(!drawing){
                this->setCursor(Qt::CrossCursor);
                QRect shape(lastPoint.toPoint(),endPoint.toPoint());
                if(tool == "circle")
                    painter.drawEllipse(shape);
                if(tool == "square")
                    painter.drawRect(shape);
          }
    }
    active_frame->thumbnail = QPixmap();
    active_frame->thumbnail = active_frame->thumbnail.fromImage(active_frame->image);
    this->setPixmap(active_frame->thumbnail.scaled(canvas_height, canvas_width));
    this->show();
    painter.end();
    if(tool == "pen" || tool =="mirrorY" || tool == "mirrorX" || tool == "mirrorXY" || tool == "eraser")
        lastPoint = endPoint;
    send_updated_thumbnail(&active_frame->thumbnail, active_frame->id);
}
