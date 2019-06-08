#ifndef GUI_INDIVIDUAL_H
#define GUI_INDIVIDUAL_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "managergames.h"

class GUI_Individual : public QWidget
{
     Q_OBJECT

public:
    GUI_Individual(QWidget *parent = nullptr, unsigned int nbHumans=0, unsigned int nbAI=0);

    inline uint GetNumberOfHumans(void) const {return m_numberOfHumans;}
    inline uint GetNumberOfIA(void) const {return m_numberOfIA;}
    inline uint GetNumberOfPlayer(void) const {return m_numberOfIA+m_numberOfHumans;}

    typedef struct {
        QLabel* m_label;
        QLineEdit* m_lineEdite;
    } Inputs;

private slots:
    void startGame();

private:
    uint m_numberOfHumans;
    uint m_numberOfIA;

    QList<Inputs*>* m_PlayerInputs;

    //title
    QLabel *m_lblCreatePlayers;


    //launch the game
    QPushButton *m_btnPlay;

    //layout of the window
    QGridLayout *m_layout;
};

#endif // GUI_INDIVIDUAL_H
