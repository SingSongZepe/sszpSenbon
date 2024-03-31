#include "singlebookinfo.h"
#include "ui_singlebookinfo.h"

#include "worker.h"
#include "function/savefile.h"

const int SingleBookInfo::SUB_INFO_LABEL_WIDTH_DEFAULT = 71;
const int SingleBookInfo::SUB_INFO_WIDTH_DEFAULT = 251;
const int SingleBookInfo::SUB_INFO_HEIGHT_DEFAULT = 21;
const int SingleBookInfo::SUB_INFO_HEIGHT_CATEGORIES = 41; // occpuies the height of two labels

const int SingleBookInfo::POSITION_OFFSET_X_DEFAULT_1 = 10;
const int SingleBookInfo::POSITION_OFFSET_X_DEFAULT_2 = 360;
const int SingleBookInfo::POSITION_OFFSET_Y_DEFAULT = 10;
const int SingleBookInfo::PADDING_BETWEEN_LABEL_VALUE = 10;

const QString SingleBookInfo::SECTION_VALUE_DEFAULT = "unknown";
const QString SingleBookInfo::DESCRIPTION_UNKNOWN = "no description";

const QString SingleBookInfo::RE_EXTENSION = "\\b(\\w+)\\b";
const QString SingleBookInfo::RE_REMOVE = "[<>:\"/\\|?*]";
const QString SingleBookInfo::EXTENSION_UNKNOWN = "unknown";

const QRegularExpression SingleBookInfo::re_extension = QRegularExpression(SingleBookInfo::RE_EXTENSION);
const QRegularExpression SingleBookInfo::re_remove = QRegularExpression(SingleBookInfo::RE_REMOVE);

SingleBookInfo::SingleBookInfo(QWidget *parent, MainWindow* context)
    : QWidget(parent)
    , ui(new Ui::SingleBookInfo)
    , context(context)
{
    ui->setupUi(this);

    // click event
    ui->lb_return_to_search->installEventFilter(this);
    ui->wgt_return_to_search->installEventFilter(this);

    // download
    ui->lb_book_cover->installEventFilter(this);

    // init sa_singlebookinfo_sub_info
    this->sb_sa_singlebookinfo_sub_info = new QScrollBar(ui->sa_singlebookinfo_sub_info);
    this->sb_sa_singlebookinfo_sub_info->setStyleSheet(SingSongZepe::STYLE_SCROLLBAR_SLIM_TRANSPARENT);
    ui->sa_singlebookinfo_sub_info->setVerticalScrollBar(this->sb_sa_singlebookinfo_sub_info);

    // init wgt_sub_info_showing;
    this->wgt_sub_info_showing = new QWidget(ui->sa_singlebookinfo_sub_info);
    this->wgt_sub_info_showing->setGeometry(0, 0, 0, 0);
    this->wgt_sub_info_showing->setFixedSize(ui->sa_singlebookinfo_sub_info->geometry().width(), 100);
    ui->sa_singlebookinfo_sub_info->setWidget(this->wgt_sub_info_showing);
}

SingleBookInfo::~SingleBookInfo() {
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
        } else if (obj == ui->lb_book_cover) {
            // MainWindow::download_book(this->book_full_info.url, this->cookie);
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent) {
                if (mouseEvent->button() == Qt::LeftButton) {
                    this->download_book();
                    return true;
                }
            }
        }
    }
    return false;
}

// we need to monitor the process of downloading
// so we need to append the download thread to context
// and will display the process of downloading
bool SingleBookInfo::download_book() {
    SSLog::ln(this->book_full_info.title);
    SSLog::ln(this->book_full_info.url);
    SSLog::ln(this->cookie.cookie);

    // request for book
    QByteArray book_data = MainWindow::request_url_with_cookie_no_timeout(this->book_full_info.url, this->cookie.cookie);

    // save the file
    SaveFile::save_file(book_data, SingleBookInfo::make_book_name());

    return true;
}

bool SingleBookInfo::set_cookie(const Cookie& cookie) {
    this->cookie = cookie;
    return true;
}

