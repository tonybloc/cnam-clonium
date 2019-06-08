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
#include <QPair>
#include <QString>

#include "managergames.h"
#include "vector"

class CloniumParameters : public QWidget
{
    Q_OBJECT

public:
    CloniumParameters(QWidget *parent = nullptr);
    uint GetNbHumanSelected() const;
    uint GetNbIASelected() const;

// onclick events on the buttons
private slots:
    //void onClickTeam();
    void onClickIndividual();

private:

    QMap<QString, AvailableCloniumGrid>* ShapOption;

    //title
    QLabel *m_lblCloParams;

    //number of players
    QMap<uint,QRadioButton*>* m_RadioButtonsHumanSelector;
    QGroupBox *m_grpHumans;
    QHBoxLayout *m_vboxHumans;

    //number of AI players    
    QMap<uint,QRadioButton*>* m_RadioButtonsIASelector;
    QGroupBox *m_grpAI;
    QHBoxLayout *m_vboxAI;

    // grid shape
    QLabel *m_lblGridShape;
    QComboBox *m_cbo_GridShape;

    // grid shape
    QLabel *m_lblRound;

    //button to create the teams
    //QPushButton *m_btnTeam;
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
