#pragma once

#include "AddInputPhraseAreaButton.h"
#include "StartLearningPhrasesButton.h"
#include "PhrasesEnteringListManager.h"
#include "LearningPhrases.h"

class PhrasesRecorder
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _startLearningButton;
    PhrasesEnteringListManager* _phrasesEnteringListManager;
public:
    explicit PhrasesRecorder(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        this->setGeometry(1000, 1000, 800, 800);

        _vBoxLayout = new QVBoxLayout(this);
        _startLearningButton = new StartLearningPhrasesButton("Start learning", this);
        _phrasesEnteringListManager = new PhrasesEnteringListManager(this);

        _vBoxLayout->setMargin(5);
        _vBoxLayout->addWidget(_startLearningButton);
        _vBoxLayout->addWidget(_phrasesEnteringListManager);

        ScrollablePhrasesEnteringList* scrollablePhrasesEnteringList = _phrasesEnteringListManager->GetScrollablePhrasesEnteringList();
        PhrasesEnteringList* phrasesEnteringList = scrollablePhrasesEnteringList->GetPhrasesEnteringList();
        for (size_t i = 0; i < 3; ++i)
            phrasesEnteringList->AddPhrasesEntering(new PhrasesEntering());
    }

    PhrasesEnteringListManager* GetPhrasesEnteringListManager() 
    {
        return _phrasesEnteringListManager;
    }
};
