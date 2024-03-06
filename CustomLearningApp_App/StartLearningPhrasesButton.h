#pragma once

#include "BasicQPushButton.h"

class StartLearningPhrasesButton
    : public BasicQPushButton
{
public:
    explicit StartLearningPhrasesButton(QWidget* parent)
        : StartLearningPhrasesButton(QString(), parent) {}

    explicit StartLearningPhrasesButton(const QString& text, QWidget* parent)
        : StartLearningPhrasesButton(QIcon(), text, parent) {}

    StartLearningPhrasesButton(const QIcon& icon, const QString& text, QWidget* parent)
        : BasicQPushButton(icon, text, parent)
    {
    }
};
