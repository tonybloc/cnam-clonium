#ifndef GUI_GRID_H
#define GUI_GRID_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPropertyAnimation>

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
    void UpdateImageSource(QPushButton* button);

    void Split(const QPushButton* button);
    void GetRowAndColumnFromQButtonName(const QPushButton* button, uint* row, uint* column);
    void onClickButton();
    CloniumPawn* GetPawnLinkedToQPushButton(const QPushButton* button);
    CellContainer* GetCellContainerLinkedToQPushButton(const QPushButton* button);

private:

    //layout of the window
    QGridLayout *m_layout;

    // grid button
    QPushButton *btn;

    //player button
    QPushButton *btnPlayer;

    // save button
    QPushButton *btnSave;

    CloniumPawn* pawn;

    // animation
    QPropertyAnimation *m_animator;
};

#endif // GUI_GRID_H
