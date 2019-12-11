#include "secondwindowdialog.h"
#include "ui_secondwindowdialog.h"

SecondWindowDialog::SecondWindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindowDialog)
{
    ui->setupUi(this);

    secondWindowTimer.setInterval(250); ///////////////////////////////////////////////////////////////////////////
    connect(&secondWindowTimer,&QTimer::timeout,this,&SecondWindowDialog::onsecondWindowTimeLoop);
    secondWindowTimer.start(); ////////////////////////////////////////////////////onsecondWindowTimeLoop///////////////////
}

void SecondWindowDialog::onsecondWindowTimeLoop()// ///////////////////////////////////////////////////////////
{
   // ui -> receivedFromMainWindow -> setText("sent from loop");
}

void SecondWindowDialog::toSecWindow(QString latlonToSecWindow, double hdgToSecWindow, double speedToSecWindow, double altToSecWindow, QString impmetToSecWindow,
                                     double vspdToSecWindow)
{
    ui -> receivedFromMainWindow -> setText(latlonToSecWindow);
    ui -> dsHeading -> setValue(hdgToSecWindow);
    ui -> dsSpeed -> setValue(speedToSecWindow);
    ui -> dsAlt -> setValue(altToSecWindow);
    ui -> mphLabel -> setText(impmetToSecWindow);
    ui -> dsFs -> setValue(vspdToSecWindow);

    if(ui -> mphLabel -> text() == "MPH")
       { ui -> altLabel -> setText("FEET");
        ui -> fsLabel -> setText("F/S");
    }
        else
    {
        ui -> altLabel -> setText("METERS");
        ui -> fsLabel -> setText("M/S");
    }
}


SecondWindowDialog::~SecondWindowDialog()
{
    delete ui;
}

