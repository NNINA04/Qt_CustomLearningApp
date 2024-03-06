#pragma once

class BasicQPushButton
    : public QPushButton
{
public:
    explicit BasicQPushButton(QWidget* parent)
        : BasicQPushButton(QString(), parent) {}

    explicit BasicQPushButton(const QString& text, QWidget* parent)
        : BasicQPushButton(QIcon(), QString(), parent) {}

    BasicQPushButton(const QIcon& icon, const QString& text, QWidget* parent)
        : QPushButton(icon, text, parent)
    {
    }
};
