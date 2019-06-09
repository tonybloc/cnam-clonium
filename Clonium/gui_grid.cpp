#include "gui_grid.h"
#include <QMessageBox>
#include <QGraphicsOpacityEffect>

using namespace  std;

const string RED = ":/Ressources/Clonium/Images/Ressources/Clonium/Images/red_";
const string BLUE = ":/Ressources/Clonium/Images/Ressources/Clonium/Images/blue_";
const string GREY = ":/Ressources/Clonium/Images/Ressources/Clonium/Images/grey_";
const string GREEN = ":/Ressources/Clonium/Images/Ressources/Clonium/Images/green_";


ManagerCloniumGame& CloniumGame = ManagerGames::Instance().GetManagerCloniumGame();

GUI_Grid::GUI_Grid(QWidget *parent)
{
    setFixedSize(500, 700);

    this->setParent(parent);
    m_layout = new QGridLayout();

    this->setLayout(m_layout);

    for (uint i = 0; i < CloniumGame.GetGrid()->GetNumberOfRows(); i++) {
        for (uint j = 0; j < CloniumGame.GetGrid()->GetNumberOfColumns(); j++) {
            QPushButton *btn = new QPushButton;

            if(CellContainer* container = CloniumGame.GetGrid()->GetElementAt(i, j))
            {
                if(container->GetIsActive())
                {
                    btn->setStyleSheet("border:0px; border-radius:5px; background-color:#AFEEEE;");

                    if(CloniumPawn* pawn = dynamic_cast<CloniumPawn*>(container->GetPawn()))
                    {
                        UpdateImageSource(btn);
                        if((pawn->GetOwner() == nullptr))
                        {
                            btn->setStyleSheet("border:0px; border-radius:5px; background-color: #4169E1 ;");
                        }
                    }
                }
                else
                {
                    btn->setStyleSheet("border:0px; border-radius:5px; background-color:#483D8B;");
                    btn->setEnabled(false);
                }

                int pawn_width = this->size().width()/CloniumGame.GetGrid()->GetNumberOfRows()-4;
                int icon_with = this->size().width()/CloniumGame.GetGrid()->GetNumberOfRows()-2;

                btn->setFixedSize(QSize(pawn_width,pawn_width));
                btn->setIconSize(QSize(icon_with,icon_with));

                btn->setObjectName(QString("btn%1%2").arg(i).arg(j));
                connect(btn, SIGNAL(clicked()), this, SLOT(onClickButtonGrid()));

                //add button
                m_layout->addWidget(btn,static_cast<int>(i),j);
                // space betwwen lines and columns
                m_layout->setVerticalSpacing(1);
                m_layout->setHorizontalSpacing(1);
                m_layout->setAlignment(Qt::AlignHCenter);

            }
            UpdateImageSource(btn);
        }
    }

    btnSave = new QPushButton;
    btnSave->setIcon(QIcon(":/Ressources/Ressources/save.png"));
    btnSave->setFixedSize(QSize(35,35));
    btnSave->setIconSize(QSize(35,35));
    m_layout->addWidget(btnSave,13,1);
    m_layout->setAlignment(Qt::AlignHCenter);

}

