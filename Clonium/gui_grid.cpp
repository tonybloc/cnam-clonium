#include "gui_grid.h"

#include <QMessageBox>

const int NB_ROWS = 10;
const int NB_COLUMNS = 10;

GUI_Grid::GUI_Grid(QWidget *parent)
{
    setFixedSize(500, 700);
    setStyleSheet("background-color: blue;");

    this->setParent(parent);
    m_layout = new QGridLayout;

    //m_layout->setMargin(50);
    this->setLayout(m_layout);


    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLUMNS; j++) {
            btn = new QPushButton;

            btn->setStyleSheet("border:0px; border-radius:5px; background-color:purple;");
            btn->setFixedSize(QSize(this->size().width()/NB_COLUMNS-5,this->size().width()/NB_COLUMNS-5));
            btn->setIconSize(QSize(this->size().width()/NB_COLUMNS-7,this->size().width()/NB_COLUMNS-7));

            btn->setObjectName(QString("btn%1%2").arg(i).arg(j));
            connect(btn, SIGNAL(clicked()), this, SLOT(test()));

            //add button
            m_layout->addWidget(btn,i,j);
            // set stretch
            //m_layout->setRowStretch(i+1,1);
            //m_layout->setColumnStretch(j+1,1);
            // space betwwen lines and columns
            m_layout->setVerticalSpacing(3);
            m_layout->setHorizontalSpacing(3);
            m_layout->setAlignment(Qt::AlignHCenter);
        }
    }

    btnSave = new QPushButton;
    btnSave->setIcon(QIcon(":/images/save.png"));
    btnSave->setFixedSize(QSize(35,35));
    btnSave->setIconSize(QSize(35,35));
    m_layout->addWidget(btnSave,NB_ROWS,1);

}

void GUI_Grid::test(){
    QPushButton* btnSender = qobject_cast<QPushButton*>(sender());
    btnSender->setIcon(QIcon(":/images/green_1.png"));


    //btnSender->setIcon(QIcon(":/images/green_2.png"));


}
