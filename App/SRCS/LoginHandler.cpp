#include "LoginHandler.h"
#include "LoginManger.h"
#include "SingletonTemplate.hpp"

LoginHandler::LoginHandler()
{

}

void LoginHandler::handle(std::unique_ptr<Event> & message) {
    switch (message->type) {
    case LOGIN_MSG:
    {
        LoginManger & manager = SingletonTemplate<LoginManger>::getInstance();

        emit manager.loggingStatus(true);
        std::this_thread::sleep_for(10s);
        qDebug() << "login " << manager.getPassword() << "  " << manager.getUser();
        emit manager.loginedStatus(false);
        emit manager.loggingStatus(false);
        break;
    }
    default:
        break;
    }
}
