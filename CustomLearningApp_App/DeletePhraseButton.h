#pragma once

#include "DesignedQPushButton.h"

class DeletePhraseButton
    : public DesignedQPushButton
{
public:
    explicit DeletePhraseButton(QWidget* parent)
        : DeletePhraseButton(QString(), parent) {}

    explicit DeletePhraseButton(const QString& text, QWidget* parent)
        : DeletePhraseButton(QIcon(), text, parent) {}

    DeletePhraseButton(const QIcon& icon, const QString& text, QWidget* parent)
        : DesignedQPushButton(icon, text, parent)
    {
    }
};
