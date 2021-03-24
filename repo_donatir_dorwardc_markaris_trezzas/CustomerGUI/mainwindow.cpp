#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dbtool = new DBTool("beesknees");
    users = new UserTable(dbtool, "users");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete users;
    delete dbtool;
    delete currentUser;
    delete qtwi;
    delete ui;
}

void MainWindow::on_s0_pb_ForgotPassword_clicked()
{
    // changes to s_forgotPassword
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_s2_pb_reset_clicked()
{
    // save user input in QStrings
    QString username = ui->s2_le_username->text();
    QString password = ui->s2_le_newPassword->text();
    QString conf_password = ui->s2_le_confPassword->text();
    // ADD FUNCTIONALITY
    // check if the username exists in the database
    if(username.compare("bees") != 0)
    {
        ui->s2_l_status->setText("Invalid username");
    }
    // check if new passwords match
    else if(password.compare(conf_password) != 0)
    {
        ui->s2_l_status->setText("Passwords do not match");
    }
    // if all good to reset username's password
    else
    {
        // this is where we would access the database
        // clear user input fields
        ui->s2_le_username->clear();
        ui->s2_le_newPassword->clear();
        ui->s2_le_confPassword->clear();
        // changes to s_login
        ui->stackedWidget->setCurrentIndex(0);
        ui->s0_l_status->setText("Currently not connected to a database, cannot change password. Please login with bees knees");
    }
}

void MainWindow::on_s0_pb_Login_clicked()
{
    // save user input in QStrings
    std::string username = ui->s0_le_username->text().toStdString();
    std::string password = ui->s0_le_password->text().toStdString();
    // ADD FUNCTIONALITY
    // this is where we'd check the database for login info
    if(users->check_credentials(username, password))
    {
        currentUser = users->get_user(username);
        // clear user input fields
        ui->s0_le_password->clear();
        ui->s0_le_username->clear();
        ui->s0_l_status->clear();
        // changes to s_homeScreen
        ui->stackedWidget->setCurrentIndex(3);
        QString message = QString::fromStdString("Welcome, " + currentUser->getFirstName() + "!");
        ui->s3_l_status->setText(message); // this would be adjusted based on the user name
    }
    else if(username.compare("bees") == 0) // if incorrect password for the username (username could still be wrong)
    {
        ui->s0_l_status->setText("Incorrect username or password");
    }
    else // if username does not exist in database
    {
        ui->s0_l_status->setText("Invalid username");
    }
}

void MainWindow::on_s0_pb_NewUser_clicked()
{
    // clear user input fields
    ui->s0_le_password->clear();
    ui->s0_le_username->clear();
    // change to s_newUser
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_s1_pb_CreateUser_clicked()
{
    // save user input in QStrings
    std::string username = ui->s1_le_username->text().toStdString();
    std::string password = ui->s1_le_password->text().toStdString();
    std::string conf_password = ui->s1_le_confirmPassword->text().toStdString();
    std::string first_name = ui->s1_le_firstName->text().toStdString();
    std::string last_name = ui->s1_le_lastName->text().toStdString();
    std::string email = ui->s1_le_email->text().toStdString();

    // ADD FUNCTIONALITY
    // this is where we'd compare to the database
    // if username already taken
    if(password.compare(conf_password) != 0)
    {
        ui->s1_l_status->setText("Passwords do not match!");
    }
    // this is where we'd add the username password combo to the database
    else
    {
        //MAKE SURE USERNAME DOESN'T ALREADY EXIST
        users->add_row(email, first_name, last_name, username, password);

        //MAKES AND POPULATES A UDP MESSAGE DATABASE W/ USERNAME AS NAME
        hiveDB = new MessageTable(dbtool, username);
        hiveDB->populate("example.txt");

        // clear user input fields
        ui->s1_le_password->clear();
        ui->s1_le_confirmPassword->clear();
        ui->s1_le_username->clear();
        ui->s1_le_email->clear();
        ui->s1_l_firstName->clear();
        ui->s1_l_lastName->clear();
        // change to s_login
        ui->stackedWidget->setCurrentIndex(0);
        ui->s0_l_status->setText("User added successfully!");
    }
}

void MainWindow::on_s3_pb_viewHive_clicked()
{
    // change to s_findHive
    ui->stackedWidget->setCurrentIndex(5);
    // ADD FUNCTIONALITY
    ui->s5_l_currentHiveStatus->setText("not connected to data");

    // trying to test a way to display hive ID's
    // having trouble getting this working
    qtwi = new QTableWidgetItem(1);
    qtwi->setText("hello??");
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->setItem(0, 0, qtwi);
}

void MainWindow::on_s3_pb_addHive_clicked()
{
    // change to s_addHive
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_s3_pb_logout_clicked()
{
    // change to s_login
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_s5_pb_home_clicked()
{
    // change to s_homeScreen
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_s4_pb_add_clicked()
{
    // ADD FUNCTIONALITY
    // save user input as QString and int
    int HiveID = ui->s4_le_hiveID->text().toInt();
    QString location = ui->s4_le_hiveLocation->text();
    // we'd need to actually add to the database
    // clear user input fields
    ui->s4_le_hiveID->clear();
    ui->s4_le_hiveLocation->clear();
    // change to s_homeScreen
    ui->stackedWidget->setCurrentIndex(3);
    // display status of adding hive to database
    QString added = "Hive added. ID: ";
    added += QString::number(HiveID);
    added += " , Location: ";
    added += location;
    ui->s3_l_status->setText(added);
}

void MainWindow::on_s4_pb_cancel_clicked()
{
    // clear user input fields
    ui->s4_le_hiveID->clear();
    ui->s4_le_hiveLocation->clear();
    // change to s_homeScreen
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tableWidget_cellActivated(int row, int column)
{
    // trying here. failing. it's not displaying cells in the first place
    QString activated = "Row: ";
    activated += QString::number(row);
    activated += " Column: ";
    activated += QString::number(column);
    ui->stackedWidget->setCurrentIndex(3);
    ui->s3_l_status->setText(activated);
    // ultimately, this would select the appropriate hive to be used on s_hiveScreen
}

void MainWindow::on_s5_pb_selectHive_clicked()
{
    // change to s_hiveScreen
    ui->stackedWidget->setCurrentIndex(6);
    // ADD FUNCTIONALITY
    // this would display the current hive connected
    ui->s6_l_status->setText("no data connection, no hives");
}

void MainWindow::on_s7_pb_submitChanges_clicked()
{
    // ADD FUNCTIONALITY
    // would need to actually submit changes to the database
    // save user input as QString
    QString updatedLocation = ui->s7_le_updateLocation->text();
    ui->s7_le_updateLocation->clear();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_s8_pb_back_clicked()
{
    // change to s_hiveScreen
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_s6_pb_viewData_clicked()
{
    // change to s_hiveData
    ui->stackedWidget->setCurrentIndex(8);
    // need to add beechimes(nullptr, hiveID) here
    // unsure what to do...
}

void MainWindow::on_s6_pb_editHive_clicked()
{
    // change to s_editHive
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_s6_pb_back_clicked()
{
    // change to s_findHive
    ui->stackedWidget->setCurrentIndex(5);
}
