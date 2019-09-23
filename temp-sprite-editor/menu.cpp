#include "menu.h"
#include <QMessageBox>
#include <iostream>

Menu::Menu()
{

}

void Menu::save()
{
    emit send_save_signal();
}

void Menu::load()
{
    emit send_load_signal();
}

void Menu::help()
{
    QMessageBox helpScreen;
    QString text = "Welcome to the Temp Sprite Editor! \n \n"
                   "Choose the tool type on the left side of the \n"
                   "window, and the tool size on the top left. \n \n"
                   "To change the color click on the change color button \n"
                   "on the bottom right of the window. \n \n"
                   "To add another frame, or to go to a previous frame, \n"
                   "use the frame explorer on the bottom of the window. \n \n"
                   "The new, save, load, and export options are under file \n"
                   "at the top left of the window.";
    helpScreen.setText(text);
    helpScreen.exec();
}

void Menu::new_sprite()
{
    emit send_new_project_signal(false);
}
