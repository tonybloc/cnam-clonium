#include "about.h"

About::About(QWidget *parent)
{
    setFixedSize(500, 700);
    this->setParent(parent);

    m_lblTitle = new QLabel("A propos", this);
    m_lblTitle->setFont(QFont("Commic Sans MS", 20));
    m_lblTitle->setStyleSheet("font-weight:bold; color:black");
    m_lblTitle->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblTitle->setFrameShadow(QFrame::Raised);
    m_lblTitle->setAlignment(Qt::AlignHCenter);

    m_lblText = new QLabel("Cette application a été réalisée par : \n\n Bruno Malvy\n\n Anthony Mochel\n\n Carole Treser", this);
    m_lblText->setWordWrap(true);
    m_lblText->setFont(QFont("Commic Sans MS", 20));
    m_lblText->setAlignment(Qt::AlignCenter);

    m_btnReturn =  new QPushButton("Retour", this);
    m_btnReturn->setFont(QFont("Commic Sans MS", 16));
    m_btnReturn->setCursor(Qt::PointingHandCursor);
    connect(m_btnReturn, SIGNAL(clicked()), this->parent(), SLOT(RetourMenu()));

    m_layout = new QVBoxLayout;

    m_layout->addWidget(m_lblTitle);
    m_layout->addWidget(m_lblText);
    m_layout->addWidget(m_btnReturn);
    m_layout->setMargin(120);

    this->setLayout(m_layout);
}
