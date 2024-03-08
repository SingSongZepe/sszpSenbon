# This Python file uses the following encoding: utf-8

import typing
from bs4 import BeautifulSoup as bs
import json
from dataclasses import asdict

from book_info import BookInfo

print("Hello World!")
print('SingSongZepe Book Result Parse!')

def print_hello():
    print('Hello, World!')

def add(a, b):
    return a + b

def book_result_parse(data):
    soup = bs(data, 'html.parser')
    
    # cover
    imgs_with_cover = soup.select('img.cover')
    len_imgs_with_cover = len(imgs_with_cover)
    print(f'imgs with cover length: {len_imgs_with_cover}')

    # href
    as_with_href = [z_cover.select_one('a') for z_cover in soup.select('z-cover')]
    len_as_with_href = len(as_with_href)
    print(f'imgs with href length: {len_as_with_href}')

    # title
    as_with_title = [h3.select_one('a') for h3 in soup.select('td h3')]
    len_as_with_title = len(as_with_title)
    print(f'imgs with title length: {len_as_with_title}')

    # publisher
    as_with_publisher = [td.select_one('div[style] a[title]') for td in soup.select('td:not([class]):not([style])')]
    len_as_with_publisher = len(as_with_publisher)
    print(f'imgs with publisher length: {len_as_with_publisher}')

    # author
    as_with_author = soup.select('div.authors a')
    len_as_with_author = len(as_with_author)
    print(f'imgs with author length: {len_as_with_author}')

    # property__file property_value
    div_with_file_info = soup.select('div.property__file div.property_value')
    len_div_with_file_info = len(div_with_file_info)
    print(f'imgs with file info length: {len_div_with_file_info}')

    # property_language property_value
    div_with_language = soup.select('div.property_language div.property_value')
    len_div_with_language = len(div_with_language)
    print(f'imgs with language length: {len_div_with_language}')

    # property_rating 
        # book-rating-interest-score book-rating-quality-score
    div_with_rating = soup.select('div.property_rating')
    len_div_with_rating = len(div_with_rating)
    print(f'imgs with rating length: {len_div_with_rating}')


    book_infos = []
    for idx in range(len(imgs_with_cover)):
        cover = imgs_with_cover[idx]['data-src']
        # print(cover)
        url = as_with_href[idx]['href']
        # print(url)
        title = as_with_title[idx].text
        # print(title)
        publisher = as_with_publisher[idx].text
        # print(publisher)
        authors = as_with_author[idx].text
        # print(authors)
        file_info = div_with_file_info[idx].text
        # print(file_info)
        language = div_with_language[idx].text
        # print(language)
        rating = div_with_rating[idx].select_one('span.book-rating-interest-score').text.replace(' ', '').replace('\n', '') + '/' + div_with_rating[idx].select_one('span.book-rating-quality-score').text.replace(' ', '').replace('\n', '')
        # print(rating)

        book_info = BookInfo(url, cover, title, publisher, authors, file_info, language, rating)
        book_infos.append(asdict(book_info))

    return json.dumps(book_infos)

