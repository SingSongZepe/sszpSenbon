from bs4 import BeautifulSoup as bs
import re
import typing

print('Hello World!')
print('SingSongZepe cookie useful checker')

NUMBER_MATCHER = r'\d+'

def check_cookie_useful(data: str) -> int: # 0 or 1, if 0, then False. if 1, then True
    soup = bs(data, 'html.parser')

    div_with_user_status = soup.select_one('div.user-data__stats-value')
    text = div_with_user_status.text.replace(' ', '')
    matches: typing.List[str] = re.findall(NUMBER_MATCHER, text)
    if len(matches) == 2:
        if matches[0].isdigit() and matches[1].isdigit():
            if matches[0] != matches[1]:  # the last one will be 10, if not vip user
                return 1
            print('SingSongLog: [NOR], this cookie is not useful')
        print('SingSongLog: [WAR] there is not digit for user status')
    return 0

if __name__ == '__main__':
    data = '''
<div class="user-data__auth-info">
    <div class="user-data__stats">
        <div class="user-data__stats-item" data-menu-toggle="tooltip" data-placement="bottom" data-original-title="每日限额">
            <div class="user-data__stats-title">
                <i class="zlibicon-download"></i>
                <span>每日限额</span>
            </div>
            <div class="user-data__stats-value">
                10/10                                                    </div>
        </div>
        <div class="user-data__stats-item" data-menu-toggle="tooltip" data-placement="bottom" data-original-title="捐款">
            <div class="user-data__stats-title">
                <i class="zlibicon-dollar"></i>
                <span>捐款</span>
            </div>
            <div class="user-data__stats-value">$0</div>
        </div>
    </div>
</div>
'''
    print(check_cookie_useful(data))

