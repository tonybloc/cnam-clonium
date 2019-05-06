#include <QApplication>
#include "widgetmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    WidgetManager mng;
    mng.show();

    return app.exec();
}
