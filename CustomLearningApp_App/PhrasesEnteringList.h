#pragma once

#include "PhrasesEntering.h"
#include "AddInputPhraseAreaButton.h"

class PhrasesEnteringList
    : public QWidget
{
    QVBoxLayout* _vBoxLayout;
    QVector<PhrasesEntering*>* _phrasesEnterings;
public:
    explicit PhrasesEnteringList(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _phrasesEnterings = new QVector<PhrasesEntering*>();

        _vBoxLayout->setMargin(0);
    }

    void AddPhrasesEntering(PhrasesEntering* phrasesEnterign)
    {
        _vBoxLayout->addWidget(phrasesEnterign);
        _phrasesEnterings->push_back(phrasesEnterign);
    }

    void DeletePhrasesEntering(int index)
    {
        _vBoxLayout->removeItem(_vBoxLayout->itemAt(index));
        _phrasesEnterings->removeAt(index);
    }

    void Clear() 
    {
        size_t size = _phrasesEnterings->size();
        for (size_t i = 0; i < size; ++i)
            this->DeletePhrasesEntering(i);
    }

    const QVector<PhrasesEntering*>* GetPhrasesEnterings()
    {
        return _phrasesEnterings;
    }
};
