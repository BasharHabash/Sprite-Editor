#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class Thumbnail: public QLabel {
    Q_OBJECT

public:
    explicit Thumbnail(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags(), int id = 0);
    ~Thumbnail();
    int id;

signals:
    void send_thumbnail_click_event(int);

protected:
    void mousePressEvent(QMouseEvent* event);

};


#endif // THUMBNAIL_H
