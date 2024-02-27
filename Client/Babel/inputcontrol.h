#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H

#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

class InputControl : public QWidget
{
    Q_OBJECT
public:
    explicit InputControl(QWidget *parent = nullptr);

    bool isPushed() const;
    void setIsPushed(bool newIsPushed);

signals:
    void KeyIsReleased();
    void KeyIsPressed();

private:
    bool _isPushed{};
    void keyPressEvent(QKeyEvent *event) override;
    bool event(QEvent *event) override;
};

#endif // INPUTCONTROL_H
