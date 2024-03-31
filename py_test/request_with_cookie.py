import requests
import json
from urllib.parse import urljoin as uj

zlibrary_root_url = 'https://zh.z-library.se/'

def req(cookie: str):
    url = 'https://z-library.se/book/3397236/b6657d/what-do-you-say-after-you-say-hello-the-psychology-of-human-destiny.html'

    headers = {
        'Cookie': cookie + 'siteLanguage=zh',
        # 'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
    }

    data = requests.get(url=url, headers=headers, verify=False)
    
    with open('./py_test/default.html', 'w+', encoding='utf8') as pf:
        pf.write(data.text)

def req_book(cookie, download_url):
    headers = {
        'Cookie': cookie,
        # 'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
    }

    data = requests.get(url=download_url, headers=headers, verify=False)
    print(data.headers['Location'])
    # with open('./py_test/book.epub', 'wb') as pf:
    #     pf.write(data.content)

# for a cookie, if its the first time to download the book,
# then will not redirect to the real url, but the book introduction url,
# so we will check if it's the html file, and then find the real url,
# its download url will divide to two parts
# for example: /dl/1313328/cabbc0
# 1313328 is the same for all users(cookies)
# cabbc0 is just for the current user(cookie) that requests for the html(book) url
# so when use the url to download a book, it is necessary to use the cookie that requests
def req_book_usually(cookie, download_url):
    headers = {
        'Cookie': cookie,
    }
    data = requests.get(url=download_url, headers=headers, verify=False)
    print(data.status_code)
    print(data.text)

if __name__ == '__main__':
    with open('./cookies.json', 'r') as pf:
        json_str = pf.read()

    cookies = json.loads(json_str)
    # req(cookies[2]['cookie'])

    # download_url = 'https://z-librarya.se/dl/3397236/7f99a6'

    # req_book(cookies[0]['cookie'], download_url)

    # hrefs = [
    #     '/dl/5239682/1e80e2',
    #     '/dl/1313328/cabbc0',
    # ]
    # download_url = uj(zlibrary_root_url, hrefs[1])
    # req_book_usually(cookie=cookies[1]['cookie'], download_url=download_url)

    # test for get extension of the book
    download_url = uj(zlibrary_root_url, '/dl/17803802/83817d?dsource=recommend')
    req_book_usually(cookie=cookies[1]['cookie'], download_url=download_url)

