#ifndef GUI_GRID_H
#define GUI_GRID_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
using namespace std;

#include "managergames.h"
#include "managergames.h"

class GUI_Grid : public QWidget
{
       Q_OBJECT

public:
    GUI_Grid(QWidget *parent = nullptr);

private slots:
    void onClickButtonGrid();
    void onClickSaveGrid();
    QString chooseColor(uint id, uint niveau);

    void Split(std::vector<QPushButton*> containers);
    void GetRowAndColumnFromQButtonName(const QPushButton* button, uint* row, uint* column);


    void BehaviorCloniumPlayer(CloniumPlayer* player);
    void BehaviorCloniumIA(CloniumIA* player);

    void UpdateImageSource(QPushButton* button);
    void UpdateImageSource(QString buttonName);

    CloniumPawn* GetPawnLinkedToQPushButton(const QPushButton* button);
    CellContainer* GetCellContainerLinkedToQPushButton(const QPushButton* button);

    bool IsEndGame();
    void Comportement_IA(Player* player);
private:



    //layout of the window
    QGridLayout *m_Gridlayout;
    QVBoxLayout* m_MainLayout;
    QHBoxLayout* m_BotLayout;
    QHBoxLayout* m_TopLayout;
    QLabel* m_labelInformation;
    QPushButton* m_btnPlayerIcon;
    QLabel* m_labelPlayerName;

    // grid button
    QPushButton *btn;

    //player button
    QPushButton *btnPlayer;

    // save button
    QPushButton *btnSave;

    // animation
    QPropertyAnimation *m_animator;
};

#endif // GUI_GRID_H
