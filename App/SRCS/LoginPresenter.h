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
    Q_SLOT void loginedStatus_(bool status) { emit loginedStatus(status); }
    Q_SLOT void loggingStatus_(bool status) { emit loggingStatus(status); }
    Q_SIGNAL void loginedStatus(bool status);
    Q_SIGNAL void loggingStatus(bool status);
private:
    void _login(QString user, QString password);
};

#endif // LOGINPRESENTER_H
