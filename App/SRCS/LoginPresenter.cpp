#include "LoginPresenter.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

LoginPresenter::LoginPresenter(QObject *parent)
    : QObject{parent}
{
    std::thread loginThread([this]() {
        login("111", "1111");
    });
    loginThread.detach();
}

void LoginPresenter::login(QString user, QString password)
{
    emit loggingStatus(true);
    std::this_thread::sleep_for(10s);
    qDebug() << "login ";
    emit loginedStatus(true);
    emit loggingStatus(false);
}
