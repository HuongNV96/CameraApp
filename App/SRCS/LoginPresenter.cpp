#include "LoginPresenter.h"
#include <chrono>
#include <thread>
#include "LoginManger.h"

using namespace std::chrono_literals;

LoginPresenter::LoginPresenter(QObject *parent)
    : QObject{parent}
{
    LoginManger & manager = SingletonTemplate<LoginManger>::getInstance();
    connect(&manager, &LoginManger::loginedStatus, this, &LoginPresenter::loginedStatus);
    connect(&manager, &LoginManger::loggingStatus, this, &LoginPresenter::loggingStatus);

    //fake int password
    _login("111", "1111");
}

void LoginPresenter::login(QString user, QString password) {
    _login(user, password);
}

void LoginPresenter::_login(QString user, QString password)
{
    LoginManger & manager = SingletonTemplate<LoginManger>::getInstance();
    manager.login(user, password);
}
