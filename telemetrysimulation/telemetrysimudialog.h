#ifndef TELEMETRYSIMUDIALOG_H
#define TELEMETRYSIMUDIALOG_H

#include <QDialog>
#include <QTimer> // /////////////////////////////////////
#include "telsimmotiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class telemetrysimuDialog; }
QT_END_NAMESPACE

class telemetrysimuDialog : public QDialog
{
    Q_OBJECT

public:
    telemetrysimuDialog(QWidget *parent = nullptr);
    ~telemetrysimuDialog();

private:
    Ui::telemetrysimuDialog *ui;
    QTimer mainTimer; // /////////////////////////////////
    telsimmotionDialog *dlg;

protected slots:
        void onmainTimeLoop(); // ///////////////////////



private slots:
        void on_startMotion_clicked();

signals:
    void toMotnEmu(QString msgToMotionWindow); // //////////////////

};
#endif // TELEMETRYSIMUDIALOG_H
