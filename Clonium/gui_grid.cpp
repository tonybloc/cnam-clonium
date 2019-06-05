#include "gui_grid.h"
#include <QPushButton>
#include <QMessageBox>

const int NB_ROWS = 10;
const int NB_COLUMNS = 10;

GUI_Grid::GUI_Grid(QWidget *parent)
{
    setFixedSize(500, 700);
    setStyleSheet("background-color: blue;");

    this->setParent(parent);
    m_layout = new QGridLayout;

    m_layout->setMargin(50);
    this->setLayout(m_layout);


    for (int i = 0; i < NB_ROWS; i++) {
        for (int j = 0; j < NB_COLUMNS; j++) {
            QPushButton *btn = new QPushButton;

            btn->setStyleSheet("border:0px; border-radius:5px; background-color:purple;");
            btn->setFixedSize(QSize(35,35));
            btn->setIconSize(QSize(33,33));

            btn->setObjectName(QString("btn%1%2").arg(i).arg(j));
            connect(btn, SIGNAL(clicked()), this, SLOT(test()));

            //add button
            m_layout->addWidget(btn,i,j);
            // set stretch
            m_layout->setRowStretch(i+2,2);
            m_layout->setColumnStretch(j+2,2);
            // space betwwen lines and columns
            m_layout->setVerticalSpacing(1);
            m_layout->setHorizontalSpacing(1);
            m_layout->setAlignment(Qt::AlignHCenter);
        }
    }
}

void GUI_Grid::test(){
    QPushButton* btnSender = qobject_cast<QPushButton*>(sender());
    btnSender->setIcon(QIcon(":/images/green_1.png"));


    //btnSender->setIcon(QIcon(":/images/green_2.png"));


}
