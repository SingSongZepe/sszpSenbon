#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QList>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

    void append_function(std::function<void()>* func);
    void run_all_functons();

    static void work_now(std::function<void()> func);

public:
    QList<std::function<void()>*> funcs;

signals:
};

#endif // WORKER_H
