#include "widgetmanager.h"
#include "iostream"
#include <QDesktopWidget>

WidgetManager::WidgetManager(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(500,700);
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter,this->size(), qApp->desktop()->availableGeometry()));

    QPixmap img(":/images/modern_background.jpg");
    img = img.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, img);
    this->setPalette(palette);

    menu = new MainMenu(this);
    WidgetActif = menu;

    cloMenu = new CloniumMenu(this);
    cloMenu->hide();

    about = new About(this);
    about->hide();

    cloParams = new CloniumParameters(this);
    cloParams->hide();

    cloGrid = new GUI_Grid(this);
    cloGrid->hide();

    cloRules = new cloniumrules(this);
    cloRules->hide();

}

void WidgetManager::RetourMenu()
{
    this->WidgetActif = menu;
    cloMenu->hide();
    about->hide();
    menu->show();
    cloRules->hide();
}

void WidgetManager::goToClonium(){
    this->WidgetActif=cloMenu;
    menu->hide();
    cloMenu->show();
}

void WidgetManager::goToAbout(){
    this->WidgetActif=about;
    menu->hide();
    about->show();
}

void WidgetManager::goToCloniumParams(){
    this->WidgetActif=cloParams;
    cloMenu->hide();
    cloParams->show();
}

void WidgetManager::goToTeams(){
    unsigned int nbHumans = cloParams->returnNbHumanPlayers();
    unsigned int nbAI = cloParams->returnNbAIPlayers();
    cloTeams = new GUI_Team(this, nbHumans, nbAI);

    this->WidgetActif=cloTeams;
    cloParams->hide();
    cloTeams->show();
}

void WidgetManager::goToIndividual(){
    unsigned int nbHumans = cloParams->returnNbHumanPlayers();
    unsigned int nbAI = cloParams->returnNbAIPlayers();

    cloIndi = new GUI_Individual(this, nbHumans, nbAI);
    this->WidgetActif=cloIndi;
    cloParams->hide();
    cloIndi->show();
}

void WidgetManager:: goToGrid(){
    unsigned int nbHumans = cloParams->returnNbHumanPlayers();
    unsigned int nbAI = cloParams->returnNbAIPlayers();

    cloGrid = new GUI_Grid(this, nbHumans, nbAI);
    this->WidgetActif=cloGrid;
    cloIndi->hide();
    cloGrid->show();
}

void WidgetManager::goToCloniumRules(){
    this->WidgetActif=cloRules;
    cloMenu->hide();
    cloRules->show();
}

void WidgetManager:: goToGridSaved(){
    this->WidgetActif=cloGrid;
    cloMenu->hide();
    cloGrid->show();
}

