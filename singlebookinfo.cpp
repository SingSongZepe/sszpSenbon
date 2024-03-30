#include "singlebookinfo.h"
#include "ui_singlebookinfo.h"

#include "worker.h"

const int SingleBookInfo::SUB_INFO_LABEL_WIDTH_DEFAULT = 71;
const int SingleBookInfo::SUB_INFO_WIDTH_DEFAULT = 251;
const int SingleBookInfo::SUB_INFO_HEIGHT_DEFAULT = 21;
const int SingleBookInfo::SUB_INFO_WIDTH_CATEGORIES = 41; // occpuies the height of two labels

const int SingleBookInfo::POSITION_OFFSET_X_DEFAULT_1 = 10;
const int SingleBookInfo::POSITION_OFFSET_X_DEFAULT_2 = 360;
const int SingleBookInfo::PADDING_BETWEEN_LABEL_VALUE = 10;

SingleBookInfo::SingleBookInfo(QWidget *parent, MainWindow* context)
    : QWidget(parent)
    , ui(new Ui::SingleBookInfo)
    , context(context)
{
    ui->setupUi(this);

    // click event
    ui->lb_return_to_search->installEventFilter(this);
    ui->wgt_return_to_search->installEventFilter(this);

    // init sa_singlebookinfo_sub_info
    this->sb_sa_singlebookinfo_sub_info = new QScrollBar(ui->sa_singlebookinfo_sub_info);
    this->sb_sa_singlebookinfo_sub_info->setStyleSheet(SingSongZepe::STYLE_SCROLLBAR_SLIM_TRANSPARENT);
    ui->sa_singlebookinfo_sub_info->setVerticalScrollBar(this->sb_sa_singlebookinfo_sub_info);

    // init wgt_sub_info_showing;
    this->wgt_sub_info_showing = new QWidget(ui->sa_singlebookinfo_sub_info);
}

SingleBookInfo::~SingleBookInfo()
{
    delete sb_sa_singlebookinfo_sub_info;
    delete wgt_sub_info_showing;
    delete ui;
}

bool SingleBookInfo::eventFilter(QObject* obj, QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress) { //
        if (obj == ui->lb_return_to_search || obj == ui->wgt_return_to_search) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent) {
                if (mouseEvent->button() == Qt::LeftButton) {
                    qDebug() << "return to Search";
                    // toggle view
                    this->context->toggle_view(SingSongZepe::Search);
                    return true;
                }
            }
        }
    }
    return false;
}

bool SingleBookInfo::set_book_full_info(const BookFullInfo& full_info) {
    this->book_full_info = full_info; // copy

    // main info
    ui->tb_book_title->setText(full_info.title);
    ui->tb_book_authors->setText(full_info.authors);
    ui->lb_book_rating->setText(full_info.rating);

    // description
    ui->tb_book_description->setText(full_info.description);

    // set pixmap
    Worker::work_now([&]() {
        MainWindow::set_label_pixmap(ui->lb_book_cover, MainWindow::load_picture(full_info.cover));
    });

    int xidx = 0, yidx = 0;
    // sub info
    // there be placement order for those labels
        // Categories


    return true;
}

QPoint SingleBookInfo::get_position_by_index(int xidx, int yidx) const {

}


