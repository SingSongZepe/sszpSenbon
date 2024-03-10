#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>

void MainWindow::toggle_view(SingSongZepe::ToggleViewKind tvk) {
    QWidget* show_view;
    switch (tvk) {
    case SingSongZepe::Search:
        show_view = this->ui->wgt_main_search;
        break;
    case SingSongZepe::SingleBookView:
        show_view = this->ui->wgt_main_singlebookview;
        break;
    case SingSongZepe::History:
        show_view = this->ui->wgt_main_search;
        break;
    case SingSongZepe::Setting:
        show_view = this->ui->wgt_main_search;
        break;
    case SingSongZepe::Todo:
        show_view = this->ui->wgt_main_search;
        break;
    default:
        break;
    }
    if (show_view == this->main_views[this->current_view_idx]) {
        SSLog::ln("this view is already current view");
        return;
    }
    int current_view_idx = 0;
    for (QWidget* view : this->main_views) {
        if (view == show_view) {
            view->setHidden(false);
            this->current_view_idx = current_view_idx;
            qDebug() << this->current_view_idx << "set visible";
        } else {
            view->setHidden(true);
        }
        current_view_idx++;
    }
}

void MainWindow::search_books_launch() {
    // collect info and make up a search object
    QString search_type = this->ui->comb_search_kind->currentText();
    QString key_word = this->ui->le_search->text();
    if (search_type == SearchConstants::GENERAL_SEARCH) {
        GeneralSearch gs = GeneralSearch(search_type, key_word);
        // call
        MainWindow::search_books(&gs);
    } else {
        FulltextSearch fs = FulltextSearch(search_type, key_word);
        // call
        MainWindow::search_books(&fs);
    }
}

void MainWindow::search_singlebook_launch(const QString& href) {
    QString url = QUrl(SingSongZepe::zlibrary_url).resolved(QUrl(href)).toString();
    SingleBookSearch search = SingleBookSearch(url);
    MainWindow::search_singlebook(&search);
}


