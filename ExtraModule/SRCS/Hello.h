#ifndef HELLO_H
#define HELLO_H

#include <QObject>

class Hello : public QObject
{
    Q_OBJECT
public:
    explicit Hello(QObject *parent = nullptr);
    Q_PROPERTY(int test READ getTest);
private :
    int getTest() {
        return 10;
    }

};

#endif // HELLO_H
