#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include "HandlerTemplate.hpp"
#include "Defines.h"

class LoginHandler : public HandlerTemplate<Event> {
public:
    LoginHandler();
    void handle(std::unique_ptr<Event> & message) override;
};

#endif // LOGINHANDLER_H
