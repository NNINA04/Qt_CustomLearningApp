#pragma once

#include "AddPhraseButton.h"
#include "StartLearningButton.h"
#include "InputPhraseAreaListManager.h"

class MainWindow
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QPushButton* _startLearningButton;
    InputPhraseAreaListManager* _learnedPhrasesListManager;
public:
    explicit MainWindow(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        this->setGeometry(1000, 1000, 800, 800);

        _vBoxLayout = new QVBoxLayout(this);
        _startLearningButton = new StartLearningButton("Start learning", this);
        _learnedPhrasesListManager = new InputPhraseAreaListManager(this);

        _vBoxLayout->addWidget(_startLearningButton);
        _vBoxLayout->addWidget(_learnedPhrasesListManager);

        connect(_startLearningButton, SIGNAL(clicked(bool)), this, SLOT(StartLearningButton_Clicked()));

        for (size_t i = 0; i < 3; ++i)
            _learnedPhrasesListManager->AddInputPhraseArea(new InputPhraseArea());
    }
private slots:
    void StartLearningButton_Clicked()
    {
        qDebug() << "Not realized yet";
    }
};
