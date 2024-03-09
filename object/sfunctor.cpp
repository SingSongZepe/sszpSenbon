#include "sfunctor.h"

SFunctor::SFunctor(std::function<void()> func, QObject *parent)
    : QObject{parent}
    , func(func)
{

}

void SFunctor::excute_function() {
    func();
    emit finished();
}
