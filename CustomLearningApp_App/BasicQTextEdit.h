#pragma once

class BasicQTextEdit
    : public QTextEdit
{
public:
    BasicQTextEdit(QWidget* parent = nullptr)
        : BasicQTextEdit(QString(), parent) {}

    BasicQTextEdit(const QString& text, QWidget* parent = nullptr)
        : QTextEdit(text, parent)
    {
        this->setMaximumHeight(25);
        this->setLineWrapMode(LineWrapMode::WidgetWidth);
        this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    }
};
