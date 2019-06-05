#include "cloniummenu.h"

CloniumMenu::CloniumMenu(QWidget *parent)
{
    setFixedSize(500, 700);
    this->setParent(parent);

    m_lblClonium = new QLabel("Clonium", this);
    m_lblClonium->setFont(QFont("Commic Sans MS", 20));
    m_lblClonium->setStyleSheet("font-weight:bold; color:black");
    m_lblClonium->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblClonium->setFrameShadow(QFrame::Raised);
    m_lblClonium->setAlignment(Qt::AlignHCenter);

    m_btnPlay = new QPushButton("Lancer le jeu !", this);
    m_btnPlay->setFont(QFont("Commic Sans MS", 16));
    m_btnPlay->setCursor(Qt::PointingHandCursor);
    connect(m_btnPlay, SIGNAL(clicked()), this->parent(), SLOT(goToCloniumParams()));

    m_btnOptions = new QPushButton("Options", this);
    m_btnOptions->setFont(QFont("Commic Sans MS", 16));
    m_btnOptions->setCursor(Qt::PointingHandCursor);
    m_lblClonium->setAlignment(Qt::AlignHCenter);

    m_btnGameRules = new QPushButton("Règles du jeu", this);
    m_btnGameRules->setFont(QFont("Commic Sans MS", 16));
    m_btnGameRules->setCursor(Qt::PointingHandCursor);
    m_lblClonium->setAlignment(Qt::AlignHCenter);
    connect(m_btnGameRules, SIGNAL(clicked()), this->parent(), SLOT(goToCloniumRules()));


    m_btnReturn =new QPushButton("Retour", this);
    m_btnReturn->setFont(QFont("Commic Sans MS", 16));
    m_btnReturn->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_btnReturn, SIGNAL(clicked()), this->parent(), SLOT(RetourMenu()));
    m_lblClonium->setAlignment(Qt::AlignHCenter);

    m_layout = new QVBoxLayout;
    m_layout->addWidget(m_lblClonium);
    m_layout->addWidget(m_btnPlay);
    m_layout->addWidget(m_btnOptions);
    m_layout->addWidget(m_btnGameRules);
    m_layout->addWidget(m_btnReturn);
    m_layout->setMargin(100);

    this->setLayout(m_layout);
}
