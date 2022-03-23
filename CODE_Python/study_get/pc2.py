import requests
url = 'https://www.bilibili.com/'
respond=requests.get(url=url)
print(respond.text)