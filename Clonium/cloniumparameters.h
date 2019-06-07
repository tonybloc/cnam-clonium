#ifndef CLONIUMPARAMETERS_H
#define CLONIUMPARAMETERS_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QRadioButton>

class CloniumParameters : public QWidget
{
    Q_OBJECT

public:
    CloniumParameters(QWidget *parent = nullptr);
    unsigned int returnNbHumanPlayers();
    unsigned int returnNbAIPlayers();

// onclick events on the buttons
private slots:
    void onClickTeam();
    void onClickIndividual();

private:
    //title
    QLabel *m_lblCloParams;

    //number of players
    QGroupBox *m_grpHumans;
    QRadioButton *m_radHum1;
    QRadioButton *m_radHum2;
    QRadioButton *m_radHum3;
    QRadioButton *m_radHum4;
    QHBoxLayout *m_vboxHumans;

    //number of AI players
    QGroupBox *m_grpAI;
    QRadioButton *m_radAI0;
    QRadioButton *m_radAI1;
    QRadioButton *m_radAI2;
    QRadioButton *m_radAI3;
    QHBoxLayout *m_vboxAI;

    // grid shape
    QLabel *m_lblGridShape;
    QComboBox *m_cbo_GridShape;

    // grid shape
    QLabel *m_lblRound;

    //button to create the teams
    QPushButton *m_btnTeam;
    QPushButton *m_btnIndividual;

    //layout of the window
    QGridLayout *m_layout;

    // groupboxes
    QGroupBox *createGrpHumans();
    QGroupBox *createGrpAI();

    bool checkNumberPlayers();
    bool accessToTeam();

    void setNumberOfPlayers();
};

#endif // CLONIUMPARAMETERS_H
