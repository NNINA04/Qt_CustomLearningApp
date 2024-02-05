#pragma once

#include "AddPhraseButton.h"
#include "StartLearningButton.h"
#include "LearnedPhrasesList.h"

class MainWindow
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _startLearningButton;
    LearnedPhrasesList* _learnedPhrasesList;
public:
    explicit MainWindow(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        this->setGeometry(1000, 1000, 800, 800);

        _vBoxLayout = new QVBoxLayout(this);
        _startLearningButton = new StartLearningButton("Start learning", this);
        _learnedPhrasesList = new LearnedPhrasesList(this);

        _vBoxLayout->addWidget(_startLearningButton);
        _vBoxLayout->addWidget(_learnedPhrasesList);

        connect(_startLearningButton, SIGNAL(clicked(bool)), this, SLOT(StartLearningButton_Clicked()));
        
        for (size_t i = 0; i < 3; ++i)
            _learnedPhrasesList->AddLearnedPhrase(new LearnedPhrase());
    }
private slots:
    void StartLearningButton_Clicked()
    {
        qDebug() << "Not realized yet";
    }
};
