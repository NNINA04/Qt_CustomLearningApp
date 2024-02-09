#pragma once

#include "ScrollableInputPhraseAreaList.h"

class InputPhraseAreaListManager
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _addInputPhraseAreaButton;
    ScrollableInputPhraseAreaList* _scrollableInputPhraseAreaList;
public:
    InputPhraseAreaListManager(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _addInputPhraseAreaButton = new AddPhraseButton("Add phrase", this);
        _scrollableInputPhraseAreaList = new ScrollableInputPhraseAreaList(this);

        _vBoxLayout->addWidget(_addInputPhraseAreaButton);
        _vBoxLayout->addWidget(_scrollableInputPhraseAreaList);

        connect(_addInputPhraseAreaButton, SIGNAL(clicked(bool)), this, SLOT(AddInputPhraseAreaButton_Clicked()));
    }

    void AddInputPhraseArea(InputPhraseArea* inputPhraseArea)
    {
        _scrollableInputPhraseAreaList->AddInputPhraseArea(inputPhraseArea);
    }
private slots:
    void AddInputPhraseAreaButton_Clicked()
    {
        this->AddInputPhraseArea(new InputPhraseArea());
    }
};
