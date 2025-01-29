#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GLPanel = new QOpenGLPanel(this);
    ui->grid->addWidget(GLPanel,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GLPanel->translate(float(ui->tx->value()), float(ui->ty->value()), float(ui->tz->value()));
}


void MainWindow::on_pushButton_2_clicked()
{
    GLPanel->rotate(float(ui->rdegree->value()), float(ui->rx->value()), float(ui->ry->value()), float(ui->rz->value()));
}


void MainWindow::on_pushButton_3_clicked()
{
    GLPanel->scale(float(ui->sx->value()), float(ui->sy->value()), float(ui->sz->value()));
}


void MainWindow::on_pushButton_4_clicked()
{
    GLPanel->lookAt(float(ui->ex->value()), float(ui->ey->value()), float(ui->ez->value()),
                    float(ui->cx->value()), float(ui->cy->value()), float(ui->cz->value()),
                    float(ui->ux->value()), float(ui->uy->value()), float(ui->uz->value()));
}


void MainWindow::on_pushButton_5_clicked()
{
    float ratio =float(GLPanel->width())/float(GLPanel->height());
    GLPanel->perspective(float(ui->verAngle->value()), ratio, float(ui->nearp->value()), float(ui->farp->value()));
}

