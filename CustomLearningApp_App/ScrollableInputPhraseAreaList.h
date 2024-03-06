#pragma once

#include "BasicQScrollArea.h"
#include "InputPhraseAreaList.h"

class ScrollableInputPhraseAreaList
    : public BasicQScrollArea
{
    InputPhraseAreaList* _inputPhraseAreaList;
public:
    explicit ScrollableInputPhraseAreaList(QWidget* parent = nullptr)
        : BasicQScrollArea(parent)
    {
        _inputPhraseAreaList = new InputPhraseAreaList(this);

        this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        this->setWidget(_inputPhraseAreaList);
        this->setWidgetResizable(true);
        this->show();
    }

    void AddInputPhraseArea(InputPhraseArea* inputPhraseArea) const
    {
        _inputPhraseAreaList->AddInputPhraseArea(inputPhraseArea);
    }

    void DeleteInputPhraseArea(int index) const
    {
        _inputPhraseAreaList->DeleteInputPhraseArea(index);
    }
};