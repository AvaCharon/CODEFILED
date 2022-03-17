import re

reg_str = '[a-zA-Z0-9]+@[a-zA-Z0-9]+\.(com)'
reg = re.compile(reg_str)

a_str = 'Charon259@gmail.com'
a_match=re.match(reg,a_str)
if a_match:
    print(a_match.group())
else:
    print('没有匹配上')