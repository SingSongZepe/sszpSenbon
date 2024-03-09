#include "worker.h"

#include "object/sfunctor.h"

#include <QThread>

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

Worker::~Worker() {

}

void Worker::work_now(std::function<void()> func) {
    QThread* thread = new QThread;
    SFunctor* sfunc = new SFunctor(func);
    connect(thread, &QThread::started, sfunc, &SFunctor::excute_function);
    connect(sfunc, &SFunctor::finished, thread, &QThread::quit);
    connect(thread, &QThread::finished, sfunc, &SFunctor::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    sfunc->moveToThread(thread);
    thread->start();
}

void Worker::append_function(std::function<void()>* func) {
    this->funcs.append(func);
}

void Worker::run_all_functons() {
    QList<QThread*> threads;
    for (auto& func: this->funcs) {
       SFunctor* sfunc = new SFunctor(*func);
       QThread* thread = new QThread();
       QObject::connect(thread, &QThread::started, sfunc, &SFunctor::excute_function);
       QObject::connect(sfunc, &SFunctor::finished, thread, &QThread::quit);
       QObject::connect(thread, &QThread::finished, sfunc, &SFunctor::deleteLater);
       QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

       sfunc->moveToThread(thread);
       threads.append(thread);
    }

    for (auto& thread : threads) {
        thread->start();
    }
}

