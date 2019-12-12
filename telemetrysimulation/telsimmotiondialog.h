#ifndef TELSIMMOTIONDIALOG_H
#define TELSIMMOTIONDIALOG_H

#include <QDialog>
#include <QTimer> // /////////////////////////////////////

namespace Ui {
class telsimmotionDialog;
}

class telsimmotionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit telsimmotionDialog(QWidget *parent = nullptr);
    ~telsimmotionDialog();

private:
    Ui::telsimmotionDialog *ui;
    QTimer mainTimer; // /////////////////////////////////

protected slots:
        void onmainTimeLoop(); // ///////////////////////

public slots:
    void toSecWindow(QString latlonFromTelSim); // /////////////////////

};

#endif // TELSIMMOTIONDIALOG_H
