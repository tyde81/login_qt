#include "login.h"
#include "ui_login.h"
#include <Qt>
#include <QMessageBox>
#include <QRegularExpression>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{
    QMessageBox *messagebox;


    QString email = ui->lineEdit_2->text();
    QString password = ui->lineEdit->text();

    const QRegularExpression pattern("^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$");
    const QRegularExpressionMatch match = pattern.match(email);

    if(!match.hasMatch()) {
        messagebox->critical(this, "Error", "Invalid email.");

        return;
    }

    if(email.isEmpty() || password.isEmpty()) {
        messagebox->critical(this, "Error", "All fields need to be filled.");

        return;
    }

    messagebox->information(this, "Success", "Successfully authenticated.");
}
