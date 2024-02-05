#pragma once

class DesignedQTextEdit
    : public QTextEdit
{
public:
    DesignedQTextEdit(QWidget* parent = nullptr)
        : DesignedQTextEdit(QString(), parent) {}

    DesignedQTextEdit(const QString& text, QWidget* parent = nullptr)
        : QTextEdit(text, parent)
    {
        
    }
};
