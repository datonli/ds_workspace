__author__ = 'Daniel.Lee'

import urllib2,re

def txt_wrap_by(start_str, end, html):
    start = html.find(start_str)
    if start >= 0:
        start += len(start_str)
        end = html.find(end, start)
        if end >= 0:
            return html[start:end].strip()

html = urllib2.urlopen('http://www.pythonchallenge.com/pc/def/equality.html')
page = html.read()
# s = txt_wrap_by("<!--","-->",page)
s = re.findall(r'<!--(.*?)-->',page,re.S)
w = re.findall(r'[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]',s[0])

print ''.join(w.__iter__())