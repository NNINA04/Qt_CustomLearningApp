#pragma once

#include "BasicQPushButton.h"

class DeleteInputPhraseAreaButton
    : public BasicQPushButton
{
public:
    explicit DeleteInputPhraseAreaButton(QWidget* parent)
        : DeleteInputPhraseAreaButton(QString(), parent) {}

    explicit DeleteInputPhraseAreaButton(const QString& text, QWidget* parent)
        : DeleteInputPhraseAreaButton(QIcon(), text, parent) {}

    DeleteInputPhraseAreaButton(const QIcon& icon, const QString& text, QWidget* parent)
        : BasicQPushButton(icon, text, parent)
    {
    }
};
