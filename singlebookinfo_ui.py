# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'singlebookinfo.ui'
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
from PySide6.QtWidgets import (QApplication, QFrame, QLabel, QScrollArea,
    QSizePolicy, QTextBrowser, QWidget)
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
        self.lb_book_cover.setCursor(QCursor(Qt.PointingHandCursor))
        self.lb_book_cover.setStyleSheet(u"")
        self.lb_book_cover.setScaledContents(True)
        self.wgt_main_info = QWidget(SingleBookInfo)
        self.wgt_main_info.setObjectName(u"wgt_main_info")
        self.wgt_main_info.setGeometry(QRect(260, 40, 461, 111))
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
        self.wgt_book_description.setGeometry(QRect(260, 170, 461, 131))
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
        self.wgt_sub_info.setGeometry(QRect(25, 330, 696, 131))
        self.wgt_sub_info.setStyleSheet(u"")
        self.sa_singlebookinfo_sub_info = QScrollArea(self.wgt_sub_info)
        self.sa_singlebookinfo_sub_info.setObjectName(u"sa_singlebookinfo_sub_info")
        self.sa_singlebookinfo_sub_info.setGeometry(QRect(0, 0, 696, 131))
        self.sa_singlebookinfo_sub_info.setFrameShape(QFrame.NoFrame)
        self.sa_singlebookinfo_sub_info.setFrameShadow(QFrame.Plain)
        self.sa_singlebookinfo_sub_info.setWidgetResizable(True)
        self.scrollAreaWidgetContents = QWidget()
        self.scrollAreaWidgetContents.setObjectName(u"scrollAreaWidgetContents")
        self.scrollAreaWidgetContents.setGeometry(QRect(0, 0, 696, 131))
        self.sa_singlebookinfo_sub_info.setWidget(self.scrollAreaWidgetContents)
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
        self.lb_return_to_search.setText("")
    # retranslateUi

