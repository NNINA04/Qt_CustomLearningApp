#pragma once

#include "TabbedPhrasesRecorders.h"

class MainWindow
    : public QMainWindow
{
    TabbedPhrasesRecorders* _tabbedPhrasesRecorder;
public:
    MainWindow(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())
        : QMainWindow(parent, flags)
    {
        _tabbedPhrasesRecorder = new TabbedPhrasesRecorders();
        this->setCentralWidget(_tabbedPhrasesRecorder);
    }
};
