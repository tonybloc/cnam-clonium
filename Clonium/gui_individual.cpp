#include "gui_individual.h"
#include "CloniumModels/cloniumplayer.h"
#include "CloniumModels/cloniumia.h"
#include "managergames.h"


GUI_Individual::GUI_Individual(QWidget *parent, unsigned int nbHumans, unsigned int nbAI)
    : m_numberOfHumans(nbHumans), m_numberOfIA(nbAI)
{
    int b = 0;

    setFixedSize(500, 700);
    this->setParent(parent);
    m_layout = new QGridLayout;

    m_lblCreatePlayers = new QLabel("Création des joueurs");
    m_lblCreatePlayers->setFont(QFont("Commic Sans MS", 20));
    m_lblCreatePlayers->setStyleSheet("font-weight:bold; color:White");
    m_lblCreatePlayers->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblCreatePlayers->setFrameShadow(QFrame::Raised);
    m_lblCreatePlayers->setAlignment(Qt::AlignHCenter);


    m_PlayerInputs = new QList<Inputs*>();
    for (uint i = 0; i < GetNumberOfPlayer(); i++) {

        Inputs* fields = new Inputs();
        fields->m_label = new QLabel();
        fields->m_lineEdite = new QLineEdit();

        // Generate input fields specific to Humans
        if (i < GetNumberOfHumans())
        {
            fields->m_label->setText(QString("Joueur n°%1 :").arg(i+1));
            fields->m_label->setFont(QFont("Commic Sans MS", 16));
            fields->m_label->setStyleSheet("QLabel { color : white; }");

            fields->m_lineEdite->setObjectName(QString("H%1").arg(i));
        }
        // Generate input fields specific to Humans
        else {
            fields->m_label->setText(QString("Bot n°%1 :").arg(b+1));
            fields->m_label->setFont(QFont("Commic Sans MS", 16));
            fields->m_label->setStyleSheet("QLabel { color : white; }");

            fields->m_lineEdite->setObjectName(QString("AI%1").arg(b));
            fields->m_lineEdite->setText(QString("AI%1").arg(b+1));
            fields->m_lineEdite->setEnabled(false);
            b++;
        }


        m_layout->addWidget(fields->m_label, static_cast<int>(i+1), 0);
        m_layout->addWidget(fields->m_lineEdite, static_cast<int>(i+1), 1);

        m_PlayerInputs->append(fields);
    }

    m_btnPlay = new QPushButton("C'est parti !", this);
    m_btnPlay->setFont(QFont("Commic Sans MS", 16));

    connect(m_btnPlay, SIGNAL(clicked()), this, SLOT(startGame()));

    m_layout->addWidget(m_lblCreatePlayers,0,0,1,2);
    m_layout->addWidget(m_btnPlay,5,0,1,2);
    m_layout->setMargin(50);
    this->setLayout(m_layout);
}

void GUI_Individual::startGame()
{
    ManagerCloniumGame& CloniumGame = ManagerGames::Instance().GetManagerCloniumGame();

    uint index = 0;
    QList<Inputs*>::iterator it;
    for(it = m_PlayerInputs->begin(); it != m_PlayerInputs->end(); it++)
    {
        if ( index < GetNumberOfHumans())
        {
            if((*it)->m_lineEdite != nullptr)
            {
                std::string name = (*it)->m_lineEdite->text().toStdString();
                CloniumGame.AddCloniumPlayer(new CloniumPlayer(index, name));
            }
        }
        else
        {
            if((*it)->m_lineEdite != nullptr)
            {
                std::string name = (*it)->m_lineEdite->text().toStdString();
                CloniumGame.AddCloniumPlayer(new CloniumIA(index, name));
            }
        }
        index++;
    }

    std::cout << "BEFOR GOTOGRID" << std::endl;
    //CloniumGame.GetGrid()->ShowGrid();
    QMetaObject::invokeMethod(this->parent(), "goToGrid");
}