bool SingleBookInfo::set_book_full_info(const BookFullInfo& full_info) {
    this->book_full_info = full_info; // copy

    // main info
    ui->tb_book_title->setText(full_info.title);
    ui->tb_book_authors->setText(full_info.authors);
    ui->lb_book_rating->setText(full_info.rating);

    // description
    if (full_info.description == SingleBookInfo::SECTION_VALUE_DEFAULT) {
        ui->tb_book_description->setText(SingleBookInfo::DESCRIPTION_UNKNOWN);
    } else {
        ui->tb_book_description->setText(full_info.description);
    }

    // set pixmap
    Worker::work_now([&]() {
        MainWindow::set_label_pixmap(ui->lb_book_cover, MainWindow::load_picture(full_info.cover));
    });

    int n = 0; // how many sub info there be // categories for 2

    // sub info
    // there be placement order for those labels
        // Categories
    if (full_info.categories != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n += 2;
        QLabel* lb_book_categories_lb = new QLabel(this->wgt_sub_info_showing);
        // lb_book_categories_lb->setGeometry(SingleBookInfo::POSITION_OFFSET_X_DEFAULT_1,
        //                                   SingleBookInfo::POSITION_OFFSET_Y_DEFAULT,
        //                                   SingleBookInfo::SUB_INFO_LABEL_WIDTH_DEFAULT,
        //                                   SingleBookInfo::SUB_INFO_HEIGHT_DEFAULT);
        lb_book_categories_lb->setText(SingSongZepe::CATEGORIES_);
        // this->lbs_sub_info.append(lb_book_categories_lb);

        QLabel* lb_book_categories = new QLabel(this->wgt_sub_info_showing);
        // lb_book_categories->setGeometry(SingleBookInfo::POSITION_OFFSET_X_DEFAULT_1 + SingleBookInfo::SUB_INFO_LABEL_WIDTH_DEFAULT + SingleBookInfo::PADDING_BETWEEN_LABEL_VALUE,
        //                                SingleBookInfo::POSITION_OFFSET_Y_DEFAULT,
        //                                SingleBookInfo::SUB_INFO_WIDTH_DEFAULT,
        //                                SingleBookInfo::SUB_INFO_HEIGHT_CATEGORIES);
        lb_book_categories->setText(full_info.categories);
        // this->lbs_sub_info.append(lb_book_categories);
    } else {
        SSLog::ln("there are no categories found");
    }

        // Language
    if (full_info.language != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_language_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_language_lb->setText(SingSongZepe::LANGUAGE_);

        QLabel* lb_book_language = new QLabel(this->wgt_sub_info_showing);
        lb_book_language->setText(full_info.language);
    } else {
        SSLog::ln("there are no language found");
    }

        //  Year
    if (full_info.year != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_year_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_year_lb->setText(SingSongZepe::YEAR_);

        QLabel* lb_book_year = new QLabel(this->wgt_sub_info_showing);
        lb_book_year->setText(full_info.year);
    } else {
        SSLog::ln("there are no year found");
    }

        // File
    if (full_info.file != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_file_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_file_lb->setText(SingSongZepe::FILE_);

        QLabel* lb_book_file = new QLabel(this->wgt_sub_info_showing);
        lb_book_file->setText(full_info.file);
    } else {
        SSLog::ln("there are no language found");
    }

        // Publisher
    if (full_info.publisher != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_publisher_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_publisher_lb->setText(SingSongZepe::PUBLISHER_);

        QLabel* lb_book_publisher = new QLabel(this->wgt_sub_info_showing);
        lb_book_publisher->setText(full_info.publisher);
    } else {
        SSLog::ln("there are no publisher found");
    }

        // Pages
    if (full_info.pages != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_pages_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_pages_lb->setText(SingSongZepe::PAGES_);

        QLabel* lb_book_pages = new QLabel(this->wgt_sub_info_showing);
        lb_book_pages->setText(full_info.pages);
    } else {
        SSLog::ln("there are no pages found");
    }

        // ISBN
    if (full_info.isbn != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_isbn_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_isbn_lb->setText(SingSongZepe::ISBN_);

        QLabel* lb_book_isbn = new QLabel(this->wgt_sub_info_showing);
        lb_book_isbn->setText(full_info.isbn);
    } else {
        SSLog::ln("there are no isbn found");
    }

        // ISBN 10
    if (full_info.isbn10 != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_isbn10_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_isbn10_lb->setText(SingSongZepe::ISBN10_);

        QLabel* lb_book_isbn10 = new QLabel(this->wgt_sub_info_showing);
        lb_book_isbn10->setText(full_info.isbn10);
    } else {
        SSLog::ln("there are no isbn 10 found");
    }

        // ISBN 13
    if (full_info.isbn13 != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_isbn13_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_isbn13_lb->setText(SingSongZepe::ISBN13_);

        QLabel* lb_book_isbn13 = new QLabel(this->wgt_sub_info_showing);
        lb_book_isbn13->setText(full_info.isbn13);
    } else {
        SSLog::ln("there are no isbn 13 found");
    }

        // IPFS
    if (full_info.ipfs != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_ipfs_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_ipfs_lb->setText(SingSongZepe::IPFS_);

        QLabel* lb_book_ipfs = new QLabel(this->wgt_sub_info_showing);
        lb_book_ipfs->setText(full_info.ipfs);
    } else {
        SSLog::ln("there are no ipfs found");
    }

        // volume
    if (full_info.volume != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_volume_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_volume_lb->setText(SingSongZepe::VOLUME_);

        QLabel* lb_book_volume = new QLabel(this->wgt_sub_info_showing);
        lb_book_volume->setText(full_info.volume);
    } else {
        SSLog::ln("there are no volume found");
    }

        // edition
    if (full_info.edition != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_edition_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_edition_lb->setText(SingSongZepe::EDITION_);

        QLabel* lb_book_edition = new QLabel(this->wgt_sub_info_showing);
        lb_book_edition->setText(full_info.edition);
    } else {
        SSLog::ln("there are no edition found");
    }

        // series
    if (full_info.series != SingleBookInfo::SECTION_VALUE_DEFAULT) {
        n++;
        QLabel* lb_book_series_lb = new QLabel(this->wgt_sub_info_showing);
        lb_book_series_lb->setText(SingSongZepe::SERIES_);

        QLabel* lb_book_series = new QLabel(this->wgt_sub_info_showing);
        lb_book_series->setText(full_info.series);
    } else {
        SSLog::ln("there are no series found");
    }

    return true;
}

QPoint SingleBookInfo::get_position_by_index(int xidx, int yidx) const {


}

// with extension, like pdf epub
QString SingleBookInfo::make_book_name() const {
    QRegularExpressionMatch match = SingleBookInfo::re_extension.match(this->book_full_info.file);

    if (match.hasMatch()) {
        return SingleBookInfo::retitle(this->book_full_info.title) + "." + match.captured(1);
    }

    return this->book_full_info.title + "." + SingleBookInfo::EXTENSION_UNKNOWN;
}

// may be a better practice
// void SingleBookInfo::retitle(QString& title) {
//     title.remove(SingleBookInfo::re_remove);
// }
// when call it, if you don't want to change original string
// then just need to copy string once
// QString copy = this->book_full_info.title;
// and then pass the copy to the function
QString SingleBookInfo::retitle(const QString& title) {
    QString copy = title;
    copy.remove(SingleBookInfo::re_remove);
    return copy;
}
