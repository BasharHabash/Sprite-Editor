#include "frame.h"
#include <QPixmap>
#include <QImage>
#include <QColor>
/*
Frame::Frame(QWidget* parent): QLabel (parent)
{
    //pixmap = QPixmap(64, 64);
    //pixmap.scaled(10, 10);
    QColor black(0,0,0);
    //pixmap.fill(black);
}
*/

Frame::Frame(){

}


Frame::Frame(int h, int w, int id)
{
    this->id = id;
    image = QImage(h, w, QImage::Format_ARGB32);
    image.fill(qRgba(0, 0, 0, 0));
    thumbnail = thumbnail.fromImage(image);
}


Frame::~Frame(){
}



