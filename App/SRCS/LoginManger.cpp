#include "LoginManger.h"
#include "Defines.h"
LoginManger::LoginManger(QObject *parent)
    : QObject{parent}
{

}

void LoginManger::login(QString user, QString password) {
    mUser = user;
    mPassword = password;

    Event event;
    event.type  = LOGIN_MSG;
    mHandler.sendMessage(event);
}
