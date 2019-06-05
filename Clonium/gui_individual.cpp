#include "gui_individual.h"
#include "cloniumplayer.h"
#include "cloniumia.h"
#include "cloniumgame.h"

unsigned int static NB_HUMANS = 0;
unsigned int static NB_AI = 0;

GUI_Individual::GUI_Individual(QWidget *parent, unsigned int nbHumans, unsigned int nbAI)
{
    NB_HUMANS = nbHumans;
    NB_AI = nbAI;
    int b = 0;

    setFixedSize(500, 700);
    this->setParent(parent);
    m_layout = new QGridLayout;

    m_lblCreatePlayers = new QLabel("Création des joueurs");
    m_lblCreatePlayers->setFont(QFont("Commic Sans MS", 20));
    m_lblCreatePlayers->setStyleSheet("font-weight:bold; color:black");
    m_lblCreatePlayers->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblCreatePlayers->setFrameShadow(QFrame::Raised);
    m_lblCreatePlayers->setAlignment(Qt::AlignHCenter);

    for (unsigned int i = 0; i < nbHumans+nbAI; i++) {

        QLabel *lbl = new QLabel();
        QLineEdit *edit = new QLineEdit();

        if (i < nbHumans){

            lbl -> setText(QString("Joueur n°%1 :").arg(i+1));
            lbl->setFont(QFont("Commic Sans MS", 16));
            lbl->setStyleSheet("QLabel { color : white; }");

            edit->setObjectName(QString("H%1").arg(i));
        }
        else {
            lbl -> setText(QString("Bot n°%1 :").arg(b+1));
            lbl->setFont(QFont("Commic Sans MS", 16));
            lbl->setStyleSheet("QLabel { color : white; }");

            edit->setObjectName(QString("AI%1").arg(b));
            edit->setText(QString("AI%1").arg(b+1));
            edit->setEnabled(false);
            b++;
        }
        m_layout->addWidget(lbl,i+1,0);
        m_layout->addWidget(edit,i+1,1);
    }

    m_btnPlay = new QPushButton("C'est parti !", this);
    m_btnPlay->setFont(QFont("Commic Sans MS", 16));
    connect(m_btnPlay, SIGNAL(clicked()), this, SLOT(getPlayersName()));

    connect(m_btnPlay, SIGNAL(clicked()), this->parent(), SLOT(goToGrid()));

    m_layout->addWidget(m_lblCreatePlayers,0,0,1,2);
    m_layout->addWidget(m_btnPlay,5,0,1,2);
    m_layout->setMargin(50);
    this->setLayout(m_layout);
}

void GUI_Individual::getPlayersName(){
    CloniumGame& g = CloniumGame::Instance();
    int a = 0;

    for(unsigned int i=0;i<NB_HUMANS+NB_AI;i++){

        if (i<NB_HUMANS){
            QLineEdit *le = findChild<QLineEdit*>(QString("H%1").arg(i));
            if(le){
                QString n=le->text();
                std::string name=n.toStdString();

                CloniumPlayer p(i, name);
                g.addPlayer(p);

            }
        }
        else {

            QLineEdit *le = findChild<QLineEdit*>(QString("AI%1").arg(a));
            if(le){
                QString n=le->text();
                std::string name=n.toStdString();

                CloniumIA p(i, name);
                g.addPlayer(p);
                a++;
            }
        }
    }
}

