#ifndef ROBALERTUI_H
#define ROBALERTUI_H

#include <QDialog>
#include <string>
#include "../UDPHandler/UDPMessageData.h"
#include "../UDPHandler/HBoard.h"
#include "../UDPHandler/HDate.h"
#include "../UDPHandler/HTime.h"

namespace Ui {
class RobAlertUI;
}

class RobAlertUI : public QDialog
{
    Q_OBJECT

public:
    explicit RobAlertUI(QWidget *parent = nullptr);
    ~RobAlertUI();

    void setHiveID(std::string _HiveID);
    void setTime(HTime ht);
    void setDate(HDate hd);
    void setNumBees(int _num_bees);

private slots:
    void on_CloseButton_clicked();

private:
    Ui::RobAlertUI *ui;
};

#endif // ROBALERTUI_H
