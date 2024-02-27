#include "inputcontrol.h"

InputControl::InputControl(QWidget *parent)
    : QWidget{parent}
{}

bool InputControl::isPushed() const
{
    return _isPushed;
}

void InputControl::setIsPushed(bool newIsPushed)
{
    _isPushed = newIsPushed;
}

void InputControl::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed" << (char)event->key() << "<-";
}

bool InputControl::event(QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *ev = static_cast<QKeyEvent *>(event);
        if (ev->key() == 'T') {
            if (!_isPushed) {
                _isPushed = true;
                qDebug() << "Key Pressed !";
                emit KeyIsPressed();
            }
            return true;
        }
    } else if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *ev = static_cast<QKeyEvent *>(event);
        if (ev->key() == 'T') {
            _isPushed = false;
            qDebug() << "Key released !";
            emit KeyIsReleased();
        }
        return true;
    }
    return QWidget::event(event);
}
