#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H
#include <QMainWindow>
#include "mainmenu.h"
#include "about.h"
#include "cloniummenu.h"
#include "gui_team.h"
#include "gui_individual.h"
#include "gui_grid.h"

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
    void goToIndividual();
    void goToGrid();

private:
    QWidget* WidgetActif;
    MainMenu* menu;
    CloniumMenu* cloMenu;
    CloniumParameters* cloParams;
    About* about;
    GUI_Team* cloTeams;
    GUI_Individual* cloIndi;
    GUI_Grid* cloGrid;
};

#endif // WIDGETMANAGER_H
