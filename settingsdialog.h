#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H


#include <QtWidgets/QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
