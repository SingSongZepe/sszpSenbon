#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "singsongzepe.h"

#include <QPushButton>
// #include <QEvent>
// #include <QMouseEvent>
#include <QDebug>
#include <QList>
#include <object/searchhistory.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // append views to the main_views
        // main
    this->main_views.append(ui->wgt_main_search);
    this->main_views.append(ui->wgt_main_singlebookview);
    this->main_views.append(ui->wgt_main_history);
    this->main_views.append(ui->wgt_main_setting);
    this->main_views.append(ui->wgt_main_todo);
        // navi
    this->navi_views.append(ui->wgt_navi_search);
    this->navi_views.append(ui->wgt_navi_singlebookview);
    this->navi_views.append(ui->wgt_navi_history);
    this->navi_views.append(ui->wgt_navi_setting);
    this->navi_views.append(ui->wgt_navi_todo);
    this->current_view_idx = 0; // set as Search view, but it should not equal to 0 1 2 3 4

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

    // init cookiemanger
    this->lcm = new LocalCookieManger();

    // init databasemanager
    this->dbm_history_search = new DatabaseManger(SingSongZepe::DB_FILE_PATH_SEARCH_HISTORY, SingSongZepe::TABLE_SEARCH_HISTORY_NAME);
    // this->dbm_history_download = new DatabaseManger(SingSongZepe::DB_FILE_PATH_DOWNLOAD_HISTORY, SingSongZepe::TABLE_DOWNLOAD_HISTORY_NAME);

    MainWindow::initializa_python();

    // book_infos
    // this->show_books(); there be nullptr

    // lb_bar
        // lb_bar_search click
    ui->lb_bar_search->installEventFilter(this);
    ui->lb_bar_history->installEventFilter(this);
    ui->lb_bar_setting->installEventFilter(this);
    ui->lb_bar_todo->installEventFilter(this);

    // pb_search click
    QObject::connect(ui->pb_search, &QPushButton::clicked, this, &MainWindow::search_books_launch);

    // le_serach return
    QObject::connect(ui->le_search, &QLineEdit::returnPressed, this, &MainWindow::search_books_launch);

    // test
        // localcookiemanger
    // qDebug() << lcm->get_one_cookie().cookie;
    // return

        // search history
    // GeneralSearch general_search = GeneralSearch("general", "hello world");
    // SearchHistory search_hitory = SearchHistory(general_search);
    // qDebug() << (search_hitory.id);
    // this->dbm_history_search->insert_item(search_hitory);
    // SearchHistory sh = this->dbm_history_search->search_by_id<SearchHistory>(search_hitory.id);
    // qDebug() << sh.search_type;
    // qDebug() << sh.key_word;

    // GeneralSearch general_search1 = GeneralSearch("fulltext", "SingSongZepe");
    // SearchHistory search_hitory1 = SearchHistory(general_search1);
    // this->dbm_history_search->update_item(search_hitory1, sh.id);

    // SearchHistory sh1 = this->dbm_history_search->search_by_id<SearchHistory>(search_hitory.id);
    // qDebug() << sh1.search_type;
    // qDebug() << sh1.key_word;
    // this->dbm_history_search->delete_item_by_id(sh1.id);
}

// implement of function
void MainWindow::print_hello(bool checked) {
    Q_UNUSED(checked)
    qDebug() << "Hello World";
}

MainWindow::~MainWindow() {
    MainWindow::finalize_python();
    // release object
    if (book_infos != nullptr) // when user even does't click pb_search
        delete book_infos;

    if (book_full_info != nullptr) // when user does't click single book(after searching)
        delete book_full_info;

    if (wgt_book_items != nullptr)
        delete wgt_book_items;

    delete sb_sa_books; // new when mainwindow init

    if (single_book_info != nullptr)
        delete single_book_info;

    delete sb_sa_singlebookview; // new when mainwindow init

    // cookiemanger
    delete lcm;

    // databasemanger
    delete dbm_history_search;
    delete dbm_history_search;

    delete ui;
}


