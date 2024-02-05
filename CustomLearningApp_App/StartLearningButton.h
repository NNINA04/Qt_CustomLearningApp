#pragma once

#include "DesignedQPushButton.h"

class StartLearningButton
    : public DesignedQPushButton
{
public:
    explicit StartLearningButton(QWidget* parent)
        : StartLearningButton(QString(), parent) {}

    explicit StartLearningButton(const QString& text, QWidget* parent)
        : StartLearningButton(QIcon(), text, parent) {}

    StartLearningButton(const QIcon& icon, const QString& text, QWidget* parent)
        : DesignedQPushButton(icon, text, parent)
    {
    }
};
