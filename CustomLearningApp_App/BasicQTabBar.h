#pragma once


class BasicQTabBar
    : public QTabBar
{
    Q_OBJECT;

    QLineEdit* _tabLineEdit;
public:
    BasicQTabBar(QWidget* parent = nullptr)
        : QTabBar(parent)
    {
        _tabLineEdit = new QLineEdit(this);
        
        _tabLineEdit->setWindowFlags(Qt::Popup);
        
        connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(TabCloseRequested(int)));
        connect(this, SIGNAL(tabBarDoubleClicked(int)), this, SLOT(TabBarDoubleClicked(int)));
        connect(_tabLineEdit, SIGNAL(editingFinished()), this, SLOT(TabLineEdit_EditingFinished()));
    }
private slots:
    void TabCloseRequested(int index)
    {
        // Write a thing that checks if PhrasesRecorder has anything and if not just delete it otherwise ask wheater delete or not using QBoxLayout
        this->removeTab(index);
    }

    void TabBarDoubleClicked(int index)
    {
        QRect rect = this->tabRect(index);
        _tabLineEdit->setFixedSize(rect.size());
        _tabLineEdit->move(this->mapToGlobal(rect.topLeft()));
        _tabLineEdit->setText(this->tabText(index));
        if (_tabLineEdit->isVisible() == false)
            _tabLineEdit->show();
    }

    void TabLineEdit_EditingFinished()
    {
        int index = currentIndex();
        if (index >= 0)
            _tabLineEdit->hide();
        this->setTabText(index, _tabLineEdit->text());
    }
};
