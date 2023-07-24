#ifndef REPEATERMANAGER_HPP
#define REPEATERMANAGER_HPP

#include "StreamRepeater.hpp"
#include "SingletonTemplate.hpp"
#include <QList>
#include <QObject>

class RepeaterManager : public QObject
{
    Q_OBJECT
public:
    RepeaterManager();
    void echo() {}
private :
    QList<std::shared_ptr<StreamRepeater>> streams;
};

#endif // REPEATERMANAGER_HPP
