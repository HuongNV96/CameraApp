#ifndef LOGINPRESENTER_H
#define LOGINPRESENTER_H

#include <QObject>
#include <QDebug>

class LoginPresenter : public QObject
{
    Q_OBJECT
public:
    LoginPresenter() = default;
    Q_INVOKABLE bool login(QString user, QString password);
};

#endif // LOGINPRESENTER_H
