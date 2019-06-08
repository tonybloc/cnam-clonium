#include "cloniumparameters.h"
#include "iostream"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QStringList>

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


    // -- Selectors of Shapes -- //

    m_lblGridShape = new QLabel("Taille de la grille :");
    m_lblGridShape->setFont(QFont("Commic Sans MS", 12));
    m_lblGridShape->setWordWrap(true);

    ShapOption = new QMap<QString, AvailableCloniumGrid>();
    ShapOption->insert("Grande", AvailableCloniumGrid::BigRectangle);
    ShapOption->insert("Moyenne", AvailableCloniumGrid::MediumRectangle);
    ShapOption->insert("Petite", AvailableCloniumGrid::SmallRectangle);

    m_cbo_GridShape = new QComboBox;
    m_cbo_GridShape->addItems(QStringList(ShapOption->keys()));
    m_cbo_GridShape->setCurrentIndex(1);


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
    m_layout->addWidget(createGrpHumans(),1,0,1,2);  // Group of RadioButton (Humans)
    m_layout->addWidget(createGrpAI(),2,0,1,2);      // Group of RadioButton (IA)

    //shape of the grid
    m_layout->addWidget(m_lblGridShape,3,0);
    m_layout->addWidget(m_cbo_GridShape,3,1);

    //team or individual
    //m_layout->addWidget(m_btnTeam,4,0);
    m_layout->addWidget(m_btnIndividual,4,0,1,2);
    m_layout->setMargin(50);

    this->setLayout(m_layout);

}

///
/// \brief CloniumParameters::createGrpHumans
/// \return a group box for humans
///
QGroupBox *CloniumParameters::createGrpHumans(){

    ManagerGames& Game = ManagerGames::Instance();

    m_grpHumans = new QGroupBox(tr("Nombre de joueurs :"));
    m_grpHumans->setMaximumHeight(100);

    // add components in the layout
    m_vboxHumans = new QHBoxLayout;
    m_RadioButtonsHumanSelector = new QMap<uint,QRadioButton*>();

    for(uint index=0; index <= Game.GetManagerCloniumGame().GetMaximumOfPlayer(); index++)
    {
        QRadioButton* radio = new QRadioButton("&"+QString::number(index));
        radio->setObjectName("H"+QString::number(index));
        radio->setChecked( (index == 0) );
        m_vboxHumans->addWidget(radio);
        m_RadioButtonsHumanSelector->insert(index,radio);
    }

    m_vboxHumans->addStretch(1);
    m_grpHumans->setLayout(m_vboxHumans);

    return m_grpHumans;
}
///
/// \brief CloniumParameters::createGrpAI
/// \return a group box for AI
///
QGroupBox *CloniumParameters::createGrpAI(){

    ManagerGames& Game = ManagerGames::Instance();

    m_grpAI = new QGroupBox(tr("Nombre d'intelligences artificielles :"));
    m_grpAI->setMaximumHeight(100);

    m_vboxAI = new QHBoxLayout;
    m_RadioButtonsIASelector = new QMap<uint,QRadioButton*>();

    for(uint index=0; index <= Game.GetManagerCloniumGame().GetMaximumOfPlayer(); index++)
    {
        QRadioButton* radio = new QRadioButton("&"+QString::number(index));
        radio->setObjectName("AI"+QString::number(index));
        radio->setChecked( (index == 0) );
        m_vboxAI->addWidget(radio);
        m_RadioButtonsIASelector->insert(index,radio);
    }

    m_vboxAI->addStretch(1);
    m_grpAI->setLayout(m_vboxAI);

    return m_grpAI;
}


///
/// \brief CloniumParameters::checkNumberPlayers
/// \return check if the number of players is right, before launching the game
///

