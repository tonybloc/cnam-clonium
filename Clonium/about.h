#ifndef ABOUT_H
#define ABOUT_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "cloniummenu.h"
#include "managergames.h"

class About : public QWidget
{
    Q_OBJECT

public:
    About(QWidget *parent = nullptr);

public slots:

private:
    QLabel *m_lblTitle;

    QLabel *m_lblText;

    QPushButton *m_btnReturn;

    CloniumMenu *cloMenu;

    QVBoxLayout *m_layout;
};

#endif // ABOUT_H
