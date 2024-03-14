#pragma once

#include "BasicQTabBar.h"

class BasicQTabWidget
    : public QTabWidget
{
    Q_OBJECT;

    QPushButton* _addTabButton;

    int _createdTabs = 0;
public:
    BasicQTabWidget(QWidget* parent = nullptr)
        : QTabWidget(parent)
    {
        _addTabButton = new QPushButton(QIcon("AddTabButton.png"), QString(), this);

        this->setCornerWidget(_addTabButton, Qt::TopRightCorner);
        this->setTabBar(new BasicQTabBar(this));
        this->setTabsClosable(true);
        this->setMovable(true);

        connect(_addTabButton, SIGNAL(clicked(bool)), this, SLOT(AddTabButton_Clicked(bool)));
    }

    void AddTabBasedOnAdding()
    {
        this->addTab(this->MakeTabBasedOnAdding(), QString("Tab %1").arg(++_createdTabs));
    }

    virtual QWidget* MakeTabBasedOnAdding() = 0;
private slots:
    void AddTabButton_Clicked(bool checked = false)
    {
        AddTabBasedOnAdding();
    }
};