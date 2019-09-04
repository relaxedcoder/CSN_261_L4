#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t.inputfromfile("L4_P1_input.csv");

    QPushButton * searchButton;
    searchButton = MainWindow::findChild<QPushButton *>("Search");
    connect(searchButton,SIGNAL(released()),this,SLOT(searchPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchPressed()
{
    QString word = ui->WordInput->toPlainText();
    string meaning = t.getmeaning(word.toStdString());
    ui->MeaningOutput->setText(QString::fromStdString(meaning));
}
