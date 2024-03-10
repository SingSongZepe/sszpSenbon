from bs4 import BeautifulSoup as bs

def search_single_book_parse(data):

    soup = bs(data, 'html.parser')
    img = soup.select('div.details-book-cover-container z-cover img')
    print(img['data-src'])
    
    return data

# 
if __name__ == '__main__':
    data = '''
<div itemscope itemtype="http://schema.org/Book">
    <div class="row cardBooks" data-spelling-suggest="true" data-book_id="13858830">
        <div class="col-sm-3 details-book-cover-container">
            <z-cover naturalRatio volume markButton id="13858830" isbn=""
                author="南派三叔 [南派三叔]" title="盗墓笔记：沙海系列1-4">
                <img data-src="https://s3proxy.cdn-zlib.se/covers300/collections/userbooks/3b3c9446f9a3159a36cd354bef43a5b7a114c0edb5a57c94d3293dd95a5f2ec9.jpg">
            </z-cover>
        </div>

        <div class="col-sm-9">
            <h1 itemprop="name" style="color: #000; line-height: 140%;">
                盗墓笔记：沙海系列1-4 </h1>

            <i><a  itemprop="author" class="color1" title="Find all the author's book" href="/author/%E5%8D%97%E6%B4%BE%E4%B8%89%E5%8F%94 %5B%E5%8D%97%E6%B4%BE%E4%B8%89%E5%8F%94%5D">南派三叔 [南派三叔]</a></i>


            <div class="book-rating-detail">
                <div class="book-rating ">
                    <span class="book-rating-interest-score ">
5.0            </span> /
                    <span class="book-rating-quality-score ">
5.0            </span>
                </div>
                <a href="#post" class="book-comments-info js-anchor">
                    2 comments </a>
                <div class="bookmarks" style="display: none" data-book_id="13858830">

                    <i class="icon-heart btn-save-for-later" title="Mark the book you like best or plan to download later"></i>
                    <i class="icon-bookmark btn-booklists" title="Add the book to your personal themed book collection and share it with your community"></i>
                </div>
            </div>

            <div class="book-choice-rating" data-visible="0" data-init="0">
                <div class="overlay-post-score">
                    <div id="bookChoiceRatingtFloatingSpinner"></div>
                </div>
                <div class="overlay">
                    <div id="bookChoiceRatingSpinner"></div>
                </div>
                <div class="book-choice-interest-title">How much do you like this book?
                </div>
                <div class="book-choice-interest-stars stars-list cursor-pointer"
                    data-disabled="0" data-id="13858830" data-type="interest">
                    <i class="book-rating-star"></i>
                    <i class="book-rating-star"></i>
                    <i class="book-rating-star"></i>
                    <i class="book-rating-star"></i>
                    <i class="book-rating-star"></i>
                </div>

                <div class="book-choice-quality-stub">
                    <div class="book-choice-quality-title">What’s the quality of the
                        file?</div>
                    <div class="book-choice-quality-dmsg">Download the book for quality
                        assessment</div>
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
                        <div class="book-choice-quality-stars stars-list cursor-pointer"
                            data-disabled="0" data-id="" data-type="quality">
                            <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Text is unreadable"></i>
                            <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Barely readable"></i>
                            <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Readable"></i>
                            <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Good"></i>
                            <i class="book-rating-star _tooltip" data-toggle="tooltip" title="Perfect"></i>
                        </div>
                    </div>
                </div>
            </div>
'''
    search_single_book_parse(data)

