#include "mainmenu.h"
#include "iostream"
#include <QDesktopWidget>

MainMenu::MainMenu(QWidget* parentWidget)
{
    setFixedSize(500, 700);
    this->setParent(parentWidget);

    m_txtMenu = new QLabel("Menu", this);
    m_txtMenu->setStyleSheet("font-weight:bold; color:black");
    m_txtMenu->setFont(QFont("Commic Sans MS", 20));
    m_txtMenu->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_txtMenu->setFrameShadow(QFrame::Raised);
    m_txtMenu->setAlignment(Qt::AlignHCenter);

    m_btnClonium = new QPushButton("Clonium", this);
    m_btnClonium->setFont(QFont("Commic Sans MS", 16));
    m_btnClonium->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_btnClonium, SIGNAL(clicked()), this->parent(), SLOT(goToClonium()));

    m_btnMorpion = new QPushButton("Morpion", this);
    m_btnMorpion->setFont(QFont("Commic Sans MS", 16));
    m_btnMorpion->setCursor(Qt::PointingHandCursor);

    m_btnPuissance4 = new QPushButton("Puisance 4", this);
    m_btnPuissance4->setFont(QFont("Commic Sans MS", 16));
    m_btnPuissance4->setCursor(Qt::PointingHandCursor);

    m_btnAbout = new QPushButton("A propos", this);
    m_btnAbout->setFont(QFont("Commic Sans MS", 16));
    m_btnAbout->setCursor(Qt::PointingHandCursor);
    QObject::connect(m_btnAbout, SIGNAL(clicked()), this->parent(), SLOT(goToAbout()));

    m_layout = new QVBoxLayout;
    m_layout->addWidget(m_txtMenu);
    m_layout->addWidget(m_btnClonium);
    m_layout->addWidget(m_btnMorpion);
    m_layout->addWidget(m_btnPuissance4);
    m_layout->addWidget(m_btnAbout);
    m_layout->setMargin(100);

    this->setLayout(m_layout);
}
