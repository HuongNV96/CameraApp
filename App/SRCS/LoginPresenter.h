#ifndef LOGINPRESENTER_H
#define LOGINPRESENTER_H

#include <QObject>
#include <QDebug>

class LoginPresenter : public QObject
{
    Q_OBJECT
public:
    explicit LoginPresenter(QObject *parent = nullptr);
    Q_INVOKABLE void login(QString user, QString password);
    Q_SIGNAL void loginedStatus(bool status);
    Q_SIGNAL void loggingStatus(bool status);
};

#endif // LOGINPRESENTER_H
