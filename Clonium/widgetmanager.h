#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H
#include <QMainWindow>
#include "mainmenu.h"
#include "about.h"
#include "cloniummenu.h"
#include "gui_team.h"
#include "gui_individual.h"
#include "gui_grid.h"
#include "cloniumrules.h"

class WidgetManager : public QMainWindow
{
    Q_OBJECT
public:
    explicit WidgetManager(QWidget *parent = nullptr);

public slots:
    void RetourMenu();
    void goToClonium();
    void goToAbout();
    void goToCloniumParams();
    void goToTeams();
    void goToIndividual(uint nbHuman, uint nbIA);
    void goToGrid();
    void goToCloniumRules();
    void goToGridSaved();

private:
    QWidget* WidgetActif;
    MainMenu* menu;
    CloniumMenu* cloMenu;
    CloniumParameters* cloParams;
    About* about;
    GUI_Team* cloTeams;
    GUI_Individual* cloIndi;
    GUI_Grid* cloGrid;
    cloniumrules* cloRules;
};

#endif // WIDGETMANAGER_H
