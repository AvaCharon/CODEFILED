import requests
from bs4 import BeautifulSoup

#定义函数
def get_title(url):
    #异常处理
    try:
        html = requests.get(url).text
        soup = BeautifulSoup(html,'lxml')
        title = soup.title.text
        return title
    except Exception as e:
        print(e)
        return None

url='https://www.bilibili.com/'
content = get_title(url)
if content:
    print(content)
else:
    print("Something wrong happen")