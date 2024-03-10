#pragma once

#include "BasicQScrollArea.h"
#include "PhrasesEnteringList.h"

class ScrollablePhrasesEnteringList
    : public BasicQScrollArea
{
    PhrasesEnteringList* _phrasesEnteringList;
public:
    explicit ScrollablePhrasesEnteringList(QWidget* parent = nullptr)
        : BasicQScrollArea(parent)
    {
        _phrasesEnteringList = new PhrasesEnteringList(this);

        this->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        this->setWidget(_phrasesEnteringList);
        this->setWidgetResizable(true);
        this->show();
    }

    PhrasesEnteringList* GetPhrasesEnteringList() const
    {
        return _phrasesEnteringList;
    }
};