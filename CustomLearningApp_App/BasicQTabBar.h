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
        if (this->count() > 1)
            this->removeTab(index);
    }

    void TabBarDoubleClicked(int index)
    {
        QRect rect = this->tabRect(index);
        _tabLineEdit->setFixedSize(rect.size());
        _tabLineEdit->move(this->mapToGlobal(rect.topLeft()));
        _tabLineEdit->setText(this->tabText(index));
        _tabLineEdit->show();
    }

    void TabLineEdit_EditingFinished()
    {
        _tabLineEdit->hide();
        this->setTabText(this->currentIndex(), _tabLineEdit->text());
    }
};
