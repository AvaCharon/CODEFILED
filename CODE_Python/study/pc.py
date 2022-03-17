from urllib import request
url='https://www.baidu.com/'
response = request.urlopen(url)
print(response.read())