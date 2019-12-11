#ifndef SECONDWINDOWDIALOG_H
#define SECONDWINDOWDIALOG_H

#include <QDialog>
#include <QTimer> // /////////////////////////////////////

namespace Ui {
class SecondWindowDialog;
}

class SecondWindowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindowDialog(QWidget *parent = nullptr);
    ~SecondWindowDialog();

private:
    Ui::SecondWindowDialog *ui;
    QTimer secondWindowTimer; // /////////////////////////////////

protected slots:

        void onsecondWindowTimeLoop(); // ///////////////////////

public slots:
    void toSecWindow(QString latlonToSecWindow, double hdgToSecWindow, double speedToSecWindow, double altToSecWindow, QString impmetToSecWindow,
                     double vspdToSecWindow); // /////////////////////

private slots:


private:
    Ui::SecondWindowDialog *Ui;
};

#endif // SECONDWINDOWDIALOG_H
