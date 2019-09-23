#include "thumbnail.h"
#include <iostream>

Thumbnail::Thumbnail(QWidget* parent, Qt::WindowFlags f, int id)
    : QLabel(parent) {
    this->id = id;
}

Thumbnail::~Thumbnail() {}

void Thumbnail::mousePressEvent(QMouseEvent* event) {
    emit send_thumbnail_click_event(id);
}
