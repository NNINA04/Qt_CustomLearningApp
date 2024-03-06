#pragma once

#include "BasicQPushButton.h"

class AddInputPhraseAreaButton
    : public BasicQPushButton
{
public:
    explicit AddInputPhraseAreaButton(QWidget* parent)
        : AddInputPhraseAreaButton(QString(), parent) {}

    explicit AddInputPhraseAreaButton(const QString& text, QWidget* parent)
        : AddInputPhraseAreaButton(QIcon(), text, parent) {}

    AddInputPhraseAreaButton(const QIcon& icon, const QString& text, QWidget* parent)
        : BasicQPushButton(icon, text, parent)
    {
    }
};
