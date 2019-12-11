#include "mainwindowdialog.h"
#include "ui_mainwindowdialog.h"

MainWindowDialog::MainWindowDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindowDialog)
{
    ui->setupUi(this);

    mainTimer.setInterval(100); //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    connect(&mainTimer,&QTimer::timeout,this,&MainWindowDialog::onmainTimeLoop);
  //  mainTimer.start(); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}


void MainWindowDialog::onmainTimeLoop()// ///////////////////////////////////////////////////////////
{
    QStringList lalo = (ui -> LatLon -> text()).split(",");
    QString flat = lalo[0];
    QString flon = lalo[1];
    double dflat = flat.toDouble() + .00000034;
    double dflon = flon.toDouble() + .00000034;
    QString dfa = QString::number(dflat, 'f', 8);
    QString dfo = QString::number(dflon, 'f', 8);
    QString writeback = dfa + "," + dfo;
    ui ->LatLon ->setText(writeback);
    double hdgtosecwin = ui -> dsHeading -> value();
    double speedtosecwin = ui ->dsSpeed -> value();
    double alttosecwin = ui -> dsAlt -> value();
    QString impmettosecwin = ui -> mphLabel -> text();
    double vspdtosecwin = ui ->mSecond -> value();


        QString sndtoSecondWindow = writeback; // /////////////
        connect(this,&MainWindowDialog::toSecWindow,dlg,&SecondWindowDialog::toSecWindow); // ///
        emit toSecWindow(sndtoSecondWindow, hdgtosecwin, speedtosecwin,alttosecwin, impmettosecwin, vspdtosecwin); // ////////////////////////

}
MainWindowDialog::~MainWindowDialog()
{
    delete ui;
}


void MainWindowDialog::on_openSecondWindow_clicked() // ///////////////
{
    dlg = new SecondWindowDialog(this); // ///////////////
    dlg->show(); // ////////////////////////////////
}

void MainWindowDialog::on_startMotion_clicked()
{
    mainTimer.start();
}

void MainWindowDialog::on_stopMotion_clicked()
{
    mainTimer.stop();
}

void MainWindowDialog::on_imperialButton_clicked()
{
    ui -> mphLabel -> setText("MPH");
    ui -> altLabel -> setText("FEET");
    ui -> fsLabel -> setText("F/S");
}

void MainWindowDialog::on_metricButton_clicked()
{
    ui -> mphLabel -> setText("KPH");
    ui -> altLabel -> setText("METERS");
    ui -> fsLabel -> setText("M/S");
}
