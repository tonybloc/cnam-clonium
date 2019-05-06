#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H
#include <QMainWindow>
#include "mainmenu.h"
#include "about.h"
#include "cloniummenu.h"

class WidgetManager : public QMainWindow
{
    Q_OBJECT
public:
    explicit WidgetManager(QWidget *parent = nullptr);

signals:

public slots:
    void RetourMenu();
    void goToClonium();
    void goToAbout();
    void goToCloniumParams();

private:
    QWidget* WidgetActif;
    MainMenu* menu;
    CloniumMenu* cloMenu;
    CloniumParameters* cloParams;
    About* about;
};

#endif // WIDGETMANAGER_H
