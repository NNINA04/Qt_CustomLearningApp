#pragma once

#include "BasicQTabWidget.h"
#include "PhrasesRecorder.h"

class PhrasesRecorderTabs
    : public BasicQTabWidget
{
public:
    using BasicQTabWidget::BasicQTabWidget;

    virtual QWidget* MakeTabBasedOnAdding()
    {
        return new PhrasesRecorder();
    }
};