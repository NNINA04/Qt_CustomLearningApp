#pragma once

class DesignedQPushButton
    : public QPushButton
{
public:
    explicit DesignedQPushButton(QWidget* parent)
        : DesignedQPushButton(QString(), parent) {}

    explicit DesignedQPushButton(const QString& text, QWidget* parent)
        : DesignedQPushButton(QIcon(), QString(), parent) {}

    DesignedQPushButton(const QIcon& icon, const QString& text, QWidget* parent)
        : QPushButton(icon, text, parent)
    {
    }
};
