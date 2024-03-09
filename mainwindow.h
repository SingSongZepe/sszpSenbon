#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "search.h"
#include "object/book_info.h"
#include "worker.h"
#include "singsongzepe.h"
#include "sslog.h"

#include <QMainWindow>
#include <QMouseEvent>
#include <QScrollBar>
#include <QLabel>
#include <QThread>

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

    // sszpSenbon for searching
    void search_books_launch();

    // api
    void search_books(const GeneralSearch* search); // general_search or fulltext_search
    bool show_books();

    // utils
    QString make_url(const GeneralSearch* search);
    QList<BookInfo> json_str2book_infos(const QString* json_str);
    bool initializa_python();
    bool finalize_python();
    static QByteArray request_url(const QString& url);
    static QPixmap load_picture(const QString& url);
    static bool set_label_pixmap(QLabel* lb, const QPixmap& pixmap);

public:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::MainWindow *ui;

    // there store book_infos
    QList<BookInfo>* book_infos = nullptr;
    // for showing of books
    QWidget* wgt_book_items = nullptr;
    QScrollBar* sb_sa_books = nullptr;
    // for wgt_book_items
    int get_book_items_height();
    int get_book_items_pos_y_by_index(int index);
    // for toggle_view (main view)
    // wgt_main_search
    QList<QWidget*> main_views;
    int current_view_idx;
};
#endif // MAINWINDOW_H
