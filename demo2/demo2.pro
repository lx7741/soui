######################################################################
# Automatically generated by qmake (3.0) ?? 7? 23 23:09:51 2019
######################################################################

TEMPLATE = app
TARGET = demo2
CONFIG(x64){
TARGET = $$TARGET"64"
}
DEPENDPATH += .
INCLUDEPATH += . \
			   ../utilities/include \
			   ../soui/include \
			   ../components
			   
dir = ..
include($$dir/common.pri)
#demo中使用了#import，不支持MP编译
QMAKE_CXXFLAGS -= /MP

CONFIG(debug,debug|release){
	LIBS += utilitiesd.lib souid.lib
}
else{
	LIBS += utilities.lib soui.lib
}


PRECOMPILED_HEADER = stdafx.h
RC_FILE += demo2.rc
RC_INCLUDE += ../soui-sys-resource

# Input
HEADERS += MainDlg.h resource.h  res/resource.h
SOURCES += demo2.cpp MainDlg.cpp
