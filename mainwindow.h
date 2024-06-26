#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "search.h"
#include "object/book_info.h"
#include "object/bookfullinfo.h"
// #include "singlebookinfo.h"
// #include "worker.h"
#include "singsongzepe.h"
#include "sslog.h"
#include "cookiemanger/localcookiemanger.h"
#include "databasemanger/databasemanger.h"
#include "object/searchhistory.h"
#include "object/downloadhistory.h"
#include "wgt_manger/searchhistoryviewmanger.h"
#include "wgt_manger/downloadhistoryviewmanger.h"
#include "download_manger/downloadmanger.h"


#include <QMainWindow>
#include <QMouseEvent>
#include <QScrollBar>
#include <QLabel>
#include <QThread>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void print_hello(bool checked);

    // sszpSenbon toggle view
    void toggle_view(SingSongZepe::ToggleViewKind tvk);
    void toggle_view_history(SingSongZepe::ToggleViewHistoryKind tvhk);

    // sszpSenbon for searching
    void search_books_launch();
    void search_singlebook_launch(const QString& href);

    // api
    void search_books(const GeneralSearch* search); // general_search or fulltext_search
    bool show_books();

    void search_singlebook(const SingleBookSearch* search);
    bool show_singlebook();

    void load_search_history();
    void load_download_history();

    // utils
    QString make_url(const GeneralSearch* search);
    QList<BookInfo> json_str2book_infos(const QString* json_str);
    BookFullInfo json_str2book_full_info(const QString* json_str);
    bool initializa_python();
    bool finalize_python();
    static QByteArray request_url(const QString& url);
    static QByteArray request_url_with_cookie(const QString& url, const QString& cookie);
    static QByteArray request_url_with_cookie_no_timeout(const QString& url, const QString& cookie);
    static QPixmap load_picture(const QString& url);
    static bool set_label_pixmap(QLabel* lb, const QPixmap& pixmap);
    const BookInfo* get_bookinfo_of_pos(const QPoint& pos);
    // download_book function will for
    // static bool download_book(const QString& download_url, Cookie& cookie);

public:
    bool eventFilter(QObject* obj, QEvent* event);

public:
    // for getting some member var
    QWidget* get_ptr_wgt_search_history() {
        return this->wgt_search_history;
    }
    QWidget* get_ptr_wgt_download_history() {
        return this->wgt_download_history;
    }
    DatabaseManger* get_ptr_dbm_history_search() {
        return this->dbm_history_search;
    }
    DatabaseManger* get_ptr_dbm_history_download() {
        return this->dbm_history_download;
    }

private:
    Ui::MainWindow *ui; // new

    // there store book_infos
    QList<BookInfo>* book_infos = nullptr;
    BookFullInfo* book_full_info = nullptr;
    // for showing of books
    QWidget* wgt_book_items = nullptr;
    QScrollBar* sb_sa_books = nullptr;
    // for showing of single book
    QWidget* single_book_info = nullptr; // SingleBookInfo but occurs recusive
    QScrollBar* sb_sa_singlebookview = nullptr;
    // for wgt_book_items
    int get_book_items_height();
    int get_book_items_pos_y_by_index(int index);
    // for toggle_view (main view)
    // wgt_main_search
    QList<QWidget*> main_views;
    QList<QWidget*> navi_views;
    int current_view_idx;

    QList<QWidget*> history_views;
    int current_history_view_idx;

    // cookiemanger
    LocalCookieManger* lcm;

    // databasemanger
    DatabaseManger* dbm_history_search;
    DatabaseManger* dbm_history_download;

    // shv manger
    SearchHistoryViewManger* shv_manger;
    QWidget* wgt_search_history;
    QScrollBar* sb_sa_sub_history_search;

    // dhv manger
    DownloadHistoryViewManger* dhv_manger;
    QWidget* wgt_download_history;
    QScrollBar* sb_sa_sub_history_download;

    // download manger
    DownloadManger* d_manger;

signals:
    // but when search, the GeneralSearch object will be deleted
    // I don't want to copy, because it will cost unnecessary memory
    // void sgn_search(GeneralSearch*);
    void sgn_insert_search_history(SearchHistory&);
    void sgn_insert_download_history(DownloadHistory&);

    // copy, otherwise will be deleted
    void sgn_append_download_history_item(DownloadHistory);

public slots:
    void slot_insert_search_history(SearchHistory& search_history) {
        this->dbm_history_search->insert_item(search_history);
    }
    void slot_insert_download_history(DownloadHistory& download_history) {
        this->dbm_history_download->insert_item(download_history);
    }
    void slot_append_download_history_item(DownloadHistory download_history) {
        this->dhv_manger->append_item(download_history);
    }
};

#endif // MAINWINDOW_H