void GUI_Grid::onClickButtonGrid()
{
    QPushButton* btnSender = qobject_cast<QPushButton*>(sender());

    std::cout << "Niveau Pion Cliquee" << GetPawnLinkedToQPushButton(btnSender)->GetLevel() << std::endl;
    std::vector<QPushButton*> listOfButton;
    listOfButton.push_back(btnSender);

    Player *p = CloniumGame.GetCurrentPlayer();
    uint* ligne = new uint();
    uint* colonne = new uint();
    GetRowAndColumnFromQButtonName(btnSender, ligne, colonne);

    if((CloniumGame.GetNumberOfTurn() == 0)){

        std::vector<CellContainerIndex*> * list = CloniumGame.GetGrid()->GetCellContainerWithPawnWithoutOwner();

        for (CellContainerIndex* c : *list) {
            if( c->row == *ligne && c->column == *colonne){
                GetPawnLinkedToQPushButton(btnSender)->SetOwner(p);
                GetPawnLinkedToQPushButton(btnSender)->SetLevel(3);
            }
        }

        UpdateImageSource(btnSender);
        int res = CloniumGame.GetNumberOfPlayer();

        if((CloniumGame.GetCurrentPlayer()->GetId() == CloniumGame.GetNumberOfPlayer()-1) ){
            CloniumGame.NextTurn();
        }
        CloniumGame.GetNextPlayer();


    }
   else  {

        if (GetPawnLinkedToQPushButton(btnSender) == nullptr){
            QMessageBox::information(this, "Information", "Vous ne pouvez cliquer ici ! ");
        }
        else if(GetPawnLinkedToQPushButton(btnSender)->GetOwner()->GetId() != p->GetId()){
            QMessageBox::information(this, "Information", "Vous ne pouvez cliquer ici ! ");
        }
        else{

           UpdateImageSource(btnSender);

            if((CloniumGame.GetCurrentPlayer()->GetId() == CloniumGame.GetNumberOfPlayer())-1 ){
                CloniumGame.NextTurn();
            }
            CloniumGame.GetNextPlayer();

        }
    }

        /*
        if (GetPawnLinkedToQPushButton(btnSender)->GetOwner() == nullptr){
            QMessageBox::information(this, "Information", "Vous ne pouvez cliquer ici ! ");
        }
        else if(GetPawnLinkedToQPushButton(btnSender)->GetOwner()->GetId() != p->GetId()){
            QMessageBox::information(this, "Information", "Vous ne pouvez cliquer ici ! ");
        }
        else{

           UpdateImageSource(btnSender);

            if((CloniumGame.GetCurrentPlayer()->GetId() == CloniumGame.GetNumberOfPlayer())-1 ){
                CloniumGame.NextTurn();
            }
            CloniumGame.GetNextPlayer();

        }

    }*/

    int icon_with = this->size().width()/CloniumGame.GetGrid()->GetNumberOfRows()-2;
    btnSender->setIconSize(QSize(icon_with,icon_with));
    UpdateImageSource(btnSender);
    Split(listOfButton);
}

void GUI_Grid::createFirstButton(uint i, uint j){
    /*
    btnPlayer = new QPushButton;
    btnPlayer->setIcon(QIcon(chooseColor(1, 3)));
    btnPlayer->setStyleSheet("border:0px; border-radius:5px; background-color:purple;");
    btnPlayer->setFixedSize(QSize(this->size().width()/NB_COLUMNS-5,this->size().width()/NB_COLUMNS-5));
    btnPlayer->setIconSize(QSize(this->size().width()/NB_COLUMNS-7,this->size().width()/NB_COLUMNS-7));
    btnPlayer->setObjectName(QString("btn%1%2").arg(i).arg(j));

    connect(btnPlayer, SIGNAL(clicked()), this, SLOT(onClickButtonGrid()));
    m_layout->addWidget(btnPlayer,i,j);
    */
}

void GUI_Grid::createGridButtons(uint i, uint j){

    /*
    btn->setStyleSheet("border:0px; border-radius:5px; background-color:purple;");
    btn->setFixedSize(QSize(this->size().width()/NB_COLUMNS-5,this->size().width()/NB_COLUMNS-5));
    btn->setIconSize(QSize(this->size().width()/NB_COLUMNS-7,this->size().width()/NB_COLUMNS-7));
    btn->setObjectName(QString("btn%1%2").arg(i).arg(j));
    btn->setEnabled(false);
    connect(btn, SIGNAL(clicked()), this, SLOT(onClickButtonGrid()));

    //add button
    m_layout->addWidget(btn,i,j);

    // space betwwen lines and columns
    m_layout->setVerticalSpacing(3);
    m_layout->setHorizontalSpacing(3);
    m_layout->setAlignment(Qt::AlignHCenter);
    */
}

QString GUI_Grid::chooseColor(uint id, uint niveau){
    string chemin;

    switch ( id ) {
    case 0:
      chemin = BLUE+to_string(niveau)+".png";
      break;
    case 1:
        chemin = RED+to_string(niveau)+".png";
        break;
    case 2:
      chemin = GREY+to_string(niveau)+".png";
      break;
    case 3:
      chemin = GREEN+to_string(niveau)+".png";
      break;
    default:
      chemin = "";
      break;

    }

    return QString::fromStdString(chemin);
}

