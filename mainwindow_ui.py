# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'mainwindow.ui'
##
## Created by: Qt User Interface Compiler version 6.5.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QCheckBox, QComboBox, QFrame,
    QHBoxLayout, QLabel, QLineEdit, QMainWindow,
    QPushButton, QScrollArea, QSizePolicy, QVBoxLayout,
    QWidget)
import image_rc

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        if not MainWindow.objectName():
            MainWindow.setObjectName(u"MainWindow")
        MainWindow.resize(801, 502)
        MainWindow.setStyleSheet(u"")
        self.cw = QWidget(MainWindow)
        self.cw.setObjectName(u"cw")
        self.wgt_head = QWidget(self.cw)
        self.wgt_head.setObjectName(u"wgt_head")
        self.wgt_head.setGeometry(QRect(0, 0, 50, 50))
        self.wgt_head.setStyleSheet(u"#wgt_head {\n"
"	background-color: #f0f0f0;\n"
"}")
        self.verticalLayoutWidget_2 = QWidget(self.wgt_head)
        self.verticalLayoutWidget_2.setObjectName(u"verticalLayoutWidget_2")
        self.verticalLayoutWidget_2.setGeometry(QRect(0, 0, 51, 51))
        self.vl_head = QVBoxLayout(self.verticalLayoutWidget_2)
        self.vl_head.setObjectName(u"vl_head")
        self.vl_head.setContentsMargins(0, 0, 0, 0)
        self.lb_head = QLabel(self.verticalLayoutWidget_2)
        self.lb_head.setObjectName(u"lb_head")

        self.vl_head.addWidget(self.lb_head)

        self.wgt_navi_search = QWidget(self.cw)
        self.wgt_navi_search.setObjectName(u"wgt_navi_search")
        self.wgt_navi_search.setGeometry(QRect(50, 0, 751, 30))
        self.wgt_navi_search.setMinimumSize(QSize(750, 30))
        self.wgt_navi_search.setStyleSheet(u"#wgt_navi_search {\n"
"	background-color: #f0f0f0;\n"
"}")
        self.wgt_search_kind = QWidget(self.wgt_navi_search)
        self.wgt_search_kind.setObjectName(u"wgt_search_kind")
        self.wgt_search_kind.setGeometry(QRect(10, 5, 101, 25))
        self.wgt_search_kind.setMinimumSize(QSize(100, 0))
        self.comb_search_kind = QComboBox(self.wgt_search_kind)
        self.comb_search_kind.addItem("")
        self.comb_search_kind.addItem("")
        self.comb_search_kind.setObjectName(u"comb_search_kind")
        self.comb_search_kind.setGeometry(QRect(1, 0, 100, 25))
        self.comb_search_kind.setMinimumSize(QSize(100, 0))
        self.wgt_exact_matching = QWidget(self.wgt_navi_search)
        self.wgt_exact_matching.setObjectName(u"wgt_exact_matching")
        self.wgt_exact_matching.setGeometry(QRect(130, 5, 150, 25))
        self.wgt_exact_matching.setMinimumSize(QSize(150, 0))
        self.cb_exact_matching = QCheckBox(self.wgt_exact_matching)
        self.cb_exact_matching.setObjectName(u"cb_exact_matching")
        self.cb_exact_matching.setGeometry(QRect(0, 0, 150, 25))
        self.cb_exact_matching.setMinimumSize(QSize(150, 0))
        self.wgt_singsongzepe = QWidget(self.wgt_navi_search)
        self.wgt_singsongzepe.setObjectName(u"wgt_singsongzepe")
        self.wgt_singsongzepe.setGeometry(QRect(490, 5, 261, 25))
        self.lb_singsongzepe = QLabel(self.wgt_singsongzepe)
        self.lb_singsongzepe.setObjectName(u"lb_singsongzepe")
        self.lb_singsongzepe.setGeometry(QRect(0, 0, 261, 25))
        self.wgt_bar = QWidget(self.cw)
        self.wgt_bar.setObjectName(u"wgt_bar")
        self.wgt_bar.setGeometry(QRect(0, 50, 51, 451))
        self.wgt_bar.setMinimumSize(QSize(50, 450))
        self.wgt_bar.setStyleSheet(u"#wgt_bar {\n"
"	background-color: #f0f0f0;\n"
"}")
        self.verticalLayoutWidget = QWidget(self.wgt_bar)
        self.verticalLayoutWidget.setObjectName(u"verticalLayoutWidget")
        self.verticalLayoutWidget.setGeometry(QRect(0, 0, 51, 476))
        self.vl_bar = QVBoxLayout(self.verticalLayoutWidget)
        self.vl_bar.setSpacing(80)
        self.vl_bar.setObjectName(u"vl_bar")
        self.vl_bar.setContentsMargins(3, 30, 3, 30)
        self.lb_bar_search = QLabel(self.verticalLayoutWidget)
        self.lb_bar_search.setObjectName(u"lb_bar_search")
        self.lb_bar_search.setMinimumSize(QSize(44, 44))
        self.lb_bar_search.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_bar_search.setPixmap(QPixmap(u":/:/res/image/search.png"))
        self.lb_bar_search.setScaledContents(True)

        self.vl_bar.addWidget(self.lb_bar_search)

        self.lb_bar_history = QLabel(self.verticalLayoutWidget)
        self.lb_bar_history.setObjectName(u"lb_bar_history")
        self.lb_bar_history.setMinimumSize(QSize(44, 44))
        self.lb_bar_history.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_bar_history.setPixmap(QPixmap(u":/:/res/image/download.png"))
        self.lb_bar_history.setScaledContents(True)

        self.vl_bar.addWidget(self.lb_bar_history)

        self.lb_bar_setting = QLabel(self.verticalLayoutWidget)
        self.lb_bar_setting.setObjectName(u"lb_bar_setting")
        self.lb_bar_setting.setMinimumSize(QSize(44, 44))
        self.lb_bar_setting.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_bar_setting.setPixmap(QPixmap(u":/:/res/image/setting.png"))
        self.lb_bar_setting.setScaledContents(True)

        self.vl_bar.addWidget(self.lb_bar_setting)

        self.lb_bar_todo = QLabel(self.verticalLayoutWidget)
        self.lb_bar_todo.setObjectName(u"lb_bar_todo")
        self.lb_bar_todo.setMinimumSize(QSize(44, 44))
        self.lb_bar_todo.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_bar_todo.setPixmap(QPixmap(u":/:/res/image/todo.png"))
        self.lb_bar_todo.setScaledContents(True)

        self.vl_bar.addWidget(self.lb_bar_todo)

        self.wgt_main_search = QWidget(self.cw)
        self.wgt_main_search.setObjectName(u"wgt_main_search")
        self.wgt_main_search.setGeometry(QRect(50, 30, 751, 471))
        self.wgt_main_search.setMinimumSize(QSize(750, 470))
        self.wgt_main_search.setStyleSheet(u"#wgt_main_search {\n"
"	background-color: #f8f8f8;\n"
"}")
        self.wgt_search = QWidget(self.wgt_main_search)
        self.wgt_search.setObjectName(u"wgt_search")
        self.wgt_search.setGeometry(QRect(0, 70, 750, 51))
        self.horizontalLayoutWidget = QWidget(self.wgt_search)
        self.horizontalLayoutWidget.setObjectName(u"horizontalLayoutWidget")
        self.horizontalLayoutWidget.setGeometry(QRect(0, 0, 751, 52))
        self.hl_search = QHBoxLayout(self.horizontalLayoutWidget)
        self.hl_search.setSpacing(3)
        self.hl_search.setObjectName(u"hl_search")
        self.hl_search.setContentsMargins(50, 0, 50, 0)
        self.le_search = QLineEdit(self.horizontalLayoutWidget)
        self.le_search.setObjectName(u"le_search")
        self.le_search.setMinimumSize(QSize(0, 45))
        font = QFont()
        font.setPointSize(10)
        self.le_search.setFont(font)
        self.le_search.setStyleSheet(u"#le_search {\n"
"	border-radius: 10px;\n"
"	padding-left: 20px;\n"
"	padding-right: 20px;\n"
"}")

        self.hl_search.addWidget(self.le_search)

        self.pb_search = QPushButton(self.horizontalLayoutWidget)
        self.pb_search.setObjectName(u"pb_search")
        self.pb_search.setEnabled(True)
        self.pb_search.setMinimumSize(QSize(45, 45))
        self.pb_search.setCursor(QCursor(Qt.PointingHandCursor))
        icon = QIcon()
        icon.addFile(u":/:/res/image/search_gray.png", QSize(), QIcon.Normal, QIcon.Off)
        self.pb_search.setIcon(icon)

        self.hl_search.addWidget(self.pb_search)

        self.wgt_books = QWidget(self.wgt_main_search)
        self.wgt_books.setObjectName(u"wgt_books")
        self.wgt_books.setGeometry(QRect(0, 170, 751, 301))
        self.wgt_books.setStyleSheet(u"#wgt_books {\n"
"	background-color: #ADD8E6;\n"
"    border-top-left-radius: 15px; \n"
"    border-top-right-radius: 15px; \n"
"	margin: 2px;\n"
"}")
        self.sa_books = QScrollArea(self.wgt_books)
        self.sa_books.setObjectName(u"sa_books")
        self.sa_books.setGeometry(QRect(10, 10, 731, 291))
        self.sa_books.setStyleSheet(u"background-color: #ADD8E6;\n"
"")
        self.sa_books.setFrameShape(QFrame.Box)
        self.sa_books.setLineWidth(0)
        self.sa_books.setWidgetResizable(True)
        self.sawc_books = QWidget()
        self.sawc_books.setObjectName(u"sawc_books")
        self.sawc_books.setGeometry(QRect(0, 0, 731, 291))
        self.sawc_books.setStyleSheet(u"#scwc_books {\n"
"	background-color: #ADD8E6;\n"
"    border-top-left-radius: 15px; \n"
"    border-top-right-radius: 15px; \n"
"}")
        self.sa_books.setWidget(self.sawc_books)
        self.wgt_main_singlebookview = QWidget(self.cw)
        self.wgt_main_singlebookview.setObjectName(u"wgt_main_singlebookview")
        self.wgt_main_singlebookview.setGeometry(QRect(50, 30, 751, 471))
        self.sa_singlebookview = QScrollArea(self.wgt_main_singlebookview)
        self.sa_singlebookview.setObjectName(u"sa_singlebookview")
        self.sa_singlebookview.setGeometry(QRect(0, 0, 751, 471))
        self.sa_singlebookview.setWidgetResizable(True)
        self.sawc_singlebookview = QWidget()
        self.sawc_singlebookview.setObjectName(u"sawc_singlebookview")
        self.sawc_singlebookview.setGeometry(QRect(0, 0, 749, 469))
        self.sa_singlebookview.setWidget(self.sawc_singlebookview)
        self.wgt_navi_singlebookview = QWidget(self.cw)
        self.wgt_navi_singlebookview.setObjectName(u"wgt_navi_singlebookview")
        self.wgt_navi_singlebookview.setGeometry(QRect(50, 0, 751, 30))
        self.wgt_navi_singlebookview.setMinimumSize(QSize(750, 30))
        self.wgt_navi_singlebookview.setStyleSheet(u"#wgt_navi_search {\n"
"	background-color: #f0f0f0;\n"
"}")
        self.wgt_singsongzepe_2 = QWidget(self.wgt_navi_singlebookview)
        self.wgt_singsongzepe_2.setObjectName(u"wgt_singsongzepe_2")
        self.wgt_singsongzepe_2.setGeometry(QRect(490, 5, 261, 25))
        self.lb_singsongzepe_2 = QLabel(self.wgt_singsongzepe_2)
        self.lb_singsongzepe_2.setObjectName(u"lb_singsongzepe_2")
        self.lb_singsongzepe_2.setGeometry(QRect(0, 0, 261, 25))
        self.wgt_navi_history = QWidget(self.cw)
        self.wgt_navi_history.setObjectName(u"wgt_navi_history")
        self.wgt_navi_history.setGeometry(QRect(50, 0, 751, 31))
        self.wgt_navi_history_search = QWidget(self.wgt_navi_history)
        self.wgt_navi_history_search.setObjectName(u"wgt_navi_history_search")
        self.wgt_navi_history_search.setGeometry(QRect(10, 10, 101, 21))
        self.lb_navi_history_search_icon = QLabel(self.wgt_navi_history_search)
        self.lb_navi_history_search_icon.setObjectName(u"lb_navi_history_search_icon")
        self.lb_navi_history_search_icon.setGeometry(QRect(0, 0, 21, 21))
        self.lb_navi_history_search = QLabel(self.wgt_navi_history_search)
        self.lb_navi_history_search.setObjectName(u"lb_navi_history_search")
        self.lb_navi_history_search.setGeometry(QRect(20, 0, 81, 21))
        self.lb_navi_history_search.setAlignment(Qt.AlignCenter)
        self.wgt_main_history = QWidget(self.cw)
        self.wgt_main_history.setObjectName(u"wgt_main_history")
        self.wgt_main_history.setGeometry(QRect(50, 30, 751, 471))
        self.wgt_main_setting = QWidget(self.cw)
        self.wgt_main_setting.setObjectName(u"wgt_main_setting")
        self.wgt_main_setting.setGeometry(QRect(50, 30, 751, 471))
        self.wgt_navi_setting = QWidget(self.cw)
        self.wgt_navi_setting.setObjectName(u"wgt_navi_setting")
        self.wgt_navi_setting.setGeometry(QRect(50, 0, 751, 30))
        self.wgt_main_todo = QWidget(self.cw)
        self.wgt_main_todo.setObjectName(u"wgt_main_todo")
        self.wgt_main_todo.setGeometry(QRect(50, 30, 751, 471))
        self.wgt_navi_todo = QWidget(self.cw)
        self.wgt_navi_todo.setObjectName(u"wgt_navi_todo")
        self.wgt_navi_todo.setGeometry(QRect(50, 0, 751, 31))
        MainWindow.setCentralWidget(self.cw)
        self.wgt_main_todo.raise_()
        self.wgt_main_singlebookview.raise_()
        self.wgt_head.raise_()
        self.wgt_navi_search.raise_()
        self.wgt_bar.raise_()
        self.wgt_main_search.raise_()
        self.wgt_navi_singlebookview.raise_()
        self.wgt_main_history.raise_()
        self.wgt_main_setting.raise_()
        self.wgt_navi_setting.raise_()
        self.wgt_navi_todo.raise_()
        self.wgt_navi_history.raise_()

        self.retranslateUi(MainWindow)

        QMetaObject.connectSlotsByName(MainWindow)
    # setupUi

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QCoreApplication.translate("MainWindow", u"MainWindow", None))
        self.lb_head.setText("")
        self.comb_search_kind.setItemText(0, QCoreApplication.translate("MainWindow", u"General", None))
        self.comb_search_kind.setItemText(1, QCoreApplication.translate("MainWindow", u"Fulltext", None))

        self.cb_exact_matching.setText(QCoreApplication.translate("MainWindow", u"Exact Matching", None))
        self.lb_singsongzepe.setText("")
        self.lb_bar_search.setText("")
        self.lb_bar_history.setText("")
        self.lb_bar_setting.setText("")
        self.lb_bar_todo.setText("")
        self.le_search.setText(QCoreApplication.translate("MainWindow", u"Hello", None))
        self.le_search.setPlaceholderText(QCoreApplication.translate("MainWindow", u"Search books", None))
        self.pb_search.setText("")
        self.lb_singsongzepe_2.setText("")
        self.lb_navi_history_search_icon.setText("")
        self.lb_navi_history_search.setText(QCoreApplication.translate("MainWindow", u"Search", None))
    # retranslateUi

