import requests
from bs4 import BeautifulSoup

url = 'https://www.bilibili.com/'
html = requests.get(url=url).text
soup = BeautifulSoup(html,'lxml')#lxml----->html,xml
print(soup.prettify())