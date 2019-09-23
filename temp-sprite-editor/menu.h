#ifndef MENU_H
#define MENU_H
#include <QObject>

class Menu : public QObject
{
    Q_OBJECT
public:
    Menu();
    void save();
    void help();
    void load();
    void new_sprite();
signals:
    void send_new_project_signal(bool);
    void send_save_signal();
    void send_load_signal();
};

#endif // MENU_H
