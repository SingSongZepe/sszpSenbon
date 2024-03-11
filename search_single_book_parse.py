
from bs4 import BeautifulSoup as bs
from book_full_info import BookFullInfo

print("Hello World!")
print('SingSongZepe search single book Parser!')

SECTION_VALUE_DEFAULT = 'unknown' # maybe just set as ''
COVER_ = 'cover'
URL_ = 'url'
TITLE_ = 'title'
AUTHORS_ = 'authors'
RATING_ = 'rating'
DESCRIPTION_ = 'description'
CATEGORIES_ = 'categories'
EDITION_ = 'edition'
LANGUAGE_ = 'language'
ISBN_ = 'isbn'
ISBN10_ = 'isbn10'
ISBN13_ = 'isbn13'
FILE_ = 'file'
VOLUME_ = 'volume'
YEAR_ = 'year'
PUBLISHER_ = 'publisher'
PAGES_ = 'pages'
SERIES_ = 'series'
IPFS_ = 'ipfs'


def search_single_book_parse(data) -> str:
    soup = bs(data, 'html.parser')

    # cover
    img_with_cover = soup.select_one('z-cover img')
    cover = img_with_cover['data-src'] if img_with_cover and img_with_cover.has_attr('data-src') else SECTION_VALUE_DEFAULT
    # print(COVER_, cover)

    # authors and title
    z_cover_with_authors_title = soup.select_one('z-cover')
    authors = z_cover_with_authors_title['author'] if z_cover_with_authors_title and z_cover_with_authors_title.has_attr('author') else SECTION_VALUE_DEFAULT
    # print(AUTHORS_, authors)

    title = z_cover_with_authors_title['title'] if z_cover_with_authors_title and z_cover_with_authors_title.has_attr('title') else SECTION_VALUE_DEFAULT
    # print(TITLE_, title)

    # rating
    div_with_rating = soup.select_one('div.book-rating')
    span_with_interest_rating = div_with_rating.select_one('span.book-rating-interest-score') 
    span_with_quality_rating = div_with_rating.select_one('span.book-rating-quality-score')
    rating = span_with_interest_rating.text.strip() + '/' + span_with_quality_rating.text.strip()
    # print(RATING_, rating)
    
    # options
    # description (it's optional, but not in details box)
    div_with_description = soup.select_one('div#bookDescriptionBox')
    description = div_with_description.text.strip() if div_with_description else SECTION_VALUE_DEFAULT
    # print(DESCRIPTION_, description)

    div_details_box = soup.select_one('div.bookDetailsBox')
    # property_categories
    a_with_categories = div_details_box.select_one('div.property_categories div.property_value a')
    categories = a_with_categories.text if a_with_categories else SECTION_VALUE_DEFAULT
    # print(CATEGORIES_, categories)

    # property_publisher
    div_with_publisher = div_details_box.select_one('div.property_publisher div.property_value')
    publisher = div_with_publisher.text if div_with_publisher else SECTION_VALUE_DEFAULT
    # print(PUBLISHER_, publisher)

    # property_year
    div_with_year = div_details_box.select_one('div.property_year div.property_value')
    year = div_with_year.text if div_with_year else SECTION_VALUE_DEFAULT
    # print(YEAR_, year)

    # property_language
    div_with_language = div_details_box.select_one('div.property_language div.property_value')
    language = div_with_language.text if div_with_language else SECTION_VALUE_DEFAULT
    # print(LANGUAGE_, language)

    # property__file
    div_with_file = div_details_box.select_one('div.property__file div.property_value')
    file = div_with_file.text if div_with_file else SECTION_VALUE_DEFAULT
    # print(FILE_, file)
    
    # property_ipfs_cid
    div_with_ipfs = div_details_box.select_one('div.property_ipfs_cid div.property_value')
    ipfs = div_with_ipfs.text.strip() if div_with_ipfs else SECTION_VALUE_DEFAULT
    # print(IPFS_, ipfs)

    # property_pages
    div_with_pages = div_details_box.select_one('div.property_pages div.property_value')
    pages = div_with_pages.text.strip() if div_with_pages else SECTION_VALUE_DEFAULT
    # print(PAGES_, pages)

    # property_isbn 10
    div_with_isbn10 = div_details_box.select_one('div[class~="10"].property_isbn div.property_value')
    isbn10 = div_with_isbn10.text if div_with_isbn10 else SECTION_VALUE_DEFAULT
    # print(ISBN10_, isbn10)

    # property_isbn 13
    div_with_isbn13 = div_details_box.select_one('div[class~="13"].property_isbn div.property_value')
    isbn13 = div_with_isbn13.text if div_with_isbn13 else SECTION_VALUE_DEFAULT
    # print(ISBN13_, isbn13)

    # property_isbn
    div_with_isbn = div_details_box.select_one('div:not([class~="10"], [class~="13"]).property_isbn div.property_value')
    isbn = div_with_isbn.text if div_with_isbn else SECTION_VALUE_DEFAULT
    # print(ISBN_, isbn)

    # property_volume
    div_with_volume = div_details_box.select_one('div.property_volume div.property_value')
    volume = div_with_volume.text if div_with_volume else SECTION_VALUE_DEFAULT
    # print(VOLUME_, volume)

    # property_edition
    div_with_edition = div_details_box.select_one('div.property_edition div.property_value')
    edition = div_with_edition.text if div_with_edition else SECTION_VALUE_DEFAULT
    # print(EDITION_, edition)

    # property_series
    div_with_series = div_details_box.select_one('div.property_series div.property_value')
    series = div_with_series.text if div_with_series else SECTION_VALUE_DEFAULT
    # print(SERIES_, series)
    
    # init book_full_info
    book_full_info = BookFullInfo(
        cover=cover,
        url=URL_,
        title=title,
        authors=authors,
        rating=rating,
        description=description,
        categories=categories,
        edition=edition,
        language=language,
        isbn=isbn,
        isbn10=isbn10,
        isbn13=isbn13,
        file=file,
        volume=volume,
        year=year,
        publisher=publisher,
        pages=pages,
        series=series,
        ipfs=ipfs
    )
    return book_full_info.transform_2json_str()

