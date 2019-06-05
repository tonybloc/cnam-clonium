#ifndef GUI_TEAM_H
#define GUI_TEAM_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class GUI_Team : public QWidget
{
    Q_OBJECT

public:
    GUI_Team(QWidget *parent = nullptr, unsigned int nbHumans=0, unsigned int nbAI=0);

private slots:
    void launchGame();

private:
    //title
    QLabel *m_lblCreateTeams;

    QLabel *m_lblTeam1;
    QLineEdit *m_txtTeam1;

    QLabel *m_lblTeam2;
    QLineEdit *m_txtTeam2;

    QLabel *m_lblVersus;

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

#endif // GUI_TEAM_H
