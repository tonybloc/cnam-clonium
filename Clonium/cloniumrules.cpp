#include "cloniumrules.h"

cloniumrules::cloniumrules(QWidget *parent)
{
    setFixedSize(500, 700);
    this->setParent(parent);

    m_lblTitle = new QLabel("Règles", this);
    m_lblTitle->setFont(QFont("Commic Sans MS", 20));
    m_lblTitle->setStyleSheet("font-weight:bold; color:black");
    m_lblTitle->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblTitle->setFrameShadow(QFrame::Raised);
    m_lblTitle->setAlignment(Qt::AlignHCenter);

    m_lblText = new QLabel("Le plateau du jeu est un échiquier carré comportant entre 6 à 10 cases de large, en fonction du choix du joueur. Chaque joueur possède des pions de sa couleur. \n\nUn pion peut être de niveau 1, 2, 3 ou 4. Il ne peut pas se déplacer, mais on peut augmenter son niveau. Un tour de jeu consiste donc à augmenter le niveau d'un de ses pions. Une fois le niveau 3 atteint, une augmentation de son niveau au niveau 4 entraînera immédiatement une scission en 4 pions de niveau 1 qui se placeront dans les cases adjacentes, latéralement et verticalement (pas en diagonale). Si des pions sont présents dans les cases en question : \n- S'ils appartiennent à un joueur adverse on les capture, \n- Dans tous les cas, on augmente leur niveau de 1. \n\nCeci peut entraîner des réactions en chaîne. Lorsque plusieurs pions déclenchent une réaction en chaîne, il peut y avoir plusieurs cases qui sont activées simultanément. On adoptera donc une gestion « tour par tour » des réactions en chaîne.", this);
    m_lblText->setWordWrap(true);
    m_lblText->setFont(QFont("Commic Sans MS", 12));
    m_lblText->setAlignment(Qt::AlignJustify);

    m_btnReturn =new QPushButton("Retour", this);
    m_btnReturn->setFont(QFont("Commic Sans MS", 16));
    m_btnReturn->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_btnReturn, SIGNAL(clicked()), this->parent(), SLOT(RetourMenu()));
    m_lblTitle->setAlignment(Qt::AlignHCenter);

    m_layout = new QVBoxLayout;

    m_layout->addWidget(m_lblTitle);
    m_layout->addWidget(m_lblText);
    m_layout->addWidget(m_btnReturn);
    m_layout->setMargin(50);

    this->setLayout(m_layout);
}
