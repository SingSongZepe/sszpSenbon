#include "helloworld.h"
#include "ui_helloworld.h"

HelloWorld::HelloWorld(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelloWorld)
{
    ui->setupUi(this);
}

HelloWorld::~HelloWorld()
{
    delete ui;
}
