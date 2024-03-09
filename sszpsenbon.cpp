#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::toggle_view(SingSongZepe::ToggleViewKind tvk) {
    QWidget* show_view;
    switch (tvk) {
    case SingSongZepe::Search:
        show_view = this->ui->wgt_main_search;
        break;
    case SingSongZepe::SingleBookView:
        show_view = this->ui->wgt_main_search;
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
    for (QWidget* view : this->main_views) {
        if (view == show_view) {
            view->setHidden(false);
        } else {
            view->setHidden(true);
        }
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
