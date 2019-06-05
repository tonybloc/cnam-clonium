#include "gui_team.h"
#include "iostream"
#include <QMessageBox>
#include "cloniumgame.h"
#include "cloniumplayer.h"
#include "cloniumia.h"
#include "cloniumteam.h"
#include "cloniumparameters.h"

const int NB_PLAYERS = 7;
const int NB_TEAMS = 2;
static unsigned int NB_HUMANS = 0;
static unsigned int NB_AI = 0;


GUI_Team::GUI_Team(QWidget *parent, unsigned int nbHumans, unsigned int nbAI)
{
    int e = 0;
    int p = 0;
    NB_HUMANS =  nbHumans;
    NB_AI = nbAI;

    setFixedSize(500, 700);
    this->setParent(parent);
    m_layout = new QGridLayout;

    m_lblCreateTeams = new QLabel("Création des équipes \n et joueurs");
    m_lblCreateTeams->setFont(QFont("Commic Sans MS", 20));
    m_lblCreateTeams->setStyleSheet("font-weight:bold; color:black");
    m_lblCreateTeams->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblCreateTeams->setFrameShadow(QFrame::Raised);
    m_lblCreateTeams->setAlignment(Qt::AlignHCenter);


    m_btnPlay = new QPushButton("C'est parti !", this);
    m_btnPlay->setFont(QFont("Commic Sans MS", 16));
    connect(m_btnPlay, SIGNAL(clicked()), this, SLOT(launchGame()));

    m_layout->addWidget(m_lblCreateTeams,0,0,1,2);


    for (int i = 0; i < NB_PLAYERS; i++) {

        if (i == 0 || i == 4){
            QLabel *m_lblTeam = new QLabel();
            m_lblTeam -> setText(QString("Equipe n°%1 :").arg(e+1));
            m_lblTeam->setFont(QFont("Commic Sans MS", 16));
            m_lblTeam->setStyleSheet("QLabel { color : white; font-weight:bold; border-bottom-width: 3px; border-bottom-style: solid; border-radius: 0px; border-color: white}");
            QLineEdit *m_txtTeam = new QLineEdit();
            m_txtTeam->setObjectName(QString("LineEditTeam%1").arg(e));

            m_layout->addWidget(m_lblTeam,i+1,0);
            m_layout->addWidget(m_txtTeam,i+1,1);
            e++;
        }
        else if (i == 3) {
            QLabel *m_lblVersus= new QLabel("VS");
            m_lblVersus->setFont(QFont("Commic Sans MS", 16));
            m_lblVersus->setStyleSheet("QLabel { color : black; font-weight:bold; }");
            m_lblVersus->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
            m_lblVersus->setFrameShadow(QFrame::Raised);
            m_lblVersus->setAlignment(Qt::AlignHCenter);

            m_layout->addWidget(m_lblVersus,i+1,0,1,2);
        }
        else{
            QLabel *lbl = new QLabel();
            lbl -> setText(QString("Joueur n°%1 :").arg(p+1));
            lbl->setFont(QFont("Commic Sans MS", 16));
            lbl->setStyleSheet("QLabel { color : white; }");

            QLineEdit *edit = new QLineEdit();
            edit->setObjectName(QString("LineEditPlayer%1").arg(p));

            m_layout->addWidget(lbl,i+1,0);
            m_layout->addWidget(edit,i+1,1);
            p++;
        }
    }

    if (nbAI != 0){
        QLabel *lblNote = new QLabel();
        lblNote -> setText(QString("Vous avez selectionné %1 joueur(s) et %2 bot(s). \nVeuillez saisir les noms des joueurs humains, dans les équipes souhaitées.\n La répartition des bots se fera de manière automatique.").arg(nbHumans).arg(nbAI));
        lblNote->setFont(QFont("Commic Sans MS", 12));
        lblNote->setStyleSheet("color:white");
        lblNote->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        lblNote->setFrameShadow(QFrame::Raised);
        lblNote->setWordWrap(true);
        m_layout->addWidget(lblNote,8,0,1,2);
    }


    m_layout->addWidget(m_btnPlay,9,0,1,2);

    m_layout->setMargin(50);
    this->setLayout(m_layout);
}


void GUI_Team::launchGame(){

    // Create Clonium game
    CloniumGame& g = CloniumGame::Instance();

    // Create teams
    for(unsigned int i=0;i<NB_TEAMS;i++){
        QLineEdit *le = findChild<QLineEdit*>(QString("LineEditTeam%1").arg(i));
        if(le){
            QString teamName1=le->text();
            std::string name=teamName1.toStdString();

            CloniumTeam p(i, name);

        }
    }


    // Create human players
    for(unsigned int i=0;i<NB_HUMANS+NB_AI;i++){

        if (i<NB_HUMANS){
            QLineEdit *le = findChild<QLineEdit*>(QString("LineEditPlayer%1").arg(i));
            if(le){
                QString teamName1=le->text();
                std::string xMax=teamName1.toStdString();

                CloniumPlayer p(i, xMax);
                g.addPlayer(p);
            }
        }
        else {
            QLineEdit *le = findChild<QLineEdit*>(QString("LineEdit%1").arg(i));

            if(le){
                QString teamName1=le->text();
                std::string xMax=teamName1.toStdString();

                CloniumIA p(i, xMax);
                g.addPlayer(p);
            }
        }


    }

    // Create AI players
    /*for(unsigned int i=0;i<NB_AI;i++){
        QLineEdit *le = findChild<QLineEdit*>(QString("LineEdit%1").arg(i));
        if(le){
            QString teamName1=le->text();
            std::string xMax=teamName1.toStdString();

            CloniumIA p(i, xMax);
            g.addPlayer(p);
        }
    }*/
}


