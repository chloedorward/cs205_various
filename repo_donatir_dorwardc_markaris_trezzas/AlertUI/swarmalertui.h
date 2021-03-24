#ifndef SWARMALERTUI_H
#define SWARMALERTUI_H

#include <QDialog>
#include <string>
#include "../UDPHandler/UDPMessageData.h"
#include "../UDPHandler/HBoard.h"
#include "../UDPHandler/HDate.h"
#include "../UDPHandler/HTime.h"

namespace Ui {
class SwarmAlertUI;
}

class SwarmAlertUI : public QDialog
{
    Q_OBJECT

public:
    explicit SwarmAlertUI(QWidget *parent = nullptr);
    ~SwarmAlertUI();

    void setHiveID(std::string _HiveID);
    void setTime(HTime ht);
    void setDate(HDate hd);
    void setNumBees(int _num_bees);

private slots:
    void on_CloseButton_clicked();

private:
    Ui::SwarmAlertUI *ui;
};

#endif // SWARMALERTUI_H
