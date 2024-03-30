# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'singlebookinfo_sub_info_example2.ui'
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
from PySide6.QtWidgets import (QApplication, QFrame, QLabel, QSizePolicy,
    QTextBrowser, QWidget)
import image_rc

class Ui_SingleBookInfo(object):
    def setupUi(self, SingleBookInfo):
        if not SingleBookInfo.objectName():
            SingleBookInfo.setObjectName(u"SingleBookInfo")
        SingleBookInfo.resize(751, 471)
        self.wgt_book_cover = QWidget(SingleBookInfo)
        self.wgt_book_cover.setObjectName(u"wgt_book_cover")
        self.wgt_book_cover.setGeometry(QRect(25, 30, 200, 280))
        self.lb_book_cover = QLabel(self.wgt_book_cover)
        self.lb_book_cover.setObjectName(u"lb_book_cover")
        self.lb_book_cover.setGeometry(QRect(0, 0, 200, 280))
        self.lb_book_cover.setStyleSheet(u"background: red;")
        self.lb_book_cover.setPixmap(QPixmap(u":/:/res/tmp/cover.jpg"))
        self.lb_book_cover.setScaledContents(True)
        self.wgt_main_info = QWidget(SingleBookInfo)
        self.wgt_main_info.setObjectName(u"wgt_main_info")
        self.wgt_main_info.setGeometry(QRect(250, 40, 461, 111))
        self.wgt_main_info.setStyleSheet(u"")
        self.lb_book_title_icon = QLabel(self.wgt_main_info)
        self.lb_book_title_icon.setObjectName(u"lb_book_title_icon")
        self.lb_book_title_icon.setGeometry(QRect(10, 10, 16, 41))
        self.lb_book_title_icon.setPixmap(QPixmap(u":/:/res/image/title_slim.png"))
        self.tb_book_title = QTextBrowser(self.wgt_main_info)
        self.tb_book_title.setObjectName(u"tb_book_title")
        self.tb_book_title.setGeometry(QRect(30, 10, 411, 41))
        self.tb_book_title.setStyleSheet(u"background: rgba(0,0,0,0);\n"
"border: 0;")
        self.tb_book_authors = QTextBrowser(self.wgt_main_info)
        self.tb_book_authors.setObjectName(u"tb_book_authors")
        self.tb_book_authors.setGeometry(QRect(40, 60, 171, 21))
        self.tb_book_authors.viewport().setProperty("cursor", QCursor(Qt.PointingHandCursor))
        self.tb_book_authors.setStyleSheet(u"#tb_book_authors {\n"
"	background: rgba(0,0,0,0);\n"
"	color: #49AFD0;\n"
"}")
        self.tb_book_authors.setFrameShape(QFrame.NoFrame)
        self.tb_book_authors.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tb_book_authors.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tb_book_authors.setTabChangesFocus(False)
        self.lb_book_authors_icon = QLabel(self.wgt_main_info)
        self.lb_book_authors_icon.setObjectName(u"lb_book_authors_icon")
        self.lb_book_authors_icon.setGeometry(QRect(10, 60, 21, 21))
        self.lb_book_authors_icon.setPixmap(QPixmap(u":/:/res/image/authors.png"))
        self.lb_book_authors_icon.setScaledContents(True)
        self.lb_book_rating_icon = QLabel(self.wgt_main_info)
        self.lb_book_rating_icon.setObjectName(u"lb_book_rating_icon")
        self.lb_book_rating_icon.setGeometry(QRect(10, 80, 21, 21))
        self.lb_book_rating_icon.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_book_rating_icon.setStyleSheet(u"#lb_book_rating_icon {\n"
"	padding: 1px;\n"
"}")
        self.lb_book_rating_icon.setPixmap(QPixmap(u":/:/res/image/rating.png"))
        self.lb_book_rating_icon.setScaledContents(True)
        self.lb_book_rating = QLabel(self.wgt_main_info)
        self.lb_book_rating.setObjectName(u"lb_book_rating")
        self.lb_book_rating.setGeometry(QRect(40, 80, 91, 21))
        font = QFont()
        font.setPointSize(10)
        font.setBold(False)
        font.setItalic(True)
        self.lb_book_rating.setFont(font)
        self.lb_book_rating.setCursor(QCursor(Qt.IBeamCursor))
        self.lb_book_rating.setStyleSheet(u"#lb_book_rating {\n"
"	color: #49AFD0\n"
"}")
        self.lb_book_rating.setScaledContents(False)
        self.lb_book_like_icon = QLabel(self.wgt_main_info)
        self.lb_book_like_icon.setObjectName(u"lb_book_like_icon")
        self.lb_book_like_icon.setGeometry(QRect(150, 80, 21, 21))
        self.lb_book_like_icon.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_book_like_icon.setStyleSheet(u"#lb_book_rating_icon {\n"
"	padding: 1px;\n"
"}")
        self.lb_book_like_icon.setPixmap(QPixmap(u":/:/res/image/like.png"))
        self.lb_book_like_icon.setScaledContents(True)
        self.lb_book_bookmark_icon = QLabel(self.wgt_main_info)
        self.lb_book_bookmark_icon.setObjectName(u"lb_book_bookmark_icon")
        self.lb_book_bookmark_icon.setGeometry(QRect(190, 80, 21, 21))
        self.lb_book_bookmark_icon.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_book_bookmark_icon.setStyleSheet(u"#lb_book_rating_icon {\n"
"	padding: 1px;\n"
"}")
        self.lb_book_bookmark_icon.setPixmap(QPixmap(u":/:/res/image/bookmark.png"))
        self.lb_book_bookmark_icon.setScaledContents(True)
        self.wgt_book_description = QWidget(SingleBookInfo)
        self.wgt_book_description.setObjectName(u"wgt_book_description")
        self.wgt_book_description.setGeometry(QRect(250, 170, 461, 131))
        self.tb_book_description = QTextBrowser(self.wgt_book_description)
        self.tb_book_description.setObjectName(u"tb_book_description")
        self.tb_book_description.setGeometry(QRect(0, 0, 461, 131))
        font1 = QFont()
        font1.setFamilies([u"Stylus BT"])
        font1.setPointSize(11)
        self.tb_book_description.setFont(font1)
        self.tb_book_description.setStyleSheet(u"background-color: rgba(0,0,0,0);")
        self.tb_book_description.setFrameShape(QFrame.NoFrame)
        self.tb_book_description.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.wgt_sub_info = QWidget(SingleBookInfo)
        self.wgt_sub_info.setObjectName(u"wgt_sub_info")
        self.wgt_sub_info.setGeometry(QRect(25, 330, 686, 131))
        self.wgt_sub_info.setStyleSheet(u"")
        self.lb_book_categories_lb = QLabel(self.wgt_sub_info)
        self.lb_book_categories_lb.setObjectName(u"lb_book_categories_lb")
        self.lb_book_categories_lb.setGeometry(QRect(10, 10, 71, 21))
        font2 = QFont()
        font2.setPointSize(10)
        self.lb_book_categories_lb.setFont(font2)
        self.tb_book_categories = QTextBrowser(self.wgt_sub_info)
        self.tb_book_categories.setObjectName(u"tb_book_categories")
        self.tb_book_categories.setGeometry(QRect(90, 10, 251, 41))
        self.tb_book_categories.viewport().setProperty("cursor", QCursor(Qt.PointingHandCursor))
        self.tb_book_categories.setStyleSheet(u"background-color: rgba(0,0,0,0);\n"
"border: 0px;")
        self.tb_book_categories.setFrameShape(QFrame.NoFrame)
        self.tb_book_categories.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.tb_book_categories.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.lb_book_language_lb = QLabel(self.wgt_sub_info)
        self.lb_book_language_lb.setObjectName(u"lb_book_language_lb")
        self.lb_book_language_lb.setGeometry(QRect(10, 50, 71, 21))
        self.lb_book_language_lb.setFont(font2)
        self.lb_book_isbn_lb = QLabel(self.wgt_sub_info)
        self.lb_book_isbn_lb.setObjectName(u"lb_book_isbn_lb")
        self.lb_book_isbn_lb.setGeometry(QRect(360, 50, 71, 21))
        self.lb_book_isbn_lb.setFont(font2)
        self.lb_book_file_lb = QLabel(self.wgt_sub_info)
        self.lb_book_file_lb.setObjectName(u"lb_book_file_lb")
        self.lb_book_file_lb.setGeometry(QRect(10, 90, 71, 21))
        self.lb_book_file_lb.setFont(font2)
        self.lb_book_language_lb_2 = QLabel(self.wgt_sub_info)
        self.lb_book_language_lb_2.setObjectName(u"lb_book_language_lb_2")
        self.lb_book_language_lb_2.setGeometry(QRect(90, 50, 251, 21))
        self.lb_book_language_lb_2.setFont(font2)
        self.lb_book_isbn10 = QLabel(self.wgt_sub_info)
        self.lb_book_isbn10.setObjectName(u"lb_book_isbn10")
        self.lb_book_isbn10.setGeometry(QRect(440, 50, 151, 21))
        self.lb_book_isbn10.setFont(font2)
        self.lb_book_categories_lb_7 = QLabel(self.wgt_sub_info)
        self.lb_book_categories_lb_7.setObjectName(u"lb_book_categories_lb_7")
        self.lb_book_categories_lb_7.setGeometry(QRect(90, 90, 251, 21))
        self.lb_book_categories_lb_7.setFont(font2)
        self.lb_book_year_lb = QLabel(self.wgt_sub_info)
        self.lb_book_year_lb.setObjectName(u"lb_book_year_lb")
        self.lb_book_year_lb.setGeometry(QRect(10, 70, 71, 21))
        self.lb_book_year_lb.setFont(font2)
        self.line = QFrame(self.wgt_sub_info)
        self.line.setObjectName(u"line")
        self.line.setGeometry(QRect(350, 0, 3, 131))
        self.line.setFrameShape(QFrame.VLine)
        self.line.setFrameShadow(QFrame.Sunken)
        self.lb_book_publisher_lb = QLabel(self.wgt_sub_info)
        self.lb_book_publisher_lb.setObjectName(u"lb_book_publisher_lb")
        self.lb_book_publisher_lb.setGeometry(QRect(360, 10, 71, 21))
        self.lb_book_publisher_lb.setFont(font2)
        self.lb_book_pages_lb = QLabel(self.wgt_sub_info)
        self.lb_book_pages_lb.setObjectName(u"lb_book_pages_lb")
        self.lb_book_pages_lb.setGeometry(QRect(360, 30, 71, 21))
        self.lb_book_pages_lb.setFont(font2)
        self.lb_book_isbn13_lb = QLabel(self.wgt_sub_info)
        self.lb_book_isbn13_lb.setObjectName(u"lb_book_isbn13_lb")
        self.lb_book_isbn13_lb.setGeometry(QRect(360, 70, 71, 21))
        self.lb_book_isbn13_lb.setFont(font2)
        self.lb_book_categories_lb_8 = QLabel(self.wgt_sub_info)
        self.lb_book_categories_lb_8.setObjectName(u"lb_book_categories_lb_8")
        self.lb_book_categories_lb_8.setGeometry(QRect(360, 90, 71, 21))
        self.lb_book_categories_lb_8.setFont(font2)
        self.lb_book_isbn13 = QLabel(self.wgt_sub_info)
        self.lb_book_isbn13.setObjectName(u"lb_book_isbn13")
        self.lb_book_isbn13.setGeometry(QRect(440, 70, 151, 21))
        self.lb_book_isbn13.setFont(font2)
        self.lb_book_isbn_3 = QLabel(self.wgt_sub_info)
        self.lb_book_isbn_3.setObjectName(u"lb_book_isbn_3")
        self.lb_book_isbn_3.setGeometry(QRect(440, 90, 151, 21))
        self.lb_book_isbn_3.setFont(font2)
        self.lb_book_isbn_4 = QLabel(self.wgt_sub_info)
        self.lb_book_isbn_4.setObjectName(u"lb_book_isbn_4")
        self.lb_book_isbn_4.setGeometry(QRect(440, 30, 151, 21))
        self.lb_book_isbn_4.setFont(font2)
        self.lb_book_isbn_5 = QLabel(self.wgt_sub_info)
        self.lb_book_isbn_5.setObjectName(u"lb_book_isbn_5")
        self.lb_book_isbn_5.setGeometry(QRect(440, 10, 151, 21))
        self.lb_book_isbn_5.setFont(font2)
        self.lb_book_language_lb_3 = QLabel(self.wgt_sub_info)
        self.lb_book_language_lb_3.setObjectName(u"lb_book_language_lb_3")
        self.lb_book_language_lb_3.setGeometry(QRect(90, 70, 251, 21))
        self.lb_book_language_lb_3.setFont(font2)
        self.wgt_return_to_search = QWidget(SingleBookInfo)
        self.wgt_return_to_search.setObjectName(u"wgt_return_to_search")
        self.wgt_return_to_search.setGeometry(QRect(0, 0, 81, 21))
        self.wgt_return_to_search.setCursor(QCursor(Qt.PointingHandCursor))
        self.wgt_return_to_search.setStyleSheet(u"background: #ADD8E6;\n"
"border-bottom-right-radius: 5px; \n"
"border-top-right-radius: 5px; ")
        self.lb_return_to_search = QLabel(self.wgt_return_to_search)
        self.lb_return_to_search.setObjectName(u"lb_return_to_search")
        self.lb_return_to_search.setGeometry(QRect(30, 0, 21, 21))
        self.lb_return_to_search.setPixmap(QPixmap(u":/:/res/image/return.png"))
        self.lb_return_to_search.setScaledContents(True)

        self.retranslateUi(SingleBookInfo)

        QMetaObject.connectSlotsByName(SingleBookInfo)
    # setupUi

    def retranslateUi(self, SingleBookInfo):
        SingleBookInfo.setWindowTitle(QCoreApplication.translate("SingleBookInfo", u"Form", None))
        self.lb_book_cover.setText("")
        self.lb_book_title_icon.setText("")
        self.tb_book_title.setHtml(QCoreApplication.translate("SingleBookInfo", u"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">title</p></body></html>", None))
        self.tb_book_authors.setHtml(QCoreApplication.translate("SingleBookInfo", u"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-style:italic;\">authors</span></p></body></html>", None))
        self.lb_book_authors_icon.setText("")
        self.lb_book_rating_icon.setText("")
        self.lb_book_rating.setText(QCoreApplication.translate("SingleBookInfo", u"5.0/5.0", None))
        self.lb_book_like_icon.setText("")
        self.lb_book_bookmark_icon.setText("")
        self.tb_book_description.setHtml(QCoreApplication.translate("SingleBookInfo", u"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Stylus BT'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Descrip"
                        "tion</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Description</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p></body></html>", None))
        self.lb_book_categories_lb.setText(QCoreApplication.translate("SingleBookInfo", u"Categories:", None))
        self.tb_book_categories.setHtml(QCoreApplication.translate("SingleBookInfo", u"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-style:italic; text-decoration: underline;\">SCdwaddddddddddddddddddddddddddddddddddddddddddd</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; font-style:italic; text-decoration: underline;\"><br /></p></body></html>", None))
        self.lb_book_language_lb.setText(QCoreApplication.translate("SingleBookInfo", u"Language:", None))
        self.lb_book_isbn_lb.setText(QCoreApplication.translate("SingleBookInfo", u"ISBN 10:", None))
        self.lb_book_file_lb.setText(QCoreApplication.translate("SingleBookInfo", u"File:", None))
        self.lb_book_language_lb_2.setText(QCoreApplication.translate("SingleBookInfo", u"English", None))
        self.lb_book_isbn10.setText(QCoreApplication.translate("SingleBookInfo", u"1440567670", None))
        self.lb_book_categories_lb_7.setText(QCoreApplication.translate("SingleBookInfo", u"EPUB, 4.29MB", None))
        self.lb_book_year_lb.setText(QCoreApplication.translate("SingleBookInfo", u"Year:", None))
        self.lb_book_publisher_lb.setText(QCoreApplication.translate("SingleBookInfo", u"Publisher:", None))
        self.lb_book_pages_lb.setText(QCoreApplication.translate("SingleBookInfo", u"Pages:", None))
        self.lb_book_isbn13_lb.setText(QCoreApplication.translate("SingleBookInfo", u"ISBN 13:", None))
        self.lb_book_categories_lb_8.setText(QCoreApplication.translate("SingleBookInfo", u"IPFS", None))
        self.lb_book_isbn13.setText(QCoreApplication.translate("SingleBookInfo", u"9781440567674", None))
        self.lb_book_isbn_3.setText(QCoreApplication.translate("SingleBookInfo", u"CID, CID Blake2b", None))
        self.lb_book_isbn_4.setText(QCoreApplication.translate("SingleBookInfo", u"288", None))
        self.lb_book_isbn_5.setText(QCoreApplication.translate("SingleBookInfo", u"Adams Media", None))
        self.lb_book_language_lb_3.setText(QCoreApplication.translate("SingleBookInfo", u"2013", None))
        self.lb_return_to_search.setText("")
    # retranslateUi

