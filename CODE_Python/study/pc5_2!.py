import bs4
import requests
from bs4 import BeautifulSoup

#通过bs4解析复杂页面
url='https://space.bilibili.com/3094025/video'
html=requests.get(url).text
soup=BeautifulSoup(html,'lxml')
paradox_up_list=[]
paradox_ups=soup.find_all(name='a',attrs={'href':'*'})
for paradox_up in zip(paradox_ups):
    paradox_up_list.append(paradox_up)
print(paradox_up_list)