// check the number of players before launching the game
bool CloniumParameters::checkNumberPlayers()
{
    if( (m_RadioButtonsIASelector != nullptr) && (m_RadioButtonsHumanSelector != nullptr) )
    {
        uint numberOfIA = GetNbIASelected();
        uint numberOfHumans = GetNbHumanSelected();
        uint maxPlayer = static_cast<uint>(ManagerGames::Instance().GetManagerCloniumGame().GetMaximumOfPlayer());
        uint minPlayer = static_cast<uint>(ManagerGames::Instance().GetManagerCloniumGame().GetMinimumOfPlayer());

        //std::cout << "Selected (IA)" << numberOfIA << " (Humain)"<< numberOfHumans << std::endl;
        //std::cout << "MAX : " << maxPlayer << " MIN :"<< minPlayer << std::endl;

        if((numberOfIA != 0) && (numberOfHumans == 0))
        {
            QMessageBox::information(this, "Information", "Impossible ! Aucun joueurs humain dans la partie !");
            return false;
        }
        if(numberOfIA+numberOfHumans > maxPlayer)
        {
            QMessageBox::information(this, "Information", QString("Impossible ! %1 joueurs maximum.").arg(maxPlayer));
            return false;
        }
        if(numberOfIA+numberOfHumans < minPlayer)
        {
            QMessageBox::information(this, "Information", QString("Impossible ! %1 joueurs minimum.").arg(minPlayer));
            return false;
        }
        return true;
    }
    else
    {
        QMessageBox::information(this, "Information", "Les RadioBouton ne sont pas définie !");
        return false;
    }
}

///
/// \brief CloniumParameters::accessToTeam
/// \return if we can access to the window of teams
///
bool CloniumParameters::accessToTeam(){
    /*
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
    */
    return false;
}

/*
///
/// \brief CloniumParameters::setNumberOfPlayers
/// check which buttons have been clicked, and set the right values in order to
/// generate the number of textedit for the players
///
*/
/*
>>>>>>> fix(view): update views according models
void CloniumParameters::setNumberOfPlayers(){

    for(unsigned int i=0;i<4;i++){
        QRadioButton *rad_human = findChild<QRadioButton*>(QString("H%1").arg(i));
        QRadioButton *rad_AI = findChild<QRadioButton*>(QString("AI%1").arg(i));
        if(rad_human){
            if (rad_human->isChecked()){
                QString human=rad_human->text();
                NbHumanPlayers=human.toInt(nullptr, 10);

            }
        }

        if(rad_AI){
            if (rad_AI->isChecked()){
                QString name=rad_AI->text();
                NbAIPlayers=name.toInt(nullptr, 10);
            }
        }

    }
}

///
/// \brief CloniumParameters::onClickTeam
/// event on click on the team button, to access to the creation of the players and teams in the next window
///
*/
/*
>>>>>>> fix(view): update views according models
void CloniumParameters::onClickTeam(){

    if (accessToTeam()){
        if (!checkNumberPlayers()){

            setNumberOfPlayers();
            QObject::connect(m_btnTeam, SIGNAL(clicked()), this->parent(), SLOT(goToTeams()));
        }
    }
}
*/

///
/// \brief CloniumParameters::onClickIndividual
/// event on click on the play button, to access to the creation of the players in the next window
///
void CloniumParameters::onClickIndividual(){
    if (checkNumberPlayers())
    {
        ManagerCloniumGame& CloniumGame = ManagerGames::Instance().GetManagerCloniumGame();
        CloniumGame.InitializeCloniumGame(ShapOption->value(m_cbo_GridShape->currentText()));

        QMetaObject::invokeMethod(this->parent(), "goToIndividual", Q_ARG(uint,GetNbHumanSelected()), Q_ARG(uint,GetNbIASelected()));

    }
}


uint CloniumParameters::GetNbHumanSelected() const
{
    uint value = 0;
    // Get number of humans selected
    QMap<uint,QRadioButton*>::iterator HumanIterator;
    for(HumanIterator = m_RadioButtonsHumanSelector->begin(); HumanIterator != m_RadioButtonsHumanSelector->end(); HumanIterator++)
    {
        if(HumanIterator.value()->isChecked())
        {
            value = HumanIterator.key();
            break;
        }
    }
    return value;
}
uint CloniumParameters::GetNbIASelected() const
{
    uint value = 0;
    // Get number of ia selected
    QMap<uint,QRadioButton*>::iterator IAIterator;
    for(IAIterator = m_RadioButtonsIASelector->begin(); IAIterator != m_RadioButtonsIASelector->end(); IAIterator++)
    {
        if(IAIterator.value()->isChecked())
        {
            value = IAIterator.key();
            break;
        }
    }
    return value;
}

