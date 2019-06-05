#ifndef GUI_GRID_H
#define GUI_GRID_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>

class GUI_Grid : public QWidget
{
       Q_OBJECT

public:
    GUI_Grid(QWidget *parent = nullptr);

private slots:
    void test();

private:

    //layout of the window
    QGridLayout *m_layout;
};

#endif // GUI_GRID_H
