#pragma once

#include "BasicQTabWidget.h"
#include "PhrasesRecorder.h"
#include "LocalDataStorage.h"

class TabbedPhrasesRecorders
    : public QWidget
{
    QVBoxLayout* _vBoxLayout;
    BasicQTabWidget* _tabWidget;
public:
    TabbedPhrasesRecorders(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QWidget(parent, f)
    {
        _vBoxLayout = new QVBoxLayout(this);
        _tabWidget = new BasicQTabWidget([]() -> QWidget* { return new PhrasesRecorder(); }, this);

        _vBoxLayout->addWidget(_tabWidget);

        _tabWidget->AddBasicTab();
    }
};