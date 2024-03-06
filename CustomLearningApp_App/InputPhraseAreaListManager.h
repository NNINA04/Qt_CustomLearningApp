#pragma once

#include "ScrollableInputPhraseAreaList.h"

class InputPhraseAreaListManager
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _addInputPhraseAreaButton;
    ScrollableInputPhraseAreaList* _scrollableInputPhraseAreaList;
    QIcon _deletePhraseButtonIcon;
public:
    explicit InputPhraseAreaListManager(const QIcon& deletePhraseButtonIcon = QIcon(), QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
        , _deletePhraseButtonIcon(deletePhraseButtonIcon)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _addInputPhraseAreaButton = new AddInputPhraseAreaButton("Add phrase", this);
        _scrollableInputPhraseAreaList = new ScrollableInputPhraseAreaList(this);

        _vBoxLayout->setMargin(0);
        _vBoxLayout->addWidget(_addInputPhraseAreaButton);
        _vBoxLayout->addWidget(_scrollableInputPhraseAreaList);

        connect(_addInputPhraseAreaButton, SIGNAL(clicked(bool)), this, SLOT(AddInputPhraseAreaButton_Clicked()));
    }

    void AddInputPhraseArea(InputPhraseArea* inputPhraseArea) const
    {
        inputPhraseArea->SetDeletePhraseButtonIcon(_deletePhraseButtonIcon);
        _scrollableInputPhraseAreaList->AddInputPhraseArea(inputPhraseArea);
    }

    void DeleteInputPhraseArea(int index) const
    {
        _scrollableInputPhraseAreaList->DeleteInputPhraseArea(index);
    }
private slots:
    void AddInputPhraseAreaButton_Clicked() const
    {
        this->AddInputPhraseArea(new InputPhraseArea());
    }
};
