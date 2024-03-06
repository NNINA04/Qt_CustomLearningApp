#pragma once

#include "InputPhraseArea.h"
#include "AddInputPhraseAreaButton.h"

class InputPhraseAreaList
    : public QWidget
{
    QVBoxLayout* _vBoxLayout;
public:
    explicit InputPhraseAreaList(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);

        _vBoxLayout->setMargin(0);
    }

    void AddInputPhraseArea(InputPhraseArea* inputPhraseArea) const
    {
        _vBoxLayout->addWidget(inputPhraseArea);
        inputPhraseArea->show();
    }

    void DeleteInputPhraseArea(int index) const
    {
        _vBoxLayout->removeItem(_vBoxLayout->itemAt(index));
    }
};
