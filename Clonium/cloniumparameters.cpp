#include "cloniumparameters.h"
#include "iostream"
#include <QDesktopWidget>
#include <QMessageBox>

static unsigned int NbHumanPlayers = 0;
static unsigned int NbAIPlayers = 0;

CloniumParameters::CloniumParameters(QWidget *parent)
{
    setFixedSize(500, 700);
    this->setParent(parent);
    m_layout = new QGridLayout;


    m_lblCloParams = new QLabel("Paramètres");
    m_lblCloParams->setFont(QFont("Commic Sans MS", 20));
    m_lblCloParams->setStyleSheet("font-weight:bold; color:black");
    m_lblCloParams->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    m_lblCloParams->setFrameShadow(QFrame::Raised);
    m_lblCloParams->setAlignment(Qt::AlignHCenter);

    // grid shape
    m_lblGridShape = new QLabel("Forme de la grille :");
    m_lblGridShape->setFont(QFont("Commic Sans MS", 12));
    m_lblGridShape->setWordWrap(true);

    m_cbo_GridShape = new QComboBox;
    m_cbo_GridShape->addItem(tr("Carrée"));
    m_cbo_GridShape->addItem(tr("Rectangulaire"));
    m_cbo_GridShape->addItem(tr("Ronde"));

    // resume a game
    //m_lblRound = new QLabel("Reprendre une partie");
    //m_lblNbPlayer->setFont(QFont("Commic Sans MS", 16));

    //button to create teams
    /*m_btnTeam= new QPushButton("Jouer en équipe", this);
    m_btnTeam->setFont(QFont("Commic Sans MS", 12));
    m_btnTeam->setCursor(Qt::PointingHandCursor);
    connect(m_btnTeam, SIGNAL(clicked()), this, SLOT(onClickTeam()));*/

    //button to create players
    m_btnIndividual= new QPushButton("Jouer", this);
    m_btnIndividual->setFont(QFont("Commic Sans MS", 12));
    m_btnIndividual->setCursor(Qt::PointingHandCursor);
    connect(m_btnIndividual, SIGNAL(clicked()), this, SLOT(onClickIndividual()));

    m_layout->addWidget(m_lblCloParams,0,0,1,2);
    //number of players
    m_layout->addWidget(createGrpHumans(),1,0,1,2);
    //number of AI players
    m_layout->addWidget(createGrpAI(),2,0,1,2);

    //shape of the grid
    m_layout->addWidget(m_lblGridShape,3,0);
    m_layout->addWidget(m_cbo_GridShape,3,1);

    //team or individual
    //m_layout->addWidget(m_btnTeam,4,0);
    m_layout->addWidget(m_btnIndividual,4,0,1,2);
    m_layout->setMargin(50);

    this->setLayout(m_layout);

}

// Create group box for humans
QGroupBox *CloniumParameters::createGrpHumans(){
    m_grpHumans = new QGroupBox(tr("Nombre de joueurs :"));
    m_grpHumans->setMaximumHeight(100);

    m_radHum1 = new QRadioButton(tr("&1"));
    m_radHum1->setObjectName(QString("H1"));
    m_radHum2 = new QRadioButton(tr("&2"));
    m_radHum2->setObjectName(QString("H2"));
    m_radHum3 = new QRadioButton(tr("&3"));
    m_radHum3->setObjectName(QString("H3"));
    m_radHum4 = new QRadioButton(tr("&4"));
    m_radHum4->setObjectName(QString("H4"));

    m_radHum1->setChecked(true);

    m_vboxHumans = new QHBoxLayout;
    m_vboxHumans->addWidget(m_radHum1);
    m_vboxHumans->addWidget(m_radHum2);
    m_vboxHumans->addWidget(m_radHum3);
    m_vboxHumans->addWidget(m_radHum4);
    m_vboxHumans->addStretch(1);
    m_grpHumans->setLayout(m_vboxHumans);

    return m_grpHumans;
}

