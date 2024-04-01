#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>

void MainWindow::toggle_view(SingSongZepe::ToggleViewKind tvk) {
    QWidget* show_view;
    switch (tvk) {
    case SingSongZepe::Search:
        show_view = ui->wgt_main_search; // ?
        break;
    case SingSongZepe::SingleBookView:
        show_view = ui->wgt_main_singlebookview;
        break;
    case SingSongZepe::History:
        show_view = ui->wgt_main_history;
        break;
    case SingSongZepe::Setting:
        show_view = ui->wgt_main_setting;
        break;
    case SingSongZepe::Todo:
        show_view = ui->wgt_main_todo;
        break;
    }

    if (show_view == this->main_views[this->current_view_idx]) {
        SSLog::ln("this view is already current view");
        return;
    }

    for (int idx = 0; idx != this->main_views.length(); idx++) {
        if (this->main_views[idx] == show_view) {
            this->main_views[idx]->setHidden(false);
            this->navi_views[idx]->setHidden(false);
            this->current_view_idx = idx;
            qDebug() << this->current_view_idx << "set visible";
        } else {
            this->main_views[idx]->setHidden(true);
            this->navi_views[idx]->setHidden(true);
        }
    }
}

void MainWindow::search_books_launch() {
    // collect info and make up a search object
    QString search_type = ui->comb_search_kind->currentText();
    QString key_word = ui->le_search->text();
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
    // qDebug() << url;
    SingleBookSearch search = SingleBookSearch(url);
    MainWindow::search_singlebook(&search);
}


