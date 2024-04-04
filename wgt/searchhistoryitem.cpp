#include "searchhistoryitem.h"
#include "ui_searchhistoryitem.h"

#include "wgt_manger/searchhistoryviewmanger.h"

#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

SearchHistoryItem::SearchHistoryItem(SearchHistoryViewManger* shv_manger, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchHistoryItem)
    , shv_manger(shv_manger)
{
    ui->setupUi(this);

    QObject::connect(ui->pb_research, &QPushButton::clicked, [](){ qDebug() << "research"; });

    ui->lb_delete->installEventFilter(this);
}
void SearchHistoryItem::set_search_history_info(const SearchHistory& search_history) {
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
}

bool SearchHistoryItem::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->lb_delete && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                // toggle view
                qDebug() << "delete";
                return true;
            }
        }
    }
}

// will be released by context->wgt_search_history
SearchHistoryItem::~SearchHistoryItem() {
    delete ui;
}
