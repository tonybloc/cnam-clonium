#ifndef GUI_GRID_H
#define GUI_GRID_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

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

    // grid button
    QPushButton *btn;

    // save button
    QPushButton *btnSave;
};

#endif // GUI_GRID_H
