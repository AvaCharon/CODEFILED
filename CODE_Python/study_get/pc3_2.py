import requests
from bs4 import BeautifulSoup

url='http://www.bilibili.com/'
response = requests.get(url)
response.encoding='GBK'
response.encoding='utf-8'
html=response.text
soup=BeautifulSoup(html,'lxml')
print(soup)
print(soup.title)
print(soup.html.title)
print(soup.html.head.title)