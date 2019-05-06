#ifndef MAINMENU_H
#define MAINMENU_H

#include <QApplication>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class MainMenu : public QWidget
{
public:
    MainMenu(QWidget *parentWidget);

signals:
 //   void goToAbout();

public slots:

private:
    QLabel *m_txtMenu;
    QPushButton *m_btnClonium;
    QPushButton *m_btnMorpion;
    QPushButton *m_btnPuissance4;
    QPushButton *m_btnAbout;
    QGridLayout *m_gridLayout;
    QVBoxLayout *m_layout;
};

#endif // MAINMENU_H
