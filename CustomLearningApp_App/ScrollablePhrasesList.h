#pragma once

#include "LearnedPhrasesList.h"

class ScrollablePhrasesList
    : public QMainWindow
{
    QScrollArea* _scrollArea;
    InputPhraseAreaList* _learnedPhrasesList;
public:
    ScrollablePhrasesList(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        : QMainWindow(parent, flags)
    {
        _scrollArea = new QScrollArea(this);
        _learnedPhrasesList = new InputPhraseAreaList(this);

        _scrollArea->setBackgroundRole(QPalette::Dark);
        _scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        _scrollArea->setGeometry(0, 0, this->width(), this->height());
        _scrollArea->setWidget(_learnedPhrasesList);

        this->setCentralWidget(_scrollArea);
    }

    void AddLearnedPhrase()
    {
        _learnedPhrasesList->AddLearnedPhrase(new InputPhraseArea());
    }
};