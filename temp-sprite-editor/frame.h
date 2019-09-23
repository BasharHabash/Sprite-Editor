#ifndef FRAME_H
#define FRAME_H

#include <QImage>
#include <QPixmap>
#include <QLabel>

class Frame
{
public:
    //Frame(QWidget* parent);
    Frame(int h, int w, int id);
    Frame();
    ~Frame();
    int id;
    QImage image;
    QPixmap thumbnail;
public slots:

    //void paintEvent(QPaintEvent *event) override;
private:

};

#endif // FRAME_H
