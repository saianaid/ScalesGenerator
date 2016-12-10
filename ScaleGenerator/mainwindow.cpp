#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "definitions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3->setText("");
    ScaleGenerator = new MusicCommons();
    //Add all the keys and modes at the begginning
    for(int key = 0; key < TOTAL_KEYS; key++){
        ui->comboBoxKey->addItem(Keys_text[key].c_str());
    }

    for(int mode = 0; mode < TOTAL_MODES; mode++){
        ui->comboBoxMode->addItem(Modes_text[mode].c_str());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ScaleGenerator->generateScaleByKey(ui->comboBoxMode->currentIndex(), ui->comboBoxKey->currentIndex());
    ui->label_3->setText(ScaleGenerator->getScaleText().c_str());
}
