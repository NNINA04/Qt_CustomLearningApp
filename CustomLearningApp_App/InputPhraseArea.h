#pragma once

#include "DesignedQTextEdit.h"
#include "DesignedQPushButton.h"
#include "DeletePhraseButton.h"

class InputPhraseArea
    : public QWidget
{
    Q_OBJECT;

    QHBoxLayout* _hBoxLayout;
    DesignedQTextEdit* _learnedPhrase;
    DesignedQPushButton* _deletePhraseButton;
    DesignedQTextEdit* _translatedPhrase;
public:
    InputPhraseArea(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _hBoxLayout = new QHBoxLayout(this);
        _learnedPhrase = new DesignedQTextEdit(this);
        _deletePhraseButton = new DesignedQPushButton(QIcon("DeletePhraseButton.png"), QString(), this);
        _translatedPhrase = new DesignedQTextEdit(this);

        _hBoxLayout->addWidget(_learnedPhrase);
        _hBoxLayout->addWidget(_deletePhraseButton);
        _hBoxLayout->addWidget(_translatedPhrase);
        _hBoxLayout->setSpacing(0);
        _hBoxLayout->setMargin(0);

        connect(_deletePhraseButton, SIGNAL(clicked()),this,SLOT(DeletePhraseButton_Clicked()));
    }
private slots:
    void DeletePhraseButton_Clicked() 
    {
        delete this;
    }
};