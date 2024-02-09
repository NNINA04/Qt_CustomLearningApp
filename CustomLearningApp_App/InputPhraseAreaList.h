#pragma once

#include "InputPhraseArea.h"
#include "AddPhraseButton.h"

class InputPhraseAreaList
    : public QWidget
{
    QVBoxLayout* _vBoxLayout;
public:
    InputPhraseAreaList(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);

        _vBoxLayout->setMargin(0);
        _vBoxLayout->setSpacing(3);
    }

    void AddInputPhraseArea(InputPhraseArea* inputPhraseArea)
    {
        _vBoxLayout->addWidget(inputPhraseArea);
        inputPhraseArea->show();
    }
};
