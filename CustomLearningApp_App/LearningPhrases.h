#pragma once

class LearningPhrases
    : public QWidget
{
    QWidget* _parent;
    QPlainTextEdit* _text;
public:
    explicit LearningPhrases(QWidget* parent, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(nullptr, f)
        , _parent(parent)
    {
        _text = new QPlainTextEdit("Test");
    }

    virtual ~LearningPhrases()
    {
        delete _text;
    }
protected:
    virtual void closeEvent(QCloseEvent* event) override
    {
        _parent->show();
        delete this;
    }
};
