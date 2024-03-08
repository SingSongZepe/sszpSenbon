#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QLabel>
// #include <QEvent>
// #include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // lb_bar
        // lb_bar_search click
    ui->lb_bar_search->installEventFilter(this);
    ui->lb_bar_download->installEventFilter(this);
    ui->lb_bar_setting->installEventFilter(this);
    ui->lb_bar_todo->installEventFilter(this);

    // pb_search click
    QObject::connect(ui->pb_search, &QPushButton::clicked, this, &MainWindow::search_books_launch);

    // le_serach return
    QObject::connect(ui->le_search, &QLineEdit::returnPressed, this, &MainWindow::search_books_launch);
}

// implement of function
void MainWindow::print_hello(bool checked) {
    Q_UNUSED(checked)
    qDebug() << "Hello World";
}

MainWindow::~MainWindow()
{
    delete ui;
}
