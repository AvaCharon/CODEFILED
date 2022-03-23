import requests
from bs4 import BeautifulSoup
import re
import xlwt


findtitle=re.compile(r'target="_blank">(.*?)</a>',re.S)
findplay=re.compile(r'<i class="b-icon play"></i>(.*?)</span>',re.S)
findauthor=re.compile(r'<i class="b-icon author"></i>(.*?)</span>',re.S)
findpts=re.compile(r'<div class="pts"><div>(.*?)</div>')

url="https://www.bilibili.com/v/popular/rank/all"
header={'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/93.0.4577.63 Safari/537.36 Edg/93.0.961.47'}
html=requests.get(url,headers=header)
if(html.status_code!=200):
    print("failed to get the website")
soup=BeautifulSoup(html.text,'html.parser')

datalist=[]

for item in soup.find_all('li',class_='rank-item'):
    data=[]
    item=str(item)
    a = re.compile(r'\n|\'|\xa0|\xa0|\u3000|\u3000|\u0020|\u0020|\t|\r')
    title=re.findall(findtitle,item)[1]
    title = a.sub('', title)
    data.append(title)
    play= re.findall(findplay,item)[0]
    play = a.sub('', play)
    data.append(play)
    author=re.findall(findauthor,item)[0]
    author = a.sub('', author)
    data.append(author)
    pts=re.findall(findpts,item)[0]
    pts = a.sub('', pts)
    data.append(pts)
    datalist.append(data)

'''
for i in range(len(datalist)):
    data=datalist[i]
    for i in range(4):
        print(data[i])
    print("\n")
'''

print("Saving...")
savepath = "全站当日Top100.xls" 
book = xlwt.Workbook(encoding="utf-8") #创建workbook对象
sheet = book.add_sheet('全站当日top100') #创建工作表
col = ("视频标题","播放量","up","热度评分")
for i in range(0,4):
    sheet.write(0,i,col[i])  
for i in range(0,100):
    data = datalist[i]
    for j in range(0,4):
        sheet.write(i+1,j,data[j])  
book.save(savepath) 
print("Done")