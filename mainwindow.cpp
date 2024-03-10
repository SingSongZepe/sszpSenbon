#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "singsongzepe.h"

#include <QPushButton>
// #include <QEvent>
// #include <QMouseEvent>
#include <QDebug>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // append views to the main_views
    this->main_views.append(ui->wgt_main_search);
    this->main_views.append(ui->wgt_main_singlebookview);
    this->current_view_idx = 0;

    MainWindow::toggle_view(SingSongZepe::transfrom_idx2viewkind(this->current_view_idx));

    // init wgt_books
    ui->wgt_books->setHidden(true);

    // init sa_books
    this->sb_sa_books = new QScrollBar(ui->sa_books);
    this->sb_sa_books->setStyleSheet(SingSongZepe::STYLE_SCROLLBAR_SLIM_TRANSPARENT);
    ui->sa_books->setVerticalScrollBar(this->sb_sa_books);

    // init sa_singlebookview
    this->sb_sa_singlebookview = new QScrollBar(ui->sa_singlebookview);
    this->sb_sa_singlebookview->setStyleSheet(SingSongZepe::STYLE_SCROLLBAR_SLIM_TRANSPARENT);
    ui->sa_singlebookview->setVerticalScrollBar(this->sb_sa_singlebookview);

    MainWindow::initializa_python();

    // book_infos
    // this->show_books(); there be nullptr

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
    MainWindow::finalize_python();
    delete ui;
    // release object
    delete book_infos;
    delete book_full_info;
    delete wgt_book_items;
    delete sb_sa_books;
    delete sb_sa_singlebookview;
}
