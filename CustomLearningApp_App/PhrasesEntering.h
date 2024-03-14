#pragma once

#include "BasicQTextEdit.h"
#include "BasicQPushButton.h"
#include "DeleteInputPhraseAreaButton.h"

class PhrasesEntering
    : public QWidget
{
    Q_OBJECT;

    QHBoxLayout* _hBoxLayout;
    QTextEdit* _leftPhrase;
    QPushButton* _destroyButton;
    QTextEdit* _rightPhrase;
public:
    using Phrases = QPair<QString, QString>;

    explicit PhrasesEntering(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _hBoxLayout = new QHBoxLayout(this);
        _leftPhrase = new BasicQTextEdit(this);
        _destroyButton = new BasicQPushButton(QIcon("DeleteInputPhraseAreaButton.png"), QString(), this);
        _rightPhrase = new BasicQTextEdit(this);

        _hBoxLayout->addWidget(_leftPhrase);
        _hBoxLayout->addWidget(_destroyButton);
        _hBoxLayout->addWidget(_rightPhrase);
        _hBoxLayout->setMargin(0);
        _hBoxLayout->setSpacing(0);

        connect(_destroyButton, SIGNAL(clicked()), this, SLOT(DestrouButton_Clicked()));
    }
private slots:
    void DestrouButton_Clicked() const
    {
        delete this;
    }
};