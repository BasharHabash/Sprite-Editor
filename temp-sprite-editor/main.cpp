#include "mainwindow.h"
#include <QApplication>
#include "spritesheet.h"
#include "thumbnail.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFrame * f = w.findChild<QFrame*>("canvas");
    SpriteSheet ss(f, 32, 32);
    //SpriteSheet ss(f, 64, 64);
    //QObject::connect(&w, SIGNAL(test(QFrame &)), &ss, SLOT(test(QFrame &)));
    QObject::connect(&w, SIGNAL(send_gif_export_request()), &ss, SLOT(recieve_gif_export_request()));
    QObject::connect(&w, SIGNAL(request_new_frame()), &ss, SLOT(recieve_new_frame_request()));
    QObject::connect(&ss, SIGNAL(send_new_thumbnail(QPixmap*, int)), &w, SLOT(create_thumbnail_view(QPixmap*, int)));
    QObject::connect(&ss, SIGNAL(send_updated_thumbnail(QPixmap*, int)), &w, SLOT(update_thumbnail_view(QPixmap*, int)));
    QObject::connect(&w, SIGNAL(send_connect_thumbnail_request(Thumbnail*)), &ss, SLOT(recieve_connect_thumbnail_request(Thumbnail*)));
    QObject::connect(&ss, SIGNAL(send_updated_active_frame(int, int)), &w, SLOT(update_current_active_frame(int, int)));
    QObject::connect(&w, SIGNAL(send_color(QColor*)), &ss, SLOT(recieve_color(QColor*)));
    QObject::connect(&w, SIGNAL(send_tool_size(int)), &ss, SLOT(recieve_tool_size(int)));
    QObject::connect(&w.menu, SIGNAL(send_new_project_signal(bool)), &ss, SLOT(setup_new_project(bool)));
    QObject::connect(&w.menu, SIGNAL(send_save_signal()), &ss, SLOT(receive_save_signal()));
    QObject::connect(&w.menu, SIGNAL(send_load_signal()), &ss, SLOT(receive_load_signal()));
    QObject::connect(&ss, SIGNAL(send_reset_thumbnails_request()), &w, SLOT(reset_thumbnail_view()));
    QObject::connect(&w, SIGNAL(send_tool(std::string)), &ss, SLOT(recieve_tool(std::string)));

    //ss.test(*w.findChild<QFrame*>("canvas"));

    ss.view_thumbnails();
    w.show();

    return a.exec();
}
