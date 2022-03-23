import requests
from bs4 import BeautifulSoup
import os
from time import sleep
import re
import random

from requests.api import get

global index
index=1

findimage=re.compile(r'src="(.*?\.jpg)" size')


def get_html(url):
    response=requests.get(url)
    html=response.text
    return html

def download(html):
    image_list=re.findall(findimage,html)
    global index
    for url in image_list:
        content = requests.get(url).content
        with open('./image/picture_%d.jpg'%index,'wb')as file:
            file.write(content)
        sleep(random.uniform(0.5,1))
        index+=1


if __name__=='__main__':
    os.makedirs('./image/',exist_ok=True)
    print("Downloading")
    for i in range(1,111):
        url = 'https://tieba.baidu.com/p/4975812455?pn='+str(i)
        html1=get_html(url)
        download(html1)
    print("Done")
