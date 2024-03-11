#include "singlebookinfo.h"
#include "ui_singlebookinfo.h"

SingleBookInfo::SingleBookInfo(QWidget *parent, MainWindow* context)
    : QWidget(parent)
    , ui(new Ui::SingleBookInfo)
    , context(context)
{
    ui->setupUi(this);

    ui->lb_return_to_search->installEventFilter(this);
}

SingleBookInfo::~SingleBookInfo()
{
    delete ui;
}

bool SingleBookInfo::eventFilter(QObject* obj, QEvent* event) {
    if (obj == ui->lb_return_to_search && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent) {
            if (mouseEvent->button() == Qt::LeftButton) {
                qDebug() << "return";
                // toggle view
                this->context->toggle_view(SingSongZepe::Search);
                return true;
            }
        }
    }
    return false;
}
