#include <QApplication>
#include "widgetmanager.h"

int main(int argc, char *argv[])
{
    ManagerGames& Game = ManagerGames::Instance();
    QApplication app(argc, argv);

    WidgetManager mng;
    mng.show();

    return app.exec();
}
