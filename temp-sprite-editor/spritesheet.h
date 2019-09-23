#ifndef SPRITESHEET_H
#define SPRITESHEET_H
#include "frame.h"
#include <vector>
#include <QMouseEvent>
#include <QLabel>
#include "thumbnail.h"
#include "menu.h"
#include <QRubberBand>

class SpriteSheet : public QLabel
{
    Q_OBJECT
public:
    SpriteSheet(QWidget * parent, int height, int width);
    //SpriteSheet(int height, int width);
    SpriteSheet();
    ~SpriteSheet() override;
    std::vector<Frame *> get_all_frames_as_a_vector();
    int height;
    int width;
private:
    std::vector<Frame*> frames;
    Frame * active_frame;
    QWidget * parent;
    int canvas_width;
    int canvas_height;
    QColor currentColor = Qt::black;
    int toolSize = 1;
    std::string tool = "pen";
    QRubberBand *rubberband;
    bool drawing;
    QPointF lastPoint;
    QPointF flippedLastPoint;
    QPointF flippedEndPoint;
    int number_of_frames;
    double scale_factor;
    void drawLineTo(const QPointF &endPoint);
public slots:
    void add_frame();
    void view_thumbnails();
    void recieve_new_frame_request();
    void recieve_gif_export_request();
    void set_active_frame(int frame_number);
    void recieve_connect_thumbnail_request(Thumbnail*);
    void recieve_color(QColor*);
    void recieve_tool_size(int);
    void recieve_tool(std::string);
    void recieve_connect_menu_request(Menu *);
    void setup_new_project(bool);
    void receive_save_signal();
    void receive_load_signal();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
signals:
    void send_new_thumbnail(QPixmap*, int);
    void send_updated_thumbnail(QPixmap*, int);
    void send_updated_active_frame(int, int);
    void send_reset_thumbnails_request();
};

#endif // SPRITESHEET_H