// Create group box for AI
QGroupBox *CloniumParameters::createGrpAI(){
    m_grpAI = new QGroupBox(tr("Nombre d'intelligences artificielles :"));
    m_grpAI->setMaximumHeight(100);

    m_radAI0 = new QRadioButton(tr("&0"));
    m_radAI0->setObjectName(QString("AI0"));
    m_radAI1 = new QRadioButton(tr("&1"));
    m_radAI1->setObjectName(QString("AI1"));
    m_radAI2 = new QRadioButton(tr("&2"));
    m_radAI2->setObjectName(QString("AI2"));
    m_radAI3 = new QRadioButton(tr("&3"));
    m_radAI3->setObjectName(QString("AI3"));

    m_radAI1->setChecked(true);

    m_vboxAI = new QHBoxLayout;
    m_vboxAI->addWidget(m_radAI0);
    m_vboxAI->addWidget(m_radAI1);
    m_vboxAI->addWidget(m_radAI2);
    m_vboxAI->addWidget(m_radAI3);

    m_vboxAI->addStretch(1);
    m_grpAI->setLayout(m_vboxAI);

    return m_grpAI;
}

// check the number of players before launching the game
bool CloniumParameters::checkNumberPlayers(){

    bool correct = false;

    if (m_radHum1->isChecked() && m_radAI0->isChecked()){
        QMessageBox::information(this, "Information", "Impossible ! 2 joueurs minimum.");
    }

    if ((m_radHum2->isChecked() && m_radAI3->isChecked()) ||
            (m_radHum3->isChecked() && (m_radAI2->isChecked() || m_radAI3->isChecked())) ||
            (m_radHum4->isChecked() && (m_radAI1->isChecked() || m_radAI2->isChecked() || m_radAI3->isChecked() ))){
        QMessageBox::information(this, "Information", "Impossible ! 4 joueurs maximum.");
    }

    return correct;
}

bool CloniumParameters::accessToTeam(){
    bool access = false;

    if ((m_radHum1->isChecked() && m_radAI3->isChecked()) ||
            (m_radHum2->isChecked() && m_radAI2->isChecked()) ||
            (m_radHum3->isChecked() && m_radAI1->isChecked()) ||
            (m_radHum4->isChecked() && m_radAI0->isChecked())){
        access=true;
    }
    else {
        QMessageBox::information(this, "Information", "Impossible ! 2 joueurs par équipe. \n Sinon, jouer individuellement.");
    }

    return access;
}

void CloniumParameters::setNumberOfPlayers(){
    for(unsigned int i=0;i<4;i++){
        QRadioButton *rad_human = findChild<QRadioButton*>(QString("H%1").arg(i));
        QRadioButton *rad_AI = findChild<QRadioButton*>(QString("AI%1").arg(i));
        if(rad_human){
            if (rad_human->isChecked()){
                QString human=rad_human->text();
                NbHumanPlayers=human.remove(0,1).toInt(nullptr, 10);
            }
        }

        if(rad_AI){
            if (rad_AI->isChecked()){
                QString name=rad_AI->text();
                NbAIPlayers=name.remove(0,1).toInt(nullptr, 10);
            }
        }

    }
}

void CloniumParameters::onClickTeam(){

    if (accessToTeam()){
        if (!checkNumberPlayers()){

            setNumberOfPlayers();
            //QMessageBox::information(this,"Information",  QString( "Nb HUmans : %1 Nb IA :%2 ").arg(NbHumanPlayers).arg(NbAIPlayers) );
            QObject::connect(m_btnTeam, SIGNAL(clicked()), this->parent(), SLOT(goToTeams()));
        }
    }
}

void CloniumParameters::onClickIndividual(){
    if (!checkNumberPlayers()){

        setNumberOfPlayers();
        QObject::connect(m_btnIndividual, SIGNAL(clicked()), this->parent(), SLOT(goToIndividual()));

    }
}

unsigned int CloniumParameters::returnNbHumanPlayers(){
    return NbHumanPlayers;
}

unsigned int CloniumParameters::returnNbAIPlayers(){
    return NbAIPlayers;
}