# test
if __name__ == '__main__':
    data = '''
<div class="resItemBox resItemBoxBooks exactMatch" data-spelling-suggest="true" data-book_id="13858830" itemscope="" itemtype="http://schema.org/Book">
    <div>
        <div class="counter">1</div>
        <table style="width:100%; height:100%;" class="resItemTable">
            <tbody><tr class="bookRow" data-book_id="13858830">
                <td class="itemCover">
                    <div class="itemCoverWrapper">
                        <z-cover id="13858830" isbn="" author="南派三叔 [南派三叔]" title="盗墓笔记：沙海系列1-4" naturalratio="" volume="" size="100" class="ready">
                            <a href="/book/13858830/2803cc/%E7%9B%97%E5%A2%93%E7%AC%94%E8%AE%B0%E6%B2%99%E6%B5%B7%E7%B3%BB%E5%88%9714.html"><img class="cover lazy" alt="" style="border-width: 1px; display: inline;" srcset="https://s3proxy.cdn-zlib.se/covers100/collections/userbooks/3b3c9446f9a3159a36cd354bef43a5b7a114c0edb5a57c94d3293dd95a5f2ec9.jpg 1x, https://s3proxy.cdn-zlib.se/covers200/collections/userbooks/3b3c9446f9a3159a36cd354bef43a5b7a114c0edb5a57c94d3293dd95a5f2ec9.jpg 2x"></a>
                        </z-cover>
                    </div>
                </td>
                
                <td style="vertical-align: top;">
                    <table style="width:100%;height:100%;">
                        <tbody><tr>
                            <td>
                                <h3 itemprop="name">
                                    <a href="/book/13858830/2803cc/%E7%9B%97%E5%A2%93%E7%AC%94%E8%AE%B0%E6%B2%99%E6%B5%B7%E7%B3%BB%E5%88%9714.html" style="text-decoration: underline;" data-target-desktop="new-tab">盗墓笔记：沙海系列1-4</a>
                                    
                                </h3>
                                <div style="color: #333; font-size: 10pt;margin-bottom:10px;"><a href="/publisher/Hello World" title="Publisher">Hello World</a></div>
                                <div class="authors"><a itemprop="author" class="color1" title="Find all the author's book" href="/author/%E5%8D%97%E6%B4%BE%E4%B8%89%E5%8F%94 %5B%E5%8D%97%E6%B4%BE%E4%B8%89%E5%8F%94%5D">南派三叔 [南派三叔]</a></div>
                            </td>
                            
                            
                        </tr>
                        <tr>
                            <td colspan="99" style="vertical-align: bottom;">
                                <div class="tags-container"></div>
                                
                                
                                <div class="bookDetailsBox">
                <div class="bookProperty property_language">
                    <div class="property_label">Language:</div>
            <div class="property_value text-capitalize">chinese</div></div>
                <div class="bookProperty property__file">
                    <div class="property_label">File:</div>
            <div class="property_value ">EPUB, 863 KB</div></div>
                <div style="display: none;" class="bookProperty property_user_tags">
                    <div class="property_label">Your tags:</div>
            <div class="property_value "></div></div>
            <div class="bookProperty property_rating">
                <div class="book-rating" title="" data-book_id="13858830" data-terms_hash="80d16715dfa7b8c1e4e7783292a5caa6" data-original-title="Book Rating / File Quality">
                    <span class="book-rating-interest-score ">
                        5.0
                    </span> /
                    <span class="book-rating-quality-score ">
                        5.0
                    </span>
                </div>
            </div><div class="bookProperty property_language_year">chinese</div></div>
                            </td>
                        </tr>
                    </tbody></table>
                </td>                
            </tr>
        </tbody></table>
    </div>
</div>
<div class="resItemBox resItemBoxBooks exactMatch" data-spelling-suggest="true" data-book_id="3397236" itemscope="" itemtype="http://schema.org/Book">
    <div>
        <div class="counter">2</div>
        <table style="width:100%; height:100%;" class="resItemTable">
            <tbody><tr class="bookRow" data-book_id="3397236">
                <td class="itemCover">
                    <div class="itemCoverWrapper">
                        <z-cover id="3397236" isbn="9780394479958" author="Eric Berne" title="What do you say after you say hello?: The psychology of human destiny" naturalratio="" volume="" size="100" class="ready">
                            <a href="/book/3397236/b6657d/what-do-you-say-after-you-say-hello-the-psychology-of-human-destiny.html"><img class="cover lazy" alt="" style="border-width: 1px; display: inline;" srcset="https://s3proxy.cdn-zlib.se/covers100/collections/genesis/994cafbde5c42f8da299f4ac2cac5fdd6b22fe7a46cfb26ab78b9be16add2852.jpg 1x, https://s3proxy.cdn-zlib.se/covers200/collections/genesis/994cafbde5c42f8da299f4ac2cac5fdd6b22fe7a46cfb26ab78b9be16add2852.jpg 2x"></a>
                        </z-cover>
                    </div>
                </td>
                
                <td style="vertical-align: top;">
                    <table style="width:100%;height:100%;">
                        <tbody><tr>
                            <td>
                                <h3 itemprop="name">
                                    <a href="/book/3397236/b6657d/what-do-you-say-after-you-say-hello-the-psychology-of-human-destiny.html" style="text-decoration: underline;" data-target-desktop="new-tab">What do you say after you say hello?: The psychology of human destiny</a>
                                    
                                </h3>
                                <div style="color: #333; font-size: 10pt;margin-bottom:10px;"><a href="/publisher/Grove Press" title="Publisher">Grove Press</a></div>
                                <div class="authors"><a itemprop="author" class="color1" title="Find all the author's book" href="/author/Eric Berne">Eric Berne</a></div>
                            </td>
                            
                            
                        </tr>
                        <tr>
                            <td colspan="99" style="vertical-align: bottom;">
                                <div class="tags-container"></div>
                                
                                
                                <div class="bookDetailsBox">
                <div class="bookProperty property_year">
                    <div class="property_label">Year:</div>
            <div class="property_value ">1972</div></div>
                <div class="bookProperty property_language">
                    <div class="property_label">Language:</div>
            <div class="property_value text-capitalize">english</div></div>
                <div class="bookProperty property__file">
                    <div class="property_label">File:</div>
            <div class="property_value ">PDF, 46.23 MB</div></div>
                <div style="display: none;" class="bookProperty property_user_tags">
                    <div class="property_label">Your tags:</div>
            <div class="property_value "></div></div>
            <div class="bookProperty property_rating">
                <div class="book-rating" title="" data-book_id="3397236" data-terms_hash="3ad5016dbff3b99b24056b1a0ed512e9" data-original-title="Book Rating / File Quality">
                    <span class="book-rating-interest-score ">
                        5.0
                    </span> /
                    <span class="book-rating-quality-score ">
                        5.0
                    </span>
                </div>
            </div><div class="bookProperty property_language_year">english, 1972</div></div>
                            </td>
                        </tr>
                    </tbody></table>
                </td>                
            </tr>
        </tbody></table>
    </div>
</div>
'''
    json_str = book_result_parse(data)
    print(type(json_str))
    print(json_str)

