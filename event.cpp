#include "mainwindow.h"
#include "ui_mainwindow.h"

// mouse event for label click
bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->lb_bar_search && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                this->toggle_view(SingSongZepe::Search);
                return true;
            }
        }
    } else if (obj == ui->lb_bar_download && event->type() == QEvent::MouseButtonPress) {

    } else if (obj == this->wgt_book_items && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event) {
            if (mouse_event->button() == Qt::LeftButton) {
                const BookInfo* book_info = MainWindow::get_bookinfo_of_pos(mouse_event->pos());
                if (book_info != nullptr) {
                    MainWindow::search_singlebook_launch(book_info->href);
                    return true;
                }
                return false;
            }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}
