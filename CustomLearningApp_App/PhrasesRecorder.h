#pragma once

#include "AddInputPhraseAreaButton.h"
#include "StartLearningPhrasesButton.h"
#include "InputPhraseAreaListManager.h"
#include "LearningPhrases.h"

class PhrasesRecorder
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _startLearningButton;
    InputPhraseAreaListManager* _learnedPhrasesListManager;
public:
    explicit PhrasesRecorder(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        this->setGeometry(1000, 1000, 800, 800);

        _vBoxLayout = new QVBoxLayout(this);
        _startLearningButton = new StartLearningPhrasesButton("Start learning", this);
        _learnedPhrasesListManager = new InputPhraseAreaListManager(QIcon("DeleteInputPhraseAreaButton.png"), this);

        _vBoxLayout->setMargin(5);
        _vBoxLayout->addWidget(_startLearningButton);
        _vBoxLayout->addWidget(_learnedPhrasesListManager);

        for (size_t i = 0; i < 3; ++i)
            _learnedPhrasesListManager->AddInputPhraseArea(new InputPhraseArea());
    }

    void ConnectStartLearningButton_Clicked(void *slot())
    {
        connect(_startLearningButton, &QPushButton::clicked, slot);
    }
};
