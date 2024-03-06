#pragma once

#include "BasicQTextEdit.h"
#include "BasicQPushButton.h"
#include "DeleteInputPhraseAreaButton.h"

class InputPhraseArea
    : public QWidget
{
    Q_OBJECT;

    QHBoxLayout* _hBoxLayout;
    QTextEdit* _learnedPhrase;
    QPushButton* _deletePhraseButton;
    QTextEdit* _translatedPhrase;
public:
    explicit InputPhraseArea(const QIcon& deletePhraseButtonIcon = QIcon(), QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _hBoxLayout = new QHBoxLayout(this);
        _learnedPhrase = new BasicQTextEdit(this);
        _deletePhraseButton = new BasicQPushButton(deletePhraseButtonIcon, QString(), this);
        _translatedPhrase = new BasicQTextEdit(this);

        _hBoxLayout->addWidget(_learnedPhrase);
        _hBoxLayout->addWidget(_deletePhraseButton);
        _hBoxLayout->addWidget(_translatedPhrase);
        _hBoxLayout->setMargin(0);
        _hBoxLayout->setSpacing(0);

        connect(_deletePhraseButton, SIGNAL(clicked()), this, SLOT(DeletePhraseButton_Clicked()));
    }

    void SetLearnedPhraseText(const QString& text) const
    {
        _learnedPhrase->setText(text);
    }

    void SetTranslatedPhraseText(const QString& text) const
    {
        _translatedPhrase->setText(text);
    }

    QString GetLearnedPhraseText() const
    {
        return _learnedPhrase->placeholderText();
    }

    QString GetTranslatedPhraseText() const
    {
        return _translatedPhrase->placeholderText();
    }

    void SetDeletePhraseButtonIcon(const QIcon& icon)
    {
        _deletePhraseButton->setIcon(icon);
    }
private slots:
    void DeletePhraseButton_Clicked() const
    {
        delete this;
    }
};