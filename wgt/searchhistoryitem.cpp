#include "searchhistoryitem.h"
#include "ui_searchhistoryitem.h"

#include "wgt_manger/searchhistoryviewmanger.h"
#include "mainwindow.h"

#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

SearchHistoryItem::SearchHistoryItem(SearchHistoryViewManger* shv_manger, QWidget *parent, int idx)
    : QWidget(parent)
    , ui(new Ui::SearchHistoryItem)
    , shv_manger(shv_manger)
    , idx(idx)
{
    ui->setupUi(this);

    QObject::connect(ui->pb_research, &QPushButton::clicked, this, &SearchHistoryItem::research);

    ui->lb_delete->installEventFilter(this);
}

void SearchHistoryItem::set_search_history_info(const SearchHistory& search_history) {
    this->search_history = search_history;
    // main info
    ui->tb_key_word->setText(search_history.key_word);
    ui->lb_search_type->setText(search_history.search_type);

    // sub info
    ui->lb_languages->setText(search_history.get_str_languages());
    ui->lb_extensions->setText(search_history.get_str_extensions());
    ui->lb_require_time->setText(search_history.get_str_require_time());
    ui->lb_exact_matching->setText(search_history.get_str_exact_matching());
    ui->lb_match_a_phrase->setText(search_history.get_str_match_a_phrase());

    ui->lb_time->setText(search_history.time);
    ui->lb_id->setText(search_history.id);

    this->id = search_history.id;
}

bool SearchHistoryItem::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->lb_delete && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // delete (self and wgt after self)
                this->shv_manger->delete_item(this->idx);
                return true;
            }
        }
    }
    return false;
}

// re search doesn't need to append the
void SearchHistoryItem::research() {
    // if (this->search_history.search_type == SearchConstants::GENERAL_SEARCH) {
    //     GeneralSearch gs = this->search_history.cvt_search_history<GeneralSearch>();
    //     this->shv_manger->context->search_books(&gs);
    // } else {
    //     FulltextSearch fs = this->search_history.cvt_search_history<FulltextSearch>();
    //     this->shv_manger->context->search_books(&fs);
    // }
}

// 'this' will be released by context->wgt_search_history
SearchHistoryItem::~SearchHistoryItem() {
    qDebug() << "sh_item release";
    delete ui;
}
