import requests
import json

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
        'Cookie': cookie + 'siteLanguage=zh',
        # 'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3',
    }

    data = requests.get(url=download_url, headers=headers, verify=False)
    with open('./py_test/book.epub', 'wb') as pf:
        pf.write(data.content)

if __name__ == '__main__':
    with open('./cookies.json', 'r') as pf:
        json_str = pf.read()

    cookies = json.loads(json_str)
    req(cookies[2]['cookie'])

    download_url = 'https://zh.z-library.se/dl/1768626/6380f8'

    req_book(cookies[2]['cookie'], download_url)
