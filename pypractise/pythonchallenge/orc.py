
import urllib2,re

def txt_wrap_by(start_str, end, html):
    firstEnd = html.find(end)
    start = html.find(start_str,firstEnd)
    if start >= 0:
        start += len(start_str)
        end = html.find(end, start)
        if end >= 0:
            return html[start:end].strip()

html = urllib2.urlopen('http://www.pythonchallenge.com/pc/def/ocr.html')
page = html.read()
# s = txt_wrap_by("<!--","-->",page)
s = re.findall(r'<!--(.*?)-->',page,re.S)
print s[1]
target = re.findall(r'[A-Za-z]',s[1],re.S)
print ''.join(target.__iter__())
# s = ''.join(s.__iter__())
# w = []
# for i in range(0,len(s)):
#     if ord(s[i]) >= 97 and ord(s[i]) <= 122:
#         w.append(s[i])
# # s = re.compile(r'<!--.*').findall(page)
# print ''.join(w.__iter__())

