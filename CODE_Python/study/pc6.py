#正则表达式
#匹配字符串
import re

reg_str='h+d{2}(qq)*(w| )'# ?表示零次/+表示一次及以上/*表示任意次/ 表示空
reg=re.compile(reg_str) #提高匹配速度

a_str='hddw'
b_str='hhhhhdddqq '

a_match=re.match(reg,a_str)
b_match=re.match(reg,b_str)

if a_match:
    print(a_match.group())
else:
    print("字符串a没有匹配上")
if b_match:
    print(b_match.group())
else:
    print("字符串b没有匹配上")
