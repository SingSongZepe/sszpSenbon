#ifndef SFUNCTOR_H
#define SFUNCTOR_H

#include <QObject>

class SFunctor : public QObject
{
    Q_OBJECT
public:
    explicit SFunctor(std::function<void()> func, QObject *parent = nullptr);

    std::function<void()> func;

public slots:
    void excute_function();

signals:
    void finished();
};

#endif // SFUNCTOR_H
