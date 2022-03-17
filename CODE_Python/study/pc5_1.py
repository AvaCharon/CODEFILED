import requests
from bs4 import BeautifulSoup

url='https://www.bilibili.com/v/game/stand_alone/?spm_id_from=333.5.b_7375626e6176.2#/'
html=requests.get(url).text
soup=BeautifulSoup(html,'lxml')
video_titles_list=[]
video_titles=soup.find_all(name='div',attrs={'class':'pic'})
for video_title in zip(video_titles):
    video_titles_list.append(video_title)
print(video_titles_list)

