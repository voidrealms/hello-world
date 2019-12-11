#ifndef MAINWINDOWDIALOG_H
#define MAINWINDOWDIALOG_H

#include <QDialog>
#include <QTimer> // /////////////////////////////////////
#include "secondwindowdialog.h" // //////////////////////

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowDialog; }
QT_END_NAMESPACE

class MainWindowDialog : public QDialog
{
    Q_OBJECT

public:
    MainWindowDialog(QWidget *parent = nullptr);
    ~MainWindowDialog();

private:
    Ui::MainWindowDialog *ui;
    QTimer mainTimer; // /////////////////////////////////
    SecondWindowDialog *dlg; // //////////////////////


protected slots:

        void onmainTimeLoop(); // ///////////////////////
private slots:
        void on_openSecondWindow_clicked(); // ////////////
  //      void on_sendToSecondWindow_clicked(); // ///////////////

  //      void on_leSendToSecondWindow_textChanged(const QString &arg1);

        void on_startMotion_clicked();

        void on_stopMotion_clicked();

        void on_imperialButton_clicked();

        void on_metricButton_clicked();

signals:
    void toSecWindow(QString msgToSecWindow, double hdgToSecWindow, double speedToSecWindow, double altToSecWindow, QString impmetToSecWindow,
    double vspdToSecWindow); // //////////////////

};
#endif // MAINWINDOWDIALOG_H
