#pragma once

#include "LearnedPhrase.h"
#include "AddPhraseButton.h"

class LearnedPhrasesList
    : public QWidget
{
    Q_OBJECT;

    QVBoxLayout* _vBoxLayout;
    QVector<LearnedPhrase*> _learnedPhrasesList;
    QPushButton* _addPhraseButton;
public:
    LearnedPhrasesList(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _addPhraseButton = new ::AddPhraseButton("Add phrase", this);

        _vBoxLayout->addWidget(_addPhraseButton);

        _vBoxLayout->setMargin(0);
        _vBoxLayout->setSpacing(3);

        connect(_addPhraseButton, SIGNAL(clicked()), this, SLOT(AddPhraseButton_Clicked()));
    }

    void AddLearnedPhrase(LearnedPhrase* learnedPhrase)
    {
        connect(learnedPhrase->GetDeletePhraseButton(), &QAbstractButton::clicked, [this, learnedPhrase] { DeletePhraseButton_Clicked(learnedPhrase); });
        _learnedPhrasesList.push_back(learnedPhrase);
        _vBoxLayout->insertWidget(_learnedPhrasesList.size() - 1, learnedPhrase);
        learnedPhrase->show();
    }
private slots:
    virtual void DeletePhraseButton_Clicked(LearnedPhrase* learnedPhrase)
    {
        for (size_t i = 0; i < _learnedPhrasesList.size(); ++i)
        {
            if (_learnedPhrasesList[i] == learnedPhrase)
            {
                delete _learnedPhrasesList[i];
                _learnedPhrasesList.removeAt(i);
                return;
            }
        }
        qFatal("Something went wrong!\nLearnedPhrasesList::DeletePhraseButton(QObject* learnedPhrase)");
    }

    virtual void AddPhraseButton_Clicked()
    {
        AddLearnedPhrase(new LearnedPhrase());
    }
};