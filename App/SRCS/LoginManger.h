#ifndef LOGINMANGER_H
#define LOGINMANGER_H

#include <QObject>
#include <QDebug>
#include "LoginHandler.h"
#include "SingletonTemplate.hpp"

class LoginManger : public QObject
{
    Q_OBJECT
public:
    explicit LoginManger(QObject *parent = nullptr);
    void login(QString user, QString password);
    Q_SIGNAL void loginedStatus(bool status);
    Q_SIGNAL void loggingStatus(bool status);
    QString getUser() { return mUser; }
    QString getPassword() { return mPassword; }
private :
    LoginHandler mHandler;
    QString mUser, mPassword;
};

#endif // LOGINMANGER_H
