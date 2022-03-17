# -*- codeing = utf-8 -*-
from bs4 import BeautifulSoup  
import re  
import urllib.request, urllib.error  
import requests
import xlwt 

findLink = re.compile(r'<a href="(.*?)">')  
findImgSrc = re.compile(r'<img.*src="(.*?)"', re.S)
findTitle = re.compile(r'<span class="title">(.*)</span>')
findLength = re.compile(r'<span class="length">(:*)</span>')
findplay = re.compile(r'<span class="play">(.*?)</span>')
findtime = re.compile(r'<span class="time">(.*?)</span>')

def main():
    baseurl = "https://space.bilibili.com/3094025/video?tid=0&page="  
    if(getData==False):
        return
    datalist = getData(baseurl)
    savepath = "小牧phenix的视频.xls"  
    saveData(datalist,savepath) 



def getData(baseurl):
    datalist = [] 
    for i in range(1, 12):  
        url = baseurl + str(i)
        headers = {'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.87 Safari/537.36 Edg/80.0.361.48'}
        html = requests.get(url,headers=headers)
        if html.status_code != 200:
            print("failed to get the website")
            return False
        soup = BeautifulSoup(html.text, 'html5lib')
        print(soup)
        for item in soup.find_all('li',class_="small-item fakeDanmu-item"):
            print("find")
            data = []
            item = str(item)
            print(item)
            link = re.findall(findLink, item)[0]
            data.append(link)
            imgSrc = re.findall(findImgSrc, item)[0]
            data.append(imgSrc)
            titles = re.findall(findTitle, item)
            data.append(titles)
            length = re.findall(findLength, item)[0]
            data.append(length)
            playNum = re.findall(findplay, item)[0]
            data.append(playNum)
            time = re.findall(findtime, item)
            data.append(time)
            datalist.append(data)
    return datalist



def saveData(datalist,savepath):
    print("save.......")
    book = xlwt.Workbook(encoding="utf-8",style_compression=0) #创建workbook对象
    sheet = book.add_sheet('小牧phenix视频', cell_overwrite_ok=True) #创建工作表
    col = ("详情链接","图片链接","标题","长度","播放量","投稿时间")
    for i in range(0,6):#列
        sheet.write(0,i,col[i]) 
    for i in range(0,360):
        print("第%d条" %(i+1))       #输出语句，用来测试
        data = datalist[i]
        for j in range(0,6):
            sheet.write(i+1,j,data[j]) 
    book.save(savepath) 



if __name__ == "__main__":  # 当程序执行时
    # 调用函数
     main()
    # init_db("movietest.db")
     print("爬取完毕！")

