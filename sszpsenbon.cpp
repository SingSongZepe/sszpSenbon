#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::search_books_launch() {
    // collect info and make up a search object
    QString* search_type = new QString(this->ui->comb_search_kind->currentText());
    QString* key_word = new QString(this->ui->le_search->text());
    if (*key_word == SearchConstants::GENERAL_SEARCH_) {
        GeneralSearch* gs = new GeneralSearch(search_type, key_word);
        // call
        MainWindow::search_books(gs);
        delete gs;
    } else {
        FulltextSearch* fs = new FulltextSearch(search_type, key_word);
        // call
        MainWindow::search_books(fs);
        delete fs;
    }
}
