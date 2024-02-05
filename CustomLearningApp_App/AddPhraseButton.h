#pragma once

#include "DesignedQPushButton.h"

class AddPhraseButton
    : public DesignedQPushButton
{
public:
    explicit AddPhraseButton(QWidget* parent)
        : AddPhraseButton(QString(), parent) {}

    explicit AddPhraseButton(const QString& text, QWidget* parent)
        : AddPhraseButton(QIcon(), text, parent) {}

    AddPhraseButton(const QIcon& icon, const QString& text, QWidget* parent)
        : DesignedQPushButton(icon, text, parent)
    {
    }
};
