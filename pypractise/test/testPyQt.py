#encoding:utf8

'''
Created on 2014年10月11日

@author: Daniel.Lee
'''
import sys
from PyQt4 import QtGui
 
app = QtGui.QApplication(sys.argv)
widget = QtGui.QWidget()
widget.resize(250, 150)
widget.setWindowTitle('PyQt')
widget.show()
sys.exit(app.exec_())