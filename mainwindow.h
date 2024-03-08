#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "search.h"
#include "object/book_info.h"

#include <QMainWindow>
#include <QMouseEvent>

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
    // for searching
    void search_books_launch();

    // api
    void search_books(const GeneralSearch* search); // general_search or fulltext_search

    // utils
    QString make_url(const GeneralSearch* search);
    QList<BookInfo> json_str2book_infos(const QString* json_str);

public:
    bool eventFilter(QObject* obj, QEvent* event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
