#include "gui_grid.h"
#include <QMessageBox>

using namespace  std;

const int NB_ROWS = 10;
const int NB_COLUMNS = 10;

const string RED = ":/images/red_";
const string BLUE = ":/images/blue_";
const string GREY = ":/images/grey_";
const string GREEN = ":/images/green_";

GUI_Grid::GUI_Grid(QWidget *parent, unsigned int nbHumans, unsigned int nbAI)
{
    setFixedSize(500, 700);
    setStyleSheet("background-color: blue;");

    this->setParent(parent);
    m_layout = new QGridLayout;

    this->setLayout(m_layout);


    for (uint i = 0; i < NB_ROWS; i++) {
        for (uint j = 0; j < NB_COLUMNS; j++) {
            btn = new QPushButton;

            if (nbHumans+nbAI == 2){
                if (i == 1 && j == 1){
                    createFirstButton(i,j);
                }
                else if (i == NB_ROWS -2  && j == NB_COLUMNS -2){
                    createFirstButton(i,j);
                }
                else{
                    createGridButtons(i,j);
                }
            }

            if (nbHumans+nbAI == 3){
                if (i == 1 && j == 1){
                    createFirstButton(i,j);
                }
                else if (i == NB_ROWS -2  && j == NB_COLUMNS -2){
                    createFirstButton(i,j);
                }
                else if (i == 1 && j == NB_COLUMNS -2){
                    createFirstButton(i,j);
                }
                else{
                    createGridButtons(i,j);
                }
            }

            if (nbHumans+nbAI == 4){
                if (i == 1 && j == 1){
                    createFirstButton(i,j);
                }
                else if (i == NB_ROWS -2  && j == NB_COLUMNS -2){
                    createFirstButton(i,j);
                }
                else if (i == 1 && j == NB_COLUMNS -2){
                    createFirstButton(i,j);
                }
                else if (i == NB_ROWS -2 && j == 1){
                    createFirstButton(i,j);
                }
                else{
                    createGridButtons(i,j);
                }
            }
        }
    }

    btnSave = new QPushButton;
    btnSave->setIcon(QIcon(":/images/save.png"));
    btnSave->setFixedSize(QSize(35,35));
    btnSave->setIconSize(QSize(35,35));
    m_layout->addWidget(btnSave,NB_ROWS,1);

}

void GUI_Grid::onClickButtonGrid(){
    QPushButton* btnSender = qobject_cast<QPushButton*>(sender());

    QPixmap pix(":/images/green_1.png");
    QIcon ButtonIcon(pix);
    QMatrix m;
    m.rotate(10);
    pix = pix.transformed(m);
    btnSender->setIcon(ButtonIcon);
    btnSender->setIconSize(QSize(30,30));
}

void GUI_Grid::createFirstButton(uint i, uint j){
    btnPlayer = new QPushButton;
    btnPlayer->setIcon(QIcon(chooseColor(1, 3)));
    btnPlayer->setStyleSheet("border:0px; border-radius:5px; background-color:purple;");
    btnPlayer->setFixedSize(QSize(this->size().width()/NB_COLUMNS-5,this->size().width()/NB_COLUMNS-5));
    btnPlayer->setIconSize(QSize(this->size().width()/NB_COLUMNS-7,this->size().width()/NB_COLUMNS-7));
    btnPlayer->setObjectName(QString("btn%1%2").arg(i).arg(j));

    connect(btnPlayer, SIGNAL(clicked()), this, SLOT(onClickButtonGrid()));
    m_layout->addWidget(btnPlayer,i,j);
}

void GUI_Grid::createGridButtons(uint i, uint j){

    btn->setStyleSheet("border:0px; border-radius:5px; background-color:purple;");
    btn->setFixedSize(QSize(this->size().width()/NB_COLUMNS-5,this->size().width()/NB_COLUMNS-5));
    btn->setIconSize(QSize(this->size().width()/NB_COLUMNS-7,this->size().width()/NB_COLUMNS-7));
    btn->setObjectName(QString("btn%1%2").arg(i).arg(j));
    btn->setEnabled(false);
    connect(btn, SIGNAL(clicked()), this, SLOT(onClickButtonGrid()));

    //add button
    m_layout->addWidget(btn,i,j);

    // space betwwen lines and columns
    m_layout->setVerticalSpacing(3);
    m_layout->setHorizontalSpacing(3);
    m_layout->setAlignment(Qt::AlignHCenter);
}

QString GUI_Grid::chooseColor(uint id, uint niveau){
    string chemin;

    switch ( id ) {
    case 0:
      chemin = RED+to_string(niveau)+".png";
      break;
    case 1:
      chemin = BLUE+to_string(niveau)+".png";
      break;
    case 2:
      chemin = GREY+to_string(niveau)+".png";
      break;
    case 3:
      chemin = GREEN+to_string(niveau)+".png";
      break;
    default:
      chemin = GREEN+to_string(niveau)+".png";
      break;
    }

    return QString::fromStdString(chemin);
}
