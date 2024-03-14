#pragma once

#include "PhrasesRecorderTabs.h"

class MainWindow
    : public QMainWindow
{
    BasicQTabWidget* _tabWidget;
public:
    MainWindow(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        : QMainWindow(parent, flags)
    {
        _tabWidget = new PhrasesRecorderTabs(this);
        _tabWidget->AddTabBasedOnAdding();
        this->setCentralWidget(_tabWidget);
        _tabWidget->show();
    }
};
