#pragma once

#include "ScrollablePhrasesEnteringList.h"

class PhrasesEnteringListManager
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _addPhrasesEnteringButton;
    ScrollablePhrasesEnteringList* _scrollableInputPhraseAreaList;
public:
    explicit PhrasesEnteringListManager(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _addPhrasesEnteringButton = new AddInputPhraseAreaButton("Add phrase", this);
        _scrollableInputPhraseAreaList = new ScrollablePhrasesEnteringList(this);

        _vBoxLayout->setMargin(0);
        _vBoxLayout->addWidget(_addPhrasesEnteringButton);
        _vBoxLayout->addWidget(_scrollableInputPhraseAreaList);

        connect(_addPhrasesEnteringButton, SIGNAL(clicked(bool)), this, SLOT(AddInputPhraseAreaButton_Clicked()));
    }

    ScrollablePhrasesEnteringList* GetScrollablePhrasesEnteringList() const
    {
        return _scrollableInputPhraseAreaList;
    }
private slots:
    void AddInputPhraseAreaButton_Clicked() const
    {
        PhrasesEnteringList* phrasesEnteringList = this->_scrollableInputPhraseAreaList->GetPhrasesEnteringList();
        phrasesEnteringList->AddPhrasesEntering(new PhrasesEntering()); // QIcon("DeleteInputPhraseAreaButton.png")
    }
};
