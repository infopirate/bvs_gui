#ifndef BVS_WALLET_H
#define BVS_WALLET_H


#include <QtCore/QtGlobal>

#include <QMainWindow>
#include "ausfuehrendialog.h"
#include "Classes/Domain/projectRepository.h"

namespace Ui {
  class BVS_Wallet;
}

class AusfuehrenDialog;


class BVS_Wallet : public QMainWindow
{
  Q_OBJECT

public:
  explicit BVS_Wallet(QWidget *parent = 0);
  ~BVS_Wallet();

private slots:
  void on_action_Ausf_hren_triggered();
//  QDialog ausfuehrendialog; //<--------- Pointer auf QDialog
  void on_actionWahl_ffnen_triggered();

  void on_action_Beenden_triggered();

  void on_actionAuswaehlen_triggered();

  void on_actionEinstellungen_triggered();

private:
  Ui::BVS_Wallet *ui;
  QDialog * ausfuehrendialog; //<--------- Pointer auf QDialog

};

#endif // BVS_WALLET_H
