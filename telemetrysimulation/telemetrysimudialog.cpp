#include "telemetrysimudialog.h"
#include "ui_telemetrysimudialog.h"

telemetrysimuDialog::telemetrysimuDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::telemetrysimuDialog)
{
    ui->setupUi(this);
    mainTimer.setInterval(100); //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    connect(&mainTimer,&QTimer::timeout,this,&telemetrysimuDialog::onmainTimeLoop);
    mainTimer.start(); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void telemetrysimuDialog::onmainTimeLoop()// ///////////////////////////////////////////////////////////
{
    QString writeback = ui ->LatLon -> text();
    connect(this,&telemetrysimuDialog::toMotnEmu,dlg,&telsimmotionDialog::toSecWindow); //
    emit toMotnEmu(writeback); // ////////////////////////
}


telemetrysimuDialog::~telemetrysimuDialog()
{
    delete ui;
}


void telemetrysimuDialog::on_startMotion_clicked()
{
    dlg = new telsimmotionDialog(this); // ///////////////
    dlg->show(); // ////////////////////////////////
}
