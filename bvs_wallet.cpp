#include "bvs_wallet.h"
#include "ui_bvs_wallet.h"
#include "ausfuehrendialog.h"
#include "projekteauswahl.h"
#include "settingsdialog.h"
#include <QDebug>
#include <QCloseEvent>
#include "Classes/Controller/nodecontroller.h"


BVS_Wallet::BVS_Wallet(QStringList args, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::BVS_Wallet)
{
    ui->setupUi(this);

//    QString  arg[Args.length()];

    for(int i = 0; i < args.length(); i++) {
        if (args.at(i) == "-debug") {
            qDebug() << "\nArgs:" << args.length() << "";
            for(int j = 0; j < args.length(); j++) {
                qDebug() << "args[" << j << "] = " << args.at(j) << "";
            }
        }
    }
}

/**
 * @brief BVS_Wallet::~BVS_Wallet -closes the bvs_gui mainwindow
 *
 */
BVS_Wallet::~BVS_Wallet()
{
//    qDebug() << "Anwendung beenden... (2)";
    closeEvent();
    delete ui;
}

/**
 * @brief BVS_Wallet::on_action_Ausf_hren_triggered
 */
void BVS_Wallet::on_action_Ausf_hren_triggered()
{
  AusfuehrenDialog *a = new AusfuehrenDialog;
  a->show();
}

/**
 * @brief BVS_Wallet::on_actionWahl_ffnen_triggered
 */
void BVS_Wallet::on_actionWahl_ffnen_triggered()
{
    ProjekteAuswahl *p = new ProjekteAuswahl;
    p->show();

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        if (project != "")
        {
            ui->label->setText(project);
        }
    }
}

/**
 * @brief BVS_Wallet::on_action_Beenden_triggered
 */
void BVS_Wallet::on_action_Beenden_triggered()
{
    closeEvent();
    exit(0);
}

/**
 * @brief BVS_Wallet::on_actionAuswaehlen_triggered
 */
void BVS_Wallet::on_actionAuswaehlen_triggered()
{
    ProjekteAuswahl *p = new ProjekteAuswahl;
    p->show();

    ProjectRepository *repository;

    if (p->exec()==QDialog::Accepted) {
        QString project = p->getProject();
        ui->label->setText(project);
        ui->listWidget->addItems(repository->findAllItems(project));    }
}

/**
 * @brief BVS_Wallet::on_actionEinstellungen_triggered
 */
void BVS_Wallet::on_actionEinstellungen_triggered()
{
    SettingsDialog *settings = new SettingsDialog;
    settings->show();
}

/**
 * @brief BVS_Wallet::closeEvent
 */
void BVS_Wallet::closeEvent()
{
//    qDebug() << "Anwendung beenden - Blockchain: ";
    NodeController nc;
    int i = nc.stopDaemon();
    qDebug() << "Anwendung beenden Status:" << i;
}
