#include "mainwindow.h"
#include "ui_mainwindow.h"

// mouse event for label click
bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->lb_bar_search && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                this->print_hello(false);
                return true;
            }
        }
    } else if (obj == ui->lb_bar_download && event->type() == QEvent::MouseButtonPress) {

    }
    return QMainWindow::eventFilter(obj, event);
}