# 
if __name__ == '__main__':
    pass
    data = '''
<div itemscope="" itemtype="http://schema.org/Book">
    <div class="row cardBooks" data-spelling-suggest="true" data-book_id="13858830">
        <div class="col-sm-3 details-book-cover-container">
            <z-cover naturalratio="" volume="" markbutton="" id="13858830" isbn="" author="南派三叔 [南派三叔]" title="盗墓笔记：沙海系列1-4">
                <img data-src="https://s3proxy.cdn-zlib.se/covers300/collections/userbooks/3b3c9446f9a3159a36cd354bef43a5b7a114c0edb5a57c94d3293dd95a5f2ec9.jpg">
            </z-cover>
        </div>

        <div class="col-sm-9">
            <h1 itemprop="name" style="color: #000; line-height: 140%;">
                盗墓笔记：沙海系列1-4            </h1>

            <i><a itemprop="author" class="color1" title="找到作者的所有书籍" href="/author/%E5%8D%97%E6%B4%BE%E4%B8%89%E5%8F%94 %5B%E5%8D%97%E6%B4%BE%E4%B8%89%E5%8F%94%5D">南派三叔 [南派三叔]</a></i>

            
    <div class="book-rating-detail">
        <div class="book-rating ">
            <span class="book-rating-interest-score ">
                5.0            </span> /
            <span class="book-rating-quality-score ">
                5.0            </span>
        </div>
        <a href="#post" class="book-comments-info js-anchor">
            2 comments        </a>
        <div class="bookmarks" style="display: none" data-book_id="13858830">
            
        <i class="icon-heart btn-save-for-later" title="标记你最喜欢或计划以后下载的书籍"></i>
        <i class="icon-bookmark btn-booklists" title="将这本书加入你的个人主题收藏，并与你的社区分享它"></i>
                        </div>
    </div>

<div class="book-choice-rating" data-visible="0" data-init="0">
    <div class="overlay-post-score"><div id="bookChoiceRatingtFloatingSpinner"></div></div>
    <div class="overlay"><div id="bookChoiceRatingSpinner"></div></div>
    <div class="book-choice-interest-title">你有多喜欢这本书？</div>
    <div class="book-choice-interest-stars stars-list cursor-pointer" data-disabled="0" data-id="13858830" data-type="interest">
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
    </div>

    <div class="book-choice-quality-stub">
        <div class="book-choice-quality-title">下载文件的质量如何？</div>
        <div class="book-choice-quality-dmsg">下载该书，以评价其质量</div>
    </div>

    <div class="book-choice-quality-title">
        <div>下载文件的质量如何？</div>
    </div>
    <div class="book-quality-rating-template">
        <div class="book-format-quality-rating">
            <div class="format-info">
                <span class="download-date"></span>
                <span class="extension book-property__extension"></span>
                <span class="size"></span>
            </div>
            <div class="book-choice-quality-stars stars-list cursor-pointer" data-disabled="0" data-id="" data-type="quality">
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Text is unreadable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Barely readable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Readable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Good"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Perfect"></i>
            </div>
        </div>
    </div>
</div>      

<div class="bookDetailsBox">
                <div class="bookProperty property_categories">
                    <div class="property_label">种类:</div>
            <div class="property_value "><a href="/category/261/Fiction-Adventure-Stories--Action">Fiction - Adventure Stories &amp; Action</a></div></div>
                <div class="bookProperty property_publisher">
                    <div class="property_label">出版社:</div>
            <div class="property_value ">Hello World</div></div>
                <div class="bookProperty property_language">
                    <div class="property_label">语言:</div>
            <div class="property_value text-capitalize">chinese</div></div>
                <div class="bookProperty property__file">
                    <div class="property_label">文件:</div>
            <div class="property_value ">EPUB, 863 KB</div></div>
                <div style="display: none;" class="bookProperty property_user_tags">
                    <div class="property_label">您的标签:</div>
            <div class="property_value "></div></div>
                    <div class="bookProperty property_ipfs_cid">
                        <div class="property_label">IPFS:</div>
                        <div class="property_value"><span class="z-copy-icon tooltip-init" data-placement="bottom" title="复制" data-copy="QmNqqMj1dRCXEHxECu4ZayzniHvLfRvtiTp38gMjNSJJEc" data-notif="CID 复制到剪贴板">CID</span> , <span class="z-copy-icon tooltip-init" data-placement="bottom" title="复制" data-copy="bafykbzacedihrwyodbx2o3didekcfruth6hkwt56uoyuc7mhlrkmdvtr53jdy" data-notif="CID 复制到剪贴板">CID Blake2b</span></div>
                    </div>          
                <div class="bookProperty property_language_year">chinese0</div></div>            </div>
        </div>
    </div>

    <section class="book-actions-container">
    <div class="details-buttons-container">
            <div class="book-actions-buttons">        
    
<div class="book-details-button">
    <div class="btn-group" id="sendToButtonBox">
        <button type="button" class="btn btn-default dropdown-toggle button-send-book" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            发送到            <span class="sendToButtonBox__icons">
                <i class="zlibicon-envelope menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-google-drive menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-Pocketbook menu-row__icon" style="position: relative;top: 2px;font-size: 16px;"></i><i class="zlibicon-Amazon menu-row__icon" style="position: relative;top: 4px;font-size: 16px;"></i>            </span>
            <span class="caret"></span>
        </button>
            </div>
</div>

    </div>
                    </div>
        <div class="book-actions-status">
<div class="cBox1" id="sentToEmailInfo" style="display:none;">
    在1-5分钟内，文件将被发送到您的电子邮件。</div>

<div class="cBox1" id="sentToTelegramInfo" style="display:none;">
    <p>该文件将通过电报信使发送给您。 您最多可能需要 1-5 分钟才能收到它。</p>
    <p>注意：确保您已将您的帐户链接到 Z-Library Telegram 机器人。</p>
</div>

<div class="cBox1" id="sentToEmailInfoKindle" style="display:none;">
    <p>该文件将发送到您的 Kindle 帐户。 您最多可能需要 1-5 分钟才能收到它。</p>
    <p><b>请注意</b>：您需要验证要发送到Kindle的每本书。检查您的邮箱中是否有来自亚马逊Kindle的验证电子邮件。</p>
</div>

<div class="cBox1" id="sendToGoogleDriveMessage" style="display:none; position: relative;"></div>

<div class="cBox1Danger" id="errorMessage" style="display:none;">
    </div>

<div id="converterCurrentStatusesBoxContainer">
    <div id="converterCurrentStatusesBox">
            </div>
</div>
<div id="convertationStatusTemplates">
    <div class="status-new" data-job_id=""><div class="spinner-content"></div><div class="message">正在转换 <b class="book-property__extension"></b></div></div>    <div class="status-error"><span class="zlibicon-close-circle status-icon"></span><div class="message">转换为 <b class="book-property__extension"></b> 失败</div><span class="zlibicon-cross icon-hovered delete-btn" data-job_id=""></span></div></div>
<div id="shareToTooltipsContainer"></div>
</div>
        <div class="bookLoginBlock__wrapper">
    <div class="bookLoginBlock__container">
        <p class="bookLoginBlock__caption" "="">开启自己的知识世界之旅！                 </p>
        <div class="bookLoginBlock__buttons">
            <button class="bookLoginBlock__button bookLoginBlock__button_primary authButton" data-action="login">登录</button>
        </div>
    </div>
</div>

</div></section>

</div>
'''
    data_philosophy101 = '''
<div style="padding:10px 0; font-size:10pt" id="bookDescriptionBox" itemprop="reviewBody">
                    Discover the world's greatest thinkers and their groundbreaking notions! Too often, textbooks turn the noteworthy theories, principles, and figures of philosophy into tedious discourse that even Plato would reject. Philosophy 101 cuts out the boring details and exhausting philosophical methodology, and instead, gives you a lesson in philosophy that keeps you engaged as you explore the fascinating history of human thought and inquisition. From Aristotle and Heidegger to free will and metaphysics, Philosophy 101 is packed with hundreds of entertaining philosophical tidbits, illustrations, and thought puzzles that you won't be able to find anywhere else. So whether you're looking to unravel the mysteries of existentialism, or just want to find out what made Voltaire tick, Philosophy 101 has all the answers--even the ones you didn't know you were looking for.                </div>
<div itemscope="" itemtype="http://schema.org/Book">
    <div class="row cardBooks" data-spelling-suggest="true" data-book_id="2283293">
        <div class="col-sm-3 details-book-cover-container">
            <z-cover naturalratio="" volume="" markbutton="" id="2283293" isbn="9781440567674,1440567670" author="Paul Kleinman" title="Philosophy 101">
                <img data-src="https://s3proxy.cdn-zlib.se/covers300/collections/genesis/dce204597722b47c83033f8ca0e743fccdacdc5541e95025490d63b05e76724b.jpg">
            </z-cover>
        </div>

        <div class="col-sm-9">
            <h1 itemprop="name" style="color: #000; line-height: 140%;">
                Philosophy 101            </h1>

            <i><a itemprop="author" class="color1" title="找到作者的所有书籍" href="/author/Paul Kleinman">Paul Kleinman</a></i>

            
    <div class="book-rating-detail">
        <div class="book-rating ">
            <span class="book-rating-interest-score ">
                5.0            </span> /
            <span class="book-rating-quality-score ">
                5.0            </span>
        </div>
        <a href="#post" class="book-comments-info js-anchor">
            9 comments        </a>
        <div class="bookmarks" style="display: none" data-book_id="2283293">
            
        <i class="icon-heart btn-save-for-later" title="标记你最喜欢或计划以后下载的书籍"></i>
        <i class="icon-bookmark btn-booklists" title="将这本书加入你的个人主题收藏，并与你的社区分享它"></i>
                        </div>
    </div>

<div class="book-choice-rating" data-visible="0" data-init="0">
    <div class="overlay-post-score"><div id="bookChoiceRatingtFloatingSpinner"></div></div>
    <div class="overlay"><div id="bookChoiceRatingSpinner"></div></div>
    <div class="book-choice-interest-title">你有多喜欢这本书？</div>
    <div class="book-choice-interest-stars stars-list cursor-pointer" data-disabled="0" data-id="2283293" data-type="interest">
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
    </div>

    <div class="book-choice-quality-stub">
        <div class="book-choice-quality-title">下载文件的质量如何？</div>
        <div class="book-choice-quality-dmsg">下载该书，以评价其质量</div>
    </div>

    <div class="book-choice-quality-title">
        <div>下载文件的质量如何？</div>
    </div>
    <div class="book-quality-rating-template">
        <div class="book-format-quality-rating">
            <div class="format-info">
                <span class="download-date"></span>
                <span class="extension book-property__extension"></span>
                <span class="size"></span>
            </div>
            <div class="book-choice-quality-stars stars-list cursor-pointer" data-disabled="0" data-id="" data-type="quality">
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Text is unreadable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Barely readable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Readable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Good"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Perfect"></i>
            </div>
        </div>
    </div>
</div>
                            <div style="padding:10px 0; font-size:10pt" id="bookDescriptionBox" itemprop="reviewBody">
                    Discover the world's greatest thinkers and their groundbreaking notions! Too often, textbooks turn the noteworthy theories, principles, and figures of philosophy into tedious discourse that even Plato would reject. Philosophy 101 cuts out the boring details and exhausting philosophical methodology, and instead, gives you a lesson in philosophy that keeps you engaged as you explore the fascinating history of human thought and inquisition. From Aristotle and Heidegger to free will and metaphysics, Philosophy 101 is packed with hundreds of entertaining philosophical tidbits, illustrations, and thought puzzles that you won't be able to find anywhere else. So whether you're looking to unravel the mysteries of existentialism, or just want to find out what made Voltaire tick, Philosophy 101 has all the answers--even the ones you didn't know you were looking for.                </div>
                        <div style="zoom: 1; margin-top: 30px;">
                

<div class="bookDetailsBox">
                <div class="bookProperty property_categories">
                    <div class="property_label">种类:</div>
            <div class="property_value "><a href="/category/614/Society-Politics--Philosophy-General--Miscellaneous-Philosophy">Society, Politics &amp; Philosophy - General &amp; Miscellaneous Philosophy</a></div></div>
                <div class="bookProperty property_year">
                    <div class="property_label">年:</div>
            <div class="property_value ">2013</div></div>
                <div class="bookProperty property_publisher">
                    <div class="property_label">出版社:</div>
            <div class="property_value ">Adams Media</div></div>
                <div class="bookProperty property_language">
                    <div class="property_label">语言:</div>
            <div class="property_value text-capitalize">english</div></div>
                <div class="bookProperty property_pages">
                    <div class="property_label">页:</div>
            <div class="property_value "><span title="Pages paperback">288</span></div></div>
                <div class="bookProperty property_isbn 10">
                    <div class="property_label">ISBN 10:</div>
            <div class="property_value ">1440567670</div></div>
                <div class="bookProperty property_isbn 13">
                    <div class="property_label">ISBN 13:</div>
            <div class="property_value ">9781440567674</div></div>
                <div class="bookProperty property__file">
                    <div class="property_label">文件:</div>
            <div class="property_value ">EPUB, 4.29 MB</div></div>
                <div style="display: none;" class="bookProperty property_user_tags">
                    <div class="property_label">您的标签:</div>
            <div class="property_value "></div></div>
                    <div class="bookProperty property_ipfs_cid">
                        <div class="property_label">IPFS:</div>
                        <div class="property_value"><span class="z-copy-icon tooltip-init" data-placement="bottom" title="复制" data-copy="QmfUT6DGADpyv9L2UL1VN18vEPciZyAe58SjKtFPK2Vkxo" data-notif="CID 复制到剪贴板">CID</span> , <span class="z-copy-icon tooltip-init" data-placement="bottom" title="复制" data-copy="bafykbzacedetkesb2qcmedw2qslvn6vcjvbjwt7phjelohkw27rqlwb4mdgny" data-notif="CID 复制到剪贴板">CID Blake2b</span></div>
                    </div>          
                <div class="bookProperty property_language_year">english, 2013</div></div>            </div>
        </div>
    </div>

    <section class="book-actions-container">
    <div class="details-buttons-container">
            <div class="book-actions-buttons">        
    
<div class="book-details-button">
    <div class="btn-group" id="sendToButtonBox">
        <button type="button" class="btn btn-default dropdown-toggle button-send-book" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            发送到            <span class="sendToButtonBox__icons">
                <i class="zlibicon-envelope menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-google-drive menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-Pocketbook menu-row__icon" style="position: relative;top: 2px;font-size: 16px;"></i><i class="zlibicon-Amazon menu-row__icon" style="position: relative;top: 4px;font-size: 16px;"></i>            </span>
            <span class="caret"></span>
        </button>
            </div>
</div>

   <div class="details-buttons-container__divider"></div>
    <div class="book-details-button">
        <div class="btn-group">
            <button type="button" class="btn btn-default dropdown-toggle button-paperback" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                平装 <span class="caret"></span>
            </button>
            <ul class="dropdown-menu">
                <div class="menu-content menu-content_paperback">
                                            <div class="menu-row">
                            <a class="menu__link_paperback" href="https://amazon.com/s?k=Philosophy+101 Paul+Kleinman" target="_blank">
                                <img class="menu__icon" src="/img/book-stores/amazon_grayscale.svg">
                                Amazon                            </a>
                        </div>
                                            <div class="menu-row">
                            <a class="menu__link_paperback" href="https://www.barnesandnoble.com/s/Philosophy+101 Paul+Kleinman" target="_blank">
                                <img class="menu__icon" src="/img/book-stores/barnes_noble_grayscale.svg">
                                Barnes &amp; Noble                            </a>
                        </div>
                                            <div class="menu-row">
                            <a class="menu__link_paperback" href="https://bookshop.org/search?keywords=Philosophy+101 Paul+Kleinman" target="_blank">
                                <img class="menu__icon" src="/img/book-stores/bookshoporg_grayscale.svg">
                                Bookshop.org                            </a>
                        </div>
                    
                    <div class="text--hint">
                        想添加您的书店？ 通过 <a href="mailto:support@z-lib.se">support@z-lib.se</a> 与我们联系                    </div>
                </div>
            </ul>
        </div>
    </div>
                    </div>
        <div class="book-actions-status">
<div class="cBox1" id="sentToEmailInfo" style="display:none;">
    在1-5分钟内，文件将被发送到您的电子邮件。</div>

<div class="cBox1" id="sentToTelegramInfo" style="display:none;">
    <p>该文件将通过电报信使发送给您。 您最多可能需要 1-5 分钟才能收到它。</p>
    <p>注意：确保您已将您的帐户链接到 Z-Library Telegram 机器人。</p>
</div>

<div class="cBox1" id="sentToEmailInfoKindle" style="display:none;">
    <p>该文件将发送到您的 Kindle 帐户。 您最多可能需要 1-5 分钟才能收到它。</p>
    <p><b>请注意</b>：您需要验证要发送到Kindle的每本书。检查您的邮箱中是否有来自亚马逊Kindle的验证电子邮件。</p>
</div>

<div class="cBox1" id="sendToGoogleDriveMessage" style="display:none; position: relative;"></div>

<div class="cBox1Danger" id="errorMessage" style="display:none;">
    </div>

<div id="converterCurrentStatusesBoxContainer">
    <div id="converterCurrentStatusesBox">
            </div>
</div>
<div id="convertationStatusTemplates">
    <div class="status-new" data-job_id=""><div class="spinner-content"></div><div class="message">正在转换 <b class="book-property__extension"></b></div></div>    <div class="status-error"><span class="zlibicon-close-circle status-icon"></span><div class="message">转换为 <b class="book-property__extension"></b> 失败</div><span class="zlibicon-cross icon-hovered delete-btn" data-job_id=""></span></div></div>
<div id="shareToTooltipsContainer"></div>
</div>
        <div class="bookLoginBlock__wrapper">
    <div class="bookLoginBlock__container">
        <p class="bookLoginBlock__caption" "="">开启自己的知识世界之旅！                 </p>
        <div class="bookLoginBlock__buttons">
            <button class="bookLoginBlock__button bookLoginBlock__button_primary authButton" data-action="login">登录</button>
        </div>
    </div>
</div>


  </div></section>

</div>
'''
    data_business_vocabulary = '''
<div itemscope="" itemtype="http://schema.org/Book">
    <div class="row cardBooks" data-spelling-suggest="true" data-book_id="5496142">
        <div class="col-sm-3 details-book-cover-container">
            <z-cover naturalratio="" volume="" markbutton="" id="5496142" isbn="97805211225041,97805211282851,97813166299701,97813166299871,05211225031,05211282851,131662997X1,13166299881" author="Bill Mascull" title="Business Vocabulary in Use: Intermediate, 3rd Edition">
                <img data-src="https://s3proxy.cdn-zlib.se/covers300/collections/genesis/4a68d5b0e5473673687f8a79afe8e1c1e2c995ccc70992b4d35a5d51d895d5fd.jpg">
            </z-cover>
        </div>

        <div class="col-sm-9">
            <h1 itemprop="name" style="color: #000; line-height: 140%;">
                Business Vocabulary in Use: Intermediate, 3rd Edition            </h1>

            <i><a itemprop="author" class="color1" title="Find all the author's book" href="/author/Bill Mascull">Bill Mascull</a></i>

            
    <div class="book-rating-detail">
        <div class="book-rating ">
            <span class="book-rating-interest-score ">
                5.0            </span> /
            <span class="book-rating-quality-score ">
                5.0            </span>
        </div>
        <a href="#post" class="book-comments-info js-anchor">
            16 comments        </a>
        <div class="bookmarks" style="display: none" data-book_id="5496142">
            
        <i class="icon-heart btn-save-for-later" title="Mark the book you like best or plan to download later"></i>
        <i class="icon-bookmark btn-booklists" title="Add the book to your personal themed book collection and share it with your community"></i>
                        </div>
    </div>

<div class="book-choice-rating" data-visible="0" data-init="0">
    <div class="overlay-post-score"><div id="bookChoiceRatingtFloatingSpinner"></div></div>
    <div class="overlay"><div id="bookChoiceRatingSpinner"></div></div>
    <div class="book-choice-interest-title">How much do you like this book?</div>
    <div class="book-choice-interest-stars stars-list cursor-pointer" data-disabled="0" data-id="5496142" data-type="interest">
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
        <i class="book-rating-star"></i>
    </div>

    <div class="book-choice-quality-stub">
        <div class="book-choice-quality-title">What’s the quality of the file?</div>
        <div class="book-choice-quality-dmsg">Download the book for quality assessment</div>
    </div>

    <div class="book-choice-quality-title">
        <div>What’s the quality of the downloaded files?</div>
    </div>
    <div class="book-quality-rating-template">
        <div class="book-format-quality-rating">
            <div class="format-info">
                <span class="download-date"></span>
                <span class="extension book-property__extension"></span>
                <span class="size"></span>
            </div>
            <div class="book-choice-quality-stars stars-list cursor-pointer" data-disabled="0" data-id="" data-type="quality">
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Text is unreadable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Barely readable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Readable"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Good"></i>
                <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Perfect"></i>
            </div>
        </div>
    </div>
</div>

                            <div style="padding:10px 0; font-size:10pt" id="bookDescriptionBox" itemprop="reviewBody">
                    The words you need to communicate with confidence in business today.&nbsp; Vocabulary explanations and practice for intermediate (B1 to B2) students and professionals looking to improve their knowledge and use of business English. This book is perfect for both self-study and classroom activities. Inside the book is a code for an ebook that can be used online with Macs, PCs and tablets. It can also be downloaded to iOS and Android tablets using the free Cambridge Bookshelf app. The ebook has the same content as the printed book, plus features such as audio so that you can listen to the words as well as reading them.                </div>
                        <div style="zoom: 1; margin-top: 30px;">
                

<div class="bookDetailsBox">
                <div class="bookProperty property_categories">
                    <div class="property_label">Categories:</div>
            <div class="property_value "><a href="/category/377/Languages-English-as-a-Foreign-Language--Reference">Languages - English as a Foreign Language &amp; Reference</a></div></div>
                <div class="bookProperty property_volume">
                    <div class="property_label">Volume:</div>
            <div class="property_value ">00</div></div>
                <div class="bookProperty property_year">
                    <div class="property_label">Year:</div>
            <div class="property_value ">2017</div></div>
                <div class="bookProperty property_edition">
                    <div class="property_label">Edition:</div>
            <div class="property_value ">kindle</div></div>
                <div class="bookProperty property_publisher">
                    <div class="property_label">Publisher:</div>
            <div class="property_value ">Cambridge University Press</div></div>
                <div class="bookProperty property_language">
                    <div class="property_label">Language:</div>
            <div class="property_value text-capitalize">english</div></div>
                <div class="bookProperty property_pages">
                    <div class="property_label">Pages:</div>
            <div class="property_value "><span title="Pages paperback">175</span></div></div>
                <div class="bookProperty property_isbn">
                    <div class="property_label">ISBN:</div>
            <div class="property_value ">13166299881</div></div>
                <div class="bookProperty property_series">
                    <div class="property_label">Series:</div>
            <div class="property_value ">Intermediate</div></div>
                <div class="bookProperty property__file">
                    <div class="property_label">File:</div>
            <div class="property_value ">PDF, 11.39 MB</div></div>
                <div style="display: none;" class="bookProperty property_user_tags">
                    <div class="property_label">Your tags:</div>
            <div class="property_value "></div></div>
                    <div class="bookProperty property_ipfs_cid">
                        <div class="property_label">IPFS:</div>
                        <div class="property_value"><span class="z-copy-icon tooltip-init" data-placement="bottom" title="Copy" data-copy="QmSjnbxgGVTQ1iPi52oj2UZnpX5FXspuBaggJfWQjq3uSw" data-notif="CID copied to clipboard">CID</span> , <span class="z-copy-icon tooltip-init" data-placement="bottom" title="Copy" data-copy="bafykbzacecoonxpeo3kx2hgl5w2be3py65qikdlpnmwjriecm6gdgevgc63is" data-notif="CID copied to clipboard">CID Blake2b</span></div>
                    </div>          
                <div class="bookProperty property_language_year">english, 2017</div></div>            </div>
        </div>
    </div>

    <section class="book-actions-container">
    <div class="details-buttons-container">
            <div class="book-actions-buttons">        
    
<div class="book-details-button">
    <div class="btn-group" id="sendToButtonBox">
        <button type="button" class="btn btn-default dropdown-toggle button-send-book" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Send to            <span class="sendToButtonBox__icons">
                <i class="zlibicon-envelope menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-google-drive menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-Pocketbook menu-row__icon" style="position: relative;top: 2px;font-size: 16px;"></i><i class="zlibicon-Amazon menu-row__icon" style="position: relative;top: 4px;font-size: 16px;"></i>            </span>
            <span class="caret"></span>
        </button>
            </div>
</div>
  <div class="details-buttons-container__divider"></div>
    <div class="book-details-button">
        <div class="btn-group">
            <button type="button" class="btn btn-default dropdown-toggle button-paperback" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                Paperback <span class="caret"></span>
            </button>
            <ul class="dropdown-menu">
                <div class="menu-content menu-content_paperback">
                                            <div class="menu-row">
                            <a class="menu__link_paperback" href="https://amazon.com/s?k=Business+Vocabulary+in+Use%3A+Intermediate%2C+3rd+Edition Bill+Mascull" target="_blank">
                                <img class="menu__icon" src="/img/book-stores/amazon_grayscale.svg">
                                Amazon                            </a>
                        </div>
                                            <div class="menu-row">
                            <a class="menu__link_paperback" href="https://www.barnesandnoble.com/s/Business+Vocabulary+in+Use%3A+Intermediate%2C+3rd+Edition Bill+Mascull" target="_blank">
                                <img class="menu__icon" src="/img/book-stores/barnes_noble_grayscale.svg">
                                Barnes &amp; Noble                            </a>
                        </div>
                                            <div class="menu-row">
                            <a class="menu__link_paperback" href="https://bookshop.org/search?keywords=Business+Vocabulary+in+Use%3A+Intermediate%2C+3rd+Edition Bill+Mascull" target="_blank">
                                <img class="menu__icon" src="/img/book-stores/bookshoporg_grayscale.svg">
                                Bookshop.org                            </a>
                        </div>
                    
                    <div class="text--hint">
                        Want to add your book store? Contact us at <a href="mailto:support@z-lib.se">support@z-lib.se</a>                    </div>
                </div>
            </ul>
        </div>
    </div>
                    </div>
        <div class="book-actions-status">
<div class="cBox1" id="sentToEmailInfo" style="display:none;">
    The file will be sent to your email address. It may take up to 1-5 minutes before you receive it.</div>

<div class="cBox1" id="sentToTelegramInfo" style="display:none;">
    <p>The file will be sent to you via the Telegram messenger. It may take up to 1-5 minutes before you receive it.</p>
    <p>Note: Make sure you have linked your account to Z-Library Telegram bot.</p>
</div>

<div class="cBox1" id="sentToEmailInfoKindle" style="display:none;">
    <p>The file will be sent to your Kindle account. It may take up to 1–5 minutes before you receive it.</p>
    <p><b>Please note</b>: you need to verify every book you want to send to your Kindle. Check your mailbox for the verification email from Amazon Kindle.</p>
</div>

<div class="cBox1" id="sendToGoogleDriveMessage" style="display:none; position: relative;"></div>

<div class="cBox1Danger" id="errorMessage" style="display:none;">
    </div>

<div id="converterCurrentStatusesBoxContainer">
    <div id="converterCurrentStatusesBox">
            </div>
</div>
<div id="convertationStatusTemplates">
    <div class="status-new" data-job_id=""><div class="spinner-content"></div><div class="message">Conversion to <b class="book-property__extension"></b> is in progress</div></div>    <div class="status-error"><span class="zlibicon-close-circle status-icon"></span><div class="message">Conversion to <b class="book-property__extension"></b> is failed</div><span class="zlibicon-cross icon-hovered delete-btn" data-job_id=""></span></div></div>
<div id="shareToTooltipsContainer"></div>
</div>
        <div class="bookLoginBlock__wrapper">
    <div class="bookLoginBlock__container">
        <p class="bookLoginBlock__caption" "="">Begin your journey into the world of knowledge!        Check out the <a href="ireader/5496142">Preview</a> and access other features        </p>
        <div class="bookLoginBlock__buttons">
            <button class="bookLoginBlock__button bookLoginBlock__button_primary authButton" data-action="login">Log In</button>
        </div>
    </div>
</div>

</div></section>

</div>
'''
    data_business_vocabulary_loginned = '''
<div itemscope="" itemtype="http://schema.org/Book">
<div class="row cardBooks" data-spelling-suggest="true" data-book_id="5496142">
    <div class="col-sm-3 details-book-cover-container">
        <z-cover naturalratio="" volume="" markbutton="" id="5496142" isbn="97805211225041,97805211282851,97813166299701,97813166299871,05211225031,05211282851,131662997X1,13166299881" author="Bill Mascull" title="Business Vocabulary in Use: Intermediate, 3rd Edition">
            <img data-src="https://s3proxy.cdn-zlib.se/covers300/collections/genesis/4a68d5b0e5473673687f8a79afe8e1c1e2c995ccc70992b4d35a5d51d895d5fd.jpg">
        </z-cover>
    </div>

    <div class="col-sm-9">
        <h1 itemprop="name" style="color: #000; line-height: 140%;">
            Business Vocabulary in Use: Intermediate, 3rd Edition </h1>

        <i><a itemprop="author" class="color1" title="找到作者的所有书籍" href="/author/Bill Mascull">Bill Mascull</a></i>


        <div class="book-rating-detail">
            <div class="book-rating  cursor-pointer">
                <span class="book-rating-interest-score ">
5.0            </span> /
                <span class="book-rating-quality-score ">
5.0            </span>
            </div>
            <a href="#post" class="book-comments-info js-anchor">
                17 comments </a>
            <div class="bookmarks" style="display: none" data-book_id="5496142">

                <i class="icon-heart btn-save-for-later" title="标记你最喜欢或计划以后下载的书籍"></i>
                <i class="icon-bookmark btn-booklists" title="将这本书加入你的个人主题收藏，并与你的社区分享它"></i>
                <i class="icon-gratitude js-gratitude-icon" data-html="true" title="<span>为书籍向我们的图书管理员道谢<br /> </span>" style="width: 20px; height: 20px; top: -3px; position: relative;">
<div id="gratitudes_form"></div><script src="resources/build/bundles/gratitudes_form.04bb5f5f77fc9bac3a26.js" charset="UTF-8"></script>                </i>
            </div>
        </div>

        <div class="book-choice-rating" data-visible="0" data-init="0">
            <div class="overlay-post-score">
                <div id="bookChoiceRatingtFloatingSpinner"></div>
            </div>
            <div class="overlay">
                <div id="bookChoiceRatingSpinner"></div>
            </div>
            <div class="book-choice-interest-title">你有多喜欢这本书？</div>
            <div class="book-choice-interest-stars stars-list cursor-pointer" data-disabled="0" data-id="5496142" data-type="interest">
                <i class="book-rating-star"></i>
                <i class="book-rating-star"></i>
                <i class="book-rating-star"></i>
                <i class="book-rating-star"></i>
                <i class="book-rating-star"></i>
            </div>

            <div class="book-choice-quality-stub">
                <div class="book-choice-quality-title">下载文件的质量如何？</div>
                <div class="book-choice-quality-dmsg">下载该书，以评价其质量</div>
            </div>

            <div class="book-choice-quality-title">
                <div>下载文件的质量如何？</div>
            </div>
            <div class="book-quality-rating-template">
                <div class="book-format-quality-rating">
                    <div class="format-info">
                        <span class="download-date"></span>
                        <span class="extension book-property__extension"></span>
                        <span class="size"></span>
                    </div>
                    <div class="book-choice-quality-stars stars-list cursor-pointer" data-disabled="0" data-id="" data-type="quality">
                        <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Text is unreadable"></i>
                        <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Barely readable"></i>
                        <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Readable"></i>
                        <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Good"></i>
                        <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Perfect"></i>
                    </div>
                </div>
            </div>
        </div>

            <div class="bookDetailsBox">
                <div class="bookProperty property_categories">
                    <div class="property_label">种类:</div>
                    <div class="property_value "><a href="/category/377/Languages-English-as-a-Foreign-Language--Reference">Languages
                            - English as a Foreign Language &amp; Reference</a></div>
                </div>
                <div class="bookProperty property_volume">
                    <div class="property_label">卷:</div>
                    <div class="property_value ">00</div>
                </div>
                <div class="bookProperty property_year">
                    <div class="property_label">年:</div>
                    <div class="property_value ">2017</div>
                </div>
                <div class="bookProperty property_edition">
                    <div class="property_label">出版:</div>
                    <div class="property_value ">kindle</div>
                </div>
                <div class="bookProperty property_publisher">
                    <div class="property_label">出版社:</div>
                    <div class="property_value ">Cambridge University Press</div>
                </div>
                <div class="bookProperty property_language">
                    <div class="property_label">语言:</div>
                    <div class="property_value text-capitalize">english</div>
                </div>
                <div class="bookProperty property_pages">
                    <div class="property_label">页:</div>
                    <div class="property_value ">
                        <span title="Pages paperback">175</span></div>
                </div>
                <div class="bookProperty property_isbn">
                    <div class="property_label">ISBN:</div>
                    <div class="property_value ">13166299881</div>
                </div>
                <div class="bookProperty property_series">
                    <div class="property_label">系列:</div>
                    <div class="property_value ">Intermediate</div>
                </div>
                <div class="bookProperty property__file">
                    <div class="property_label">文件:</div>
                    <div class="property_value ">PDF, 11.39 MB</div>
                </div>
                <div style="display: none;" class="bookProperty property_user_tags">
                    <div class="property_label">您的标签:</div>
                    <div class="property_value "></div>
                </div>
                <div class="bookProperty property_ipfs_cid">
                    <div class="property_label">IPFS:</div>
                    <div class="property_value">
                        <span class="z-copy-icon tooltip-init" data-placement="bottom" title="复制" data-copy="QmSjnbxgGVTQ1iPi52oj2UZnpX5FXspuBaggJfWQjq3uSw" data-notif="CID 复制到剪贴板">CID</span>
                        ,
                        <span class="z-copy-icon tooltip-init" data-placement="bottom" title="复制" data-copy="bafykbzacecoonxpeo3kx2hgl5w2be3py65qikdlpnmwjriecm6gdgevgc63is" data-notif="CID 复制到剪贴板">CID Blake2b</span>
                    </div>
                </div>
                <div class="bookProperty property_language_year">english, 2017</div>
            </div>
        </div>
    </div>
</div>

<section class="book-actions-container">
    <div class="details-buttons-container">
        <div class="book-actions-buttons">
            <div class="book-details-button read-online ">
                <div class="btn-group">
                    <a class="btn btn-primary addDownloadedBook" href="/dl/5496142/947a20" target="" data-book_id="5496142" data-isbn="97805211225041" rel="nofollow">
                        <i class="zlibicon-download"></i>下载
                        (<span class="book-property__extension">pdf</span>, 11.39
                        MB)
                    </a>
                    <button id="btnCheckOtherFormats" type="button" class="btn btn-primary dropdown-toggle dlDropdownBtn" data-check-formats="1" data-convertation-available="0">
<span class="zlibicon-menu-dots"></span>
<span class="sr-only">Toggle Dropdown</span>
</button>
                    <ul class="dropdown-menu">
                        <li class="disabled"><i class="zlibicon-play"></i>线上阅读</li>
                        <li>
                            <div class="premium-only"><a href="/how-to-donate" target="_blank">成为高级会员</a>以访问在线阅读</div>
                        </li>
                        <!-- <li role="separator" class="divider"></li> -->
                        <li role="separator" class="divider other-formats-divider">
                            <div class="divider-text">下载</div>
                        </li>
                        <li id="bookOtherFormatsContainer">
                            <span class="dropdown-menu-muted" style="padding: 5px 19px 0; white-space: nowrap;">
Checking other formats...
<span id="bookOtherFormatsSpinnerContainer"></span>
                            </span>
                        </li>
                    </ul>
                </div>

            </div>


            <div class="book-details-button">
                <div class="btn-group" id="sendToButtonBox">
                    <button type="button" class="btn btn-default dropdown-toggle button-send-book" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
发送到            <span class="sendToButtonBox__icons">
<i class="zlibicon-envelope menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-google-drive menu-row__icon" style="font-size: 11px;"></i><i class="zlibicon-Pocketbook menu-row__icon" style="position: relative;top: 2px;font-size: 16px;"></i><i class="zlibicon-Amazon menu-row__icon" style="position: relative;top: 4px;font-size: 16px;"></i>            </span>
<span class="caret"></span>
</button>
                    <div class="dropdown-menu">
                        <section class="dropdown-widget send-to-widget menu-content">
                            <div class="menu-row send-to" data-send_to="email">
                                <i class="zlibicon-envelope menu-row__icon" style="font-size: 11px;"></i><span>Email <span class="gray">(aaaaaa1964027610@163.com)</span></span>
                            </div>
                            <div class="menu-row send-to" data-send_to="googleDrive">
                                <i class="zlibicon-google-drive menu-row__icon" style="font-size: 11px;"></i><span>Google Drive</span>
                            </div>
                            <div class="menu-row send-to" data-send_to="telegram">
                                <i class="zlibicon-paper-airplane menu-row__icon" style="font-size: 11px;"></i><span>Telegram</span>
                            </div>
                            <div class="menu-row send-to" data-send_to="wechat">
                                <i class="zlibicon-we-chat menu-row__icon" style="position: relative;top: 2px;font-size: 16px;"></i><span>WeChat</span>
                            </div>
                            <div class="dropdown-menu__divider"><span>电子阅读器</span>
                            </div>
                            <div class="menu-row send-to menu-row_unavailable" data-send_to="kindle">
                                <i class="zlibicon-Amazon menu-row__icon" style="position: relative;top: 4px;font-size: 16px;"></i><span>Kindle</span>
                            </div>
                            <div class="menu-row__message menu-row__message_warning">
                                <span><a href="/how-to-donate" target="_blank">成为高级会员</a>以访问此功能</span>
                            </div>
                            <div class="menu-row send-to menu-row_unavailable" data-send_to="pocketbook">
                                <i class="zlibicon-Pocketbook menu-row__icon" style="position: relative;top: 2px;font-size: 16px;"></i><span>PocketBook</span>
                            </div>
                            <div class="menu-row__message">
                                <span>未提供电子邮件。<a href="/profileEdit" target="_blank">设置PocketBook电子邮件</a></span><span class="menu-row__hint"><i class="zlibicon-question-circle" title="需要帮助吗？请了解<br/><a class=&quot;text--inline-link&quot; href=&quot;/info/howtopocketbook&quot;>向PocketBook发送书籍</a>的说明" data-toggle="tooltip" data-placement="top" data-html="true" data-mouseover="true"></i></span>
                            </div>
                        </section>
                    </div>
                </div>
            </div>

            <div class="details-buttons-container__divider"></div>
            <div class="book-details-button">
                <div class="btn-group">
                    <button type="button" class="btn btn-default dropdown-toggle button-paperback" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
平装 <span class="caret"></span>
</button>
                    <ul class="dropdown-menu">
                        <div class="menu-content menu-content_paperback">
                            <div class="menu-row">
                                <a class="menu__link_paperback" href="https://amazon.com/s?k=Business+Vocabulary+in+Use%3A+Intermediate%2C+3rd+Edition Bill+Mascull" target="_blank">
                                    <img class="menu__icon" src="/img/book-stores/amazon_grayscale.svg">
Amazon </a>
                            </div>
                            <div class="menu-row">
                                <a class="menu__link_paperback" href="https://www.barnesandnoble.com/s/Business+Vocabulary+in+Use%3A+Intermediate%2C+3rd+Edition Bill+Mascull" target="_blank">
                                    <img class="menu__icon" src="/img/book-stores/barnes_noble_grayscale.svg">
Barnes &amp; Noble </a>
                            </div>
                            <div class="menu-row">
                                <a class="menu__link_paperback" href="https://bookshop.org/search?keywords=Business+Vocabulary+in+Use%3A+Intermediate%2C+3rd+Edition Bill+Mascull" target="_blank">
                                    <img class="menu__icon" src="/img/book-stores/bookshoporg_grayscale.svg">
Bookshop.org </a>
                            </div>

                            <div class="text--hint">
                                想添加您的书店？ 通过 <a href="mailto:support@z-lib.se">support@z-lib.se</a>
                                与我们联系 </div>
                        </div>
                    </ul>
                </div>
            </div>
            <div class="clear"></div>
            <z-dropdown topic="书籍有问题吗？" arrow="" onchange="smthwrong(event)">
                <label value="suggest"><i class="zlibicon-suggest"></i> 已建议的修改</label>
                <label value="report"><i class="zlibicon-warning"></i> 报告问题</label>
            </z-dropdown>
        </div>
        <div class="book-actions-status">
            <div class="cBox1" id="sentToEmailInfo" style="display:none;">
                在1-5分钟内，文件将被发送到您的电子邮件。</div>

            <div class="cBox1" id="sentToTelegramInfo" style="display:none;">
                <p>该文件将通过电报信使发送给您。 您最多可能需要 1-5 分钟才能收到它。</p>
                <p>注意：确保您已将您的帐户链接到 Z-Library Telegram 机器人。</p>
            </div>

            <div class="cBox1" id="sentToEmailInfoKindle" style="display:none;">
                <p>该文件将发送到您的 Kindle 帐户。 您最多可能需要 1-5 分钟才能收到它。</p>
                <p><b>请注意</b>：您需要验证要发送到Kindle的每本书。检查您的邮箱中是否有来自亚马逊Kindle的验证电子邮件。</p>
            </div>

            <div class="cBox1" id="sendToGoogleDriveMessage" style="display:none; position: relative;"></div>

            <div class="cBox1Danger" id="errorMessage" style="display:none;">
            </div>

            <div id="converterCurrentStatusesBoxContainer">
                <div id="converterCurrentStatusesBox">
                </div>
            </div>
            <div id="convertationStatusTemplates">
                <div class="status-new" data-job_id="">
                    <div class="spinner-content"></div>
                    <div class="message">正在转换
                        <b class="book-property__extension"></b></div>
                </div>
                <div class="status-error">
                    <span class="zlibicon-close-circle status-icon"></span>
                    <div class="message">转换为
                        <b class="book-property__extension"></b> 失败</div>
                    <span class="zlibicon-cross icon-hovered delete-btn" data-job_id=""></span>
                </div>
            </div>
            <div id="shareToTooltipsContainer"></div>
        </div>
</div></section>

</div>

<div style="padding:10px 0; font-size:10pt" id="bookDescriptionBox" itemprop="reviewBody">
The words you need to communicate with confidence in business
today.&nbsp; Vocabulary explanations and practice for intermediate (B1
to B2) students and professionals looking to improve their knowledge and
use of business English. This book is perfect for both self-study and
classroom activities. Inside the book is a code for an ebook that can be
used online with Macs, PCs and tablets. It can also be downloaded to iOS
and Android tablets using the free Cambridge Bookshelf app. The ebook
has the same content as the printed book, plus features such as audio so
that you can listen to the words as well as reading them. </div>
'''
    json_str = search_single_book_parse(data_business_vocabulary_loginned)
    print(json_str)
