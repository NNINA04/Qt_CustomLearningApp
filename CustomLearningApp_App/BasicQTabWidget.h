#pragma once

#include "BasicQTabBar.h"


class BasicQTabWidget
    : public QTabWidget
{
    Q_OBJECT;

    QPushButton* _addTabButton;

    QWidget* (*_basicTabCreator)();

    int _createdTabs = 0;
public:
    BasicQTabWidget(QWidget* (*basicTabCreator)(), QWidget* parent = nullptr)
        : QTabWidget(parent)
        , _basicTabCreator(basicTabCreator)
    {
        _addTabButton = new QPushButton(QIcon("AddTabButton.png"), QString(), this);

        this->setCornerWidget(_addTabButton, Qt::TopRightCorner);
        this->setTabBar(new BasicQTabBar(this));
        this->setTabsClosable(true);
        this->setMovable(true);

        auto t = []()->QWidget* { return nullptr; };
        void (*ptr)() = []() {};

        connect(_addTabButton, SIGNAL(clicked(bool)), this, SLOT(AddTabButton_Clicked(bool)));
    }

    auto GetBasicTabCreator() const
    {
        return _basicTabCreator;
    }

    void SetBasicTabCreator(QWidget* (*basicTabCreator)())
    {
        _basicTabCreator = basicTabCreator;
    }

    void AddBasicTab()
    {
        this->addTab(_basicTabCreator(), QString("Tab %1").arg(++_createdTabs));
    }
private slots:
    void AddTabButton_Clicked(bool checked = false)
    {
        this->AddBasicTab();
    }
};