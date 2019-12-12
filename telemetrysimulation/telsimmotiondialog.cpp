#include "telsimmotiondialog.h"
#include "ui_telsimmotiondialog.h"

telsimmotionDialog::telsimmotionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telsimmotionDialog)
{
    ui->setupUi(this);
    mainTimer.setInterval(450); //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    connect(&mainTimer,&QTimer::timeout,this,&telsimmotionDialog::onmainTimeLoop);
  //  mainTimer.start(); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void telsimmotionDialog::onmainTimeLoop()// ///////////////////////////////////////////////////////////
{
  //  ui -> LatLon -> setText("second loop is running");

}

void telsimmotionDialog::toSecWindow(QString latlonFromTelSim)
{
    ui -> LatLon -> setText(latlonFromTelSim);

}


telsimmotionDialog::~telsimmotionDialog()
{
    delete ui;
}
