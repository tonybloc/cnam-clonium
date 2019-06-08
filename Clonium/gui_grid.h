#ifndef GUI_GRID_H
#define GUI_GRID_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

using namespace std;

#include "managergames.h"
#include "managergames.h"

class GUI_Grid : public QWidget
{
       Q_OBJECT

public:
    GUI_Grid(QWidget *parent = nullptr, unsigned int nbHumans=0, unsigned int nbAI=0);

private slots:
    void onClickButtonGrid();
    void createFirstButton(uint i, uint j);
    void createGridButtons(uint i, uint j);
    QString chooseColor(uint id, uint niveau);


    void Split(const QPushButton* button);
    void GetRowAndColumnFromQButtonName(const QPushButton* button, uint* row, uint* column);
    void onClickButton();

private:

    //layout of the window
    QGridLayout *m_layout;

    // grid button
    QPushButton *btn;

    //player button
    QPushButton *btnPlayer;

    // save button
    QPushButton *btnSave;
};

#endif // GUI_GRID_H
