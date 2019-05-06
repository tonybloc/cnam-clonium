#include "cloniumparameters.h"
#include "iostream"
#include <QDesktopWidget>

CloniumParameters::CloniumParameters(QWidget *parent)
{
    setFixedSize(500, 700);
    this->setParent(parent);

    m_lblCloParams = new QLabel("Paramètres");
    m_lblCloParams->setFont(QFont("Commic Sans MS", 20));
    m_lblCloParams->setStyleSheet("font-weight:bold; color:black");
    m_lblCloParams->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblCloParams->setFrameShadow(QFrame::Raised);
    m_lblCloParams->setAlignment(Qt::AlignHCenter);

    //number of players
    m_lblNbPlayer = new QLabel("Nombre de joueurs :");
    m_lblNbPlayer->setFont(QFont("Commic Sans MS", 16));
    m_lblNbPlayer->setWordWrap(true);

    m_cbo_NbPlayer = new QComboBox;
    m_cbo_NbPlayer->addItem(tr("2"));
    m_cbo_NbPlayer->addItem(tr("3"));
    m_cbo_NbPlayer->addItem(tr("4"));

    // grid shape
    m_lblGridShape = new QLabel("Forme de la grille :");
    m_lblGridShape->setFont(QFont("Commic Sans MS", 16));
    m_lblGridShape->setWordWrap(true);

    m_cbo_GridShape = new QComboBox;
    m_cbo_GridShape->addItem(tr("Carrée"));
    m_cbo_GridShape->addItem(tr("Rectangulaire"));
    m_cbo_GridShape->addItem(tr("Ronde"));

    // grid shape
    m_lblRound = new QLabel("Reprendre une partie");
    m_lblNbPlayer->setFont(QFont("Commic Sans MS", 16));

    //button to launch the game
    m_btnPlay= new QPushButton("C'est parti !", this);
    m_btnPlay->setFont(QFont("Commic Sans MS", 16));
    m_btnPlay->setCursor(Qt::PointingHandCursor);

    m_layout = new QGridLayout;
    m_layout->addWidget(m_lblCloParams,0,0,1,2);
    m_layout->addWidget(m_lblNbPlayer,1,0);
    m_layout->addWidget(m_cbo_NbPlayer,1,1);
    m_layout->addWidget(m_lblGridShape,2,0);
    m_layout->addWidget(m_cbo_GridShape,2,1);
    //m_layout->addWidget(m_lblRound,3,0);
    m_layout->addWidget(m_btnPlay,4,0,1,2);
    m_layout->setMargin(100);

    this->setLayout(m_layout);
}

