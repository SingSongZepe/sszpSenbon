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
    } else if (obj == ui->lb_bar_history && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                this->toggle_view(SingSongZepe::History); // there download mean history
                return true;
            }
        }
    } else if (obj == ui->lb_bar_setting && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                this->toggle_view(SingSongZepe::ToggleViewKind::Setting); // there download mean history
                return true;
            }
        }
    } else if (obj == ui->lb_bar_todo && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                this->toggle_view(SingSongZepe::ToggleViewKind::Todo); // there download mean history
                return true;
            }
        }
    } else if((obj == ui->lb_navi_history_search || obj == ui->lb_navi_history_search_icon) && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                this->toggle_view_history(SingSongZepe::ToggleViewHistoryKind::SearchHistory); // there download mean history
                qDebug() << "sh";
                return true;
            }
        }
    } else if((obj == ui->lb_navi_history_download || obj == ui->lb_navi_history_download_icon) && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                this->toggle_view_history(SingSongZepe::ToggleViewHistoryKind::DownloadHistory); // there download mean history
                qDebug() << "dh";
                return true;
            }
        }
    }
    else if (obj == this->wgt_book_items && event->type() == QEvent::MouseButtonPress) {
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
