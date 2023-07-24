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
        //For demo, in real we need connnect to API to login
        emit manager.loggingStatus(true);
        std::this_thread::sleep_for(1s);
        qDebug() << manager.getPassword() << " ffkf  " << manager.getUser();
        if (manager.getPassword() == "string" && manager.getUser() == "string") {
            emit manager.loginedStatus(true);
        } else {
            emit manager.loginedStatus(true);
        }
        emit manager.loggingStatus(false);
        break;
    }
    default:
        break;
    }
}
