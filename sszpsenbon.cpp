#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "object/searchhistory.h"

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

    // check whether current view
    // if (show_view == this->main_views[this->current_view_idx]) {
    //     SSLog::ln("this view is already current view");
    //     return;
    // }

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

void MainWindow::toggle_view_history(SingSongZepe::ToggleViewHistoryKind tvhk) {
    QWidget* show_view;
    switch(tvhk) {
    case SingSongZepe::SearchHistory:
        show_view = ui->wgt_sub_history_search;
        break;
    case SingSongZepe::DownloadHistory:
        show_view = ui->wgt_sub_history_download;
        break;
    default:
        show_view = ui->wgt_sub_history_search;
        break;
    }

    for (int idx = 0; idx != this->history_views.length(); idx++) {
        if (this->history_views[idx] == show_view) {
            this->history_views[idx]->setHidden(false);
            this->current_history_view_idx = idx;
        } else {
            this->history_views[idx]->setHidden(true);
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
        // after search book
        // we add the search to database
        SearchHistory sh = SearchHistory(gs);
        if (this->dbm_history_search->insert_item(sh)) {
            SSLog::ln("add the search to database successfully");
        }
        this->shv_manger->append_item(sh);

    } else {
        FulltextSearch fs = FulltextSearch(search_type, key_word);
        // call
        MainWindow::search_books(&fs);
        // after search book
        // we add the search to database
        SearchHistory sh = SearchHistory(fs);
        if (this->dbm_history_search->insert_item(sh)) {
            SSLog::ln("add the search to database successfully");
        }
        this->shv_manger->append_item(sh);
    }
}

void MainWindow::search_singlebook_launch(const QString& href) {
    QString url = QUrl(SingSongZepe::zlibrary_url).resolved(QUrl(href)).toString();
    // qDebug() << url;
    SingleBookSearch search = SingleBookSearch(url);
    MainWindow::search_singlebook(&search);
}


