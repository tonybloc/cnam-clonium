#ifndef CLONIUMMENU_H
#define CLONIUMMENU_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

#include "cloniumparameters.h"


class CloniumMenu : public QWidget
{
    Q_OBJECT

public:
    explicit CloniumMenu(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLabel *m_lblClonium;
    QPushButton *m_btnPlay;
    QPushButton *m_btnOptions;
    QPushButton *m_btnGameRules;
    QPushButton *m_btnReturn;

    QVBoxLayout *m_layout;
};

#endif // CLONIUMMENU_H