void GUI_Grid::Split(std::vector<QPushButton*> buttons)
{
    ManagerCloniumGame& CloniumGame = ManagerGames::Instance().GetManagerCloniumGame();
    std::vector<QPushButton*>::iterator it = buttons.begin();
    std::vector<QPushButton*> nextButtons;

    if( it == buttons.end())
    {
        return;
    }
    else {
        for(it = buttons.begin(); it != buttons.end(); it++)
        {
            CellContainer* container = GetCellContainerLinkedToQPushButton(*it);
            if(container->GetPawn() != nullptr)
            {
                if(dynamic_cast<CloniumPawn*>(container->GetPawn())->IncreaseLevel())
                {
                    std::vector<CellContainerIndex*>* indexs = CloniumGame.GetGrid()->GetAdjacent(GetCellContainerLinkedToQPushButton(*it));
                    for(CellContainerIndex* index : *indexs)
                    {

                        CellContainer* containerAdjacent = (CloniumGame.GetGrid()->GetElementAt(index->row, index->column));

                        std::cout << "Adjacent : (row="<< index->row << ")(col="<< index->column <<") " << std::endl;
                        if(!containerAdjacent->GetIsActive())
                            continue;

                        QPushButton* buttonTemp = this->findChild<QPushButton*>(QString("btn%1%2").arg(index->row).arg(index->column));
                        nextButtons.push_back(buttonTemp);
                    }
                }
                UpdateImageSource(*it);
            }
            else
            {
                container->SetPawn(new CloniumPawn(1));
                std::cout << "LEVEL = " << dynamic_cast<CloniumPawn*>(container->GetPawn())->GetLevel() << std::endl;
                UpdateImageSource(*it);
            }
        }
        Split(nextButtons);
    }
}

void GUI_Grid::UpdateImageSource(QPushButton* button)
{
    CloniumPawn* pawn = GetPawnLinkedToQPushButton(button);
    if(pawn != nullptr)
    {
        button->setIcon(QIcon(chooseColor(1, pawn->GetLevel())));
        button->setIconSize(QSize(30,30));
    }
}

void GUI_Grid::GetRowAndColumnFromQButtonName(const QPushButton* button, uint* row, uint* column)
{
    QString name = button->objectName();
    *column = static_cast<uint>(name.mid(name.length()-1,1).toInt());
    *row = static_cast<uint>(name.mid(name.length()-2,1).toInt());
}


// Permet de récupérer le CellContainer liée à un QPushButton (il peut être  "nullptr")

CloniumPawn* GUI_Grid::GetPawnLinkedToQPushButton(const QPushButton* button)
{
    return dynamic_cast<CloniumPawn*>(GetCellContainerLinkedToQPushButton(button)->GetPawn());

}
CellContainer* GUI_Grid::GetCellContainerLinkedToQPushButton(const QPushButton* button)
{
    ManagerCloniumGame& CloniumGame = ManagerGames::Instance().GetManagerCloniumGame();
    uint* row = new uint();
    uint* column = new uint();

    GetRowAndColumnFromQButtonName(button, row, column);

    return CloniumGame.GetGrid()->GetElementAt(*row, *column);
}

void GUI_Grid::UpdateImageSource(QPushButton* button)
{
    CloniumPawn* pawn = GetPawnLinkedToQPushButton(button);
    if(pawn != nullptr)
    {
        button->setIcon(QIcon(chooseColor(CloniumGame.GetCurrentPlayer()->GetId(), pawn->GetLevel())));
        button->setToolTip(QString::fromStdString(CloniumGame.GetCurrentPlayer()->GetName()));

        QGraphicsOpacityEffect *eff  = new QGraphicsOpacityEffect(this);
        button->setGraphicsEffect(eff);

        m_animator = new QPropertyAnimation(eff, "opacity");
        m_animator->setDuration(500);
        m_animator->setStartValue(1);
        m_animator->setEndValue(1);
        m_animator->setEasingCurve(QEasingCurve::InBack);
        m_animator->start(QPropertyAnimation::DeleteWhenStopped);

        int icon_with = this->size().width()/CloniumGame.GetGrid()->GetNumberOfRows()-2;
        button->setIconSize(QSize(icon_with,icon_with));

    }
}
