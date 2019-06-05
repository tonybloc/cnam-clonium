#ifndef CLONIUMRULES_H
#define CLONIUMRULES_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "cloniummenu.h"

class cloniumrules: public QWidget
{
    Q_OBJECT

public:
    cloniumrules(QWidget *parent = nullptr);
public slots:
private:
    QLabel *m_lblTitle;

    QLabel *m_lblText;

    QPushButton *m_btnReturn;

    QVBoxLayout *m_layout;
};

#endif // CLONIUMRULES_H
