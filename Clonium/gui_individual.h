#ifndef GUI_INDIVIDUAL_H
#define GUI_INDIVIDUAL_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class GUI_Individual : public QWidget
{
     Q_OBJECT

public:
    GUI_Individual(QWidget *parent = nullptr, unsigned int nbHumans=0, unsigned int nbAI=0);

private slots:
    void getPlayersName();

private:
    //title
    QLabel *m_lblCreatePlayers;

    QLabel *m_lblPlayer1;
    QLineEdit *m_txtPlayer1;

    QLabel *m_lblPlayer2;
    QLineEdit *m_txtPlayer2;

    QLabel *m_lblPlayer3;
    QLineEdit *m_txtPlayer3;

    QLabel *m_lblPlayer4;
    QLineEdit *m_txtPlayer4;

    //launch the game
    QPushButton *m_btnPlay;

    //layout of the window
    QGridLayout *m_layout;
};

#endif // GUI_INDIVIDUAL_H
