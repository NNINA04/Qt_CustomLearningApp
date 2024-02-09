#pragma once

#include "DesignedQScrollArea.h"
#include "InputPhraseAreaList.h"

class ScrollableInputPhraseAreaList
    : public DesignedQScrollArea
{
    InputPhraseAreaList* _inputPhraseAreaList;
public:
    explicit ScrollableInputPhraseAreaList(QWidget* parent = nullptr)
        : DesignedQScrollArea(parent)
    {
        _inputPhraseAreaList = new InputPhraseAreaList(this);

        this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        this->setWidget(_inputPhraseAreaList);
        this->setWidgetResizable(true);
        this->show();
    }

    void AddInputPhraseArea(InputPhraseArea* inputPhraseArea)
    {
        _inputPhraseAreaList->AddInputPhraseArea(inputPhraseArea);
    }
};