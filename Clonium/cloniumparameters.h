#ifndef CLONIUMPARAMETERS_H
#define CLONIUMPARAMETERS_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>

class CloniumParameters : public QWidget
{
    Q_OBJECT

public:
    CloniumParameters(QWidget *parent = nullptr);

public slots:

private:
    //title
    QLabel *m_lblCloParams;

    //number of players
    QLabel *m_lblNbPlayer;
    QComboBox *m_cbo_NbPlayer;

    // grid shape
    QLabel *m_lblGridShape;
    QComboBox *m_cbo_GridShape;

    // grid shape
    QLabel *m_lblRound;

    //button to launch the game
    QPushButton *m_btnPlay;

    QGridLayout *m_layout;

};

#endif // CLONIUMPARAMETERS_H
