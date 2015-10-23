'''
Created on Nov 19, 2014

@author: Daniel.Lee
'''
import urllib.request

msg = 'I am a msg that sent to Twitter!'
pwd_manager = urllib.request.HTTPPasswordMgr()
pwd_manager.add_password("Twitter API", "http://twitter.com/statuses", "DannyInHG@gmail.com", "laCorse1990911")
http_handler = urllib.request.HTTPBasicAuthHandler(pwd_manager)
page_opener = urllib.request.build_opener(http_handler)
urllib.request.install_opener(page_opener)
params = urllib.parse.urlencode({'message':msg})
resp = urllib.request.urlopen("https://twitter.com/statuses/update.json",params)
text = resp.read()
print(text)