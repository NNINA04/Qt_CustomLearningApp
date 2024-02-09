#pragma once

#include "InputPhraseAreaList.h"

class LearnedPhrasesListManager
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _addPhraseButton;
    InputPhraseAreaList* _learnedPhrasesList;
public:
    LearnedPhrasesListManager(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _addPhraseButton = new AddPhraseButton("Add phrase", this);
        _learnedPhrasesList = new InputPhraseAreaList(this);

        _vBoxLayout->addWidget(_addPhraseButton);
        _vBoxLayout->addWidget(_learnedPhrasesList);

        connect(_addPhraseButton, SIGNAL(clicked(bool)), this, SLOT(AddPhraseButton_Clicked()));
    }

    void AddLearnedPhrase()
    {
        _learnedPhrasesList->AddLearnedPhrase(new InputPhraseArea());
    }
private slots:
    void AddPhraseButton_Clicked()
    {
        this->AddLearnedPhrase();
    }
};
