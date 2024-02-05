#pragma once

#include "DesignedQTextEdit.h"
#include "DeletePhraseButton.h"
#include "DesignedQPushButton.h"

class LearnedPhrase
    : public QWidget
{
    QHBoxLayout* _hBoxLayout;
    QTextEdit* _learnedPhrase;
    QPushButton* _deletePhraseButton;
    QTextEdit* _translatedPhrase;
public:
    LearnedPhrase(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _hBoxLayout = new QHBoxLayout(this);
        _learnedPhrase = new DesignedQTextEdit(this);
        _deletePhraseButton = new DesignedQPushButton(QIcon("DeletePhraseButton.png"), QString(), this);
        _translatedPhrase = new DesignedQTextEdit(this);

        _hBoxLayout->addWidget(_learnedPhrase);
        _hBoxLayout->addWidget(_deletePhraseButton);
        _hBoxLayout->addWidget(_translatedPhrase);

        _hBoxLayout->setMargin(0);
        _hBoxLayout->setSpacing(0);
    }

    QPushButton* GetDeletePhraseButton() const
    {
        return _deletePhraseButton;
    }
};