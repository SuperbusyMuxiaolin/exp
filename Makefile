#############################################################################
# Makefile for building: lpl
# Generated by qmake (2.01a) (Qt 4.7.1) on: ?? 4? 16 22:06:31 2024
# Project:  lpl.pro
# Template: app
# Command: /opt/qt-4.7.1/bin/qmake -o Makefile lpl.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gcc
CXX           = arm-linux-g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/qt-4.7.1/mkspecs/default -I. -I/opt/qt-4.7.1/include/QtCore -I/opt/qt-4.7.1/include/QtNetwork -I/opt/qt-4.7.1/include/QtGui -I/opt/qt-4.7.1/include -I. -I. -I.
LINK          = arm-linux-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/opt/qt-4.7.1/lib
LIBS          = $(SUBLIBS)  -L/opt/qt-4.7.1/lib -lQtGui -L/usr/local/tslib/lib -L/opt/qt-4.7.1/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-linux-ar cqs
RANLIB        = 
QMAKE         = /opt/qt-4.7.1/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		qt1.cpp \
		camera.cpp \
		historyr.cpp \
		logwidget.cpp moc_qt1.cpp \
		moc_historyr.cpp \
		moc_logwidget.cpp
OBJECTS       = main.o \
		qt1.o \
		camera.o \
		historyr.o \
		logwidget.o \
		moc_qt1.o \
		moc_historyr.o \
		moc_logwidget.o
DIST          = /opt/qt-4.7.1/mkspecs/common/g++.conf \
		/opt/qt-4.7.1/mkspecs/common/unix.conf \
		/opt/qt-4.7.1/mkspecs/common/linux.conf \
		/opt/qt-4.7.1/mkspecs/common/qws.conf \
		/opt/qt-4.7.1/mkspecs/qconfig.pri \
		/opt/qt-4.7.1/mkspecs/features/qt_functions.prf \
		/opt/qt-4.7.1/mkspecs/features/qt_config.prf \
		/opt/qt-4.7.1/mkspecs/features/exclusive_builds.prf \
		/opt/qt-4.7.1/mkspecs/features/default_pre.prf \
		/opt/qt-4.7.1/mkspecs/features/release.prf \
		/opt/qt-4.7.1/mkspecs/features/default_post.prf \
		/opt/qt-4.7.1/mkspecs/features/warn_on.prf \
		/opt/qt-4.7.1/mkspecs/features/qt.prf \
		/opt/qt-4.7.1/mkspecs/features/unix/thread.prf \
		/opt/qt-4.7.1/mkspecs/features/moc.prf \
		/opt/qt-4.7.1/mkspecs/features/resources.prf \
		/opt/qt-4.7.1/mkspecs/features/uic.prf \
		/opt/qt-4.7.1/mkspecs/features/yacc.prf \
		/opt/qt-4.7.1/mkspecs/features/lex.prf \
		/opt/qt-4.7.1/mkspecs/features/include_source_dir.prf \
		lpl.pro
QMAKE_TARGET  = lpl
DESTDIR       = 
TARGET        = lpl

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_qt1.h ui_historyr.h ui_logwidget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: lpl.pro  /opt/qt-4.7.1/mkspecs/default/qmake.conf /opt/qt-4.7.1/mkspecs/common/g++.conf \
		/opt/qt-4.7.1/mkspecs/common/unix.conf \
		/opt/qt-4.7.1/mkspecs/common/linux.conf \
		/opt/qt-4.7.1/mkspecs/common/qws.conf \
		/opt/qt-4.7.1/mkspecs/qconfig.pri \
		/opt/qt-4.7.1/mkspecs/features/qt_functions.prf \
		/opt/qt-4.7.1/mkspecs/features/qt_config.prf \
		/opt/qt-4.7.1/mkspecs/features/exclusive_builds.prf \
		/opt/qt-4.7.1/mkspecs/features/default_pre.prf \
		/opt/qt-4.7.1/mkspecs/features/release.prf \
		/opt/qt-4.7.1/mkspecs/features/default_post.prf \
		/opt/qt-4.7.1/mkspecs/features/warn_on.prf \
		/opt/qt-4.7.1/mkspecs/features/qt.prf \
		/opt/qt-4.7.1/mkspecs/features/unix/thread.prf \
		/opt/qt-4.7.1/mkspecs/features/moc.prf \
		/opt/qt-4.7.1/mkspecs/features/resources.prf \
		/opt/qt-4.7.1/mkspecs/features/uic.prf \
		/opt/qt-4.7.1/mkspecs/features/yacc.prf \
		/opt/qt-4.7.1/mkspecs/features/lex.prf \
		/opt/qt-4.7.1/mkspecs/features/include_source_dir.prf \
		/opt/qt-4.7.1/lib/libQtGui.prl \
		/opt/qt-4.7.1/lib/libQtNetwork.prl \
		/opt/qt-4.7.1/lib/libQtCore.prl
	$(QMAKE) -o Makefile lpl.pro
/opt/qt-4.7.1/mkspecs/common/g++.conf:
/opt/qt-4.7.1/mkspecs/common/unix.conf:
/opt/qt-4.7.1/mkspecs/common/linux.conf:
/opt/qt-4.7.1/mkspecs/common/qws.conf:
/opt/qt-4.7.1/mkspecs/qconfig.pri:
/opt/qt-4.7.1/mkspecs/features/qt_functions.prf:
/opt/qt-4.7.1/mkspecs/features/qt_config.prf:
/opt/qt-4.7.1/mkspecs/features/exclusive_builds.prf:
/opt/qt-4.7.1/mkspecs/features/default_pre.prf:
/opt/qt-4.7.1/mkspecs/features/release.prf:
/opt/qt-4.7.1/mkspecs/features/default_post.prf:
/opt/qt-4.7.1/mkspecs/features/warn_on.prf:
/opt/qt-4.7.1/mkspecs/features/qt.prf:
/opt/qt-4.7.1/mkspecs/features/unix/thread.prf:
/opt/qt-4.7.1/mkspecs/features/moc.prf:
/opt/qt-4.7.1/mkspecs/features/resources.prf:
/opt/qt-4.7.1/mkspecs/features/uic.prf:
/opt/qt-4.7.1/mkspecs/features/yacc.prf:
/opt/qt-4.7.1/mkspecs/features/lex.prf:
/opt/qt-4.7.1/mkspecs/features/include_source_dir.prf:
/opt/qt-4.7.1/lib/libQtGui.prl:
/opt/qt-4.7.1/lib/libQtNetwork.prl:
/opt/qt-4.7.1/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile lpl.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/lpl1.0.0 || $(MKDIR) .tmp/lpl1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/lpl1.0.0/ && $(COPY_FILE) --parents dlinklist.h qt1.h dlinklist.c historyr.h logwidget.h Resistor.h .tmp/lpl1.0.0/ && $(COPY_FILE) --parents main.cpp qt1.cpp camera.cpp historyr.cpp logwidget.cpp .tmp/lpl1.0.0/ && $(COPY_FILE) --parents qt1.ui historyr.ui logwidget.ui .tmp/lpl1.0.0/ && (cd `dirname .tmp/lpl1.0.0` && $(TAR) lpl1.0.0.tar lpl1.0.0 && $(COMPRESS) lpl1.0.0.tar) && $(MOVE) `dirname .tmp/lpl1.0.0`/lpl1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/lpl1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_qt1.cpp moc_historyr.cpp moc_logwidget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_qt1.cpp moc_historyr.cpp moc_logwidget.cpp
moc_qt1.cpp: camera.h \
		ui_qt1.h \
		Resistor.h \
		historyr.h \
		logwidget.h \
		qt1.h
	/opt/qt-4.7.1/bin/moc $(DEFINES) $(INCPATH) qt1.h -o moc_qt1.cpp

moc_historyr.cpp: historyr.h
	/opt/qt-4.7.1/bin/moc $(DEFINES) $(INCPATH) historyr.h -o moc_historyr.cpp

moc_logwidget.cpp: logwidget.h
	/opt/qt-4.7.1/bin/moc $(DEFINES) $(INCPATH) logwidget.h -o moc_logwidget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_qt1.h ui_historyr.h ui_logwidget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_qt1.h ui_historyr.h ui_logwidget.h
ui_qt1.h: qt1.ui
	/opt/qt-4.7.1/bin/uic qt1.ui -o ui_qt1.h

ui_historyr.h: historyr.ui
	/opt/qt-4.7.1/bin/uic historyr.ui -o ui_historyr.h

ui_logwidget.h: logwidget.ui
	/opt/qt-4.7.1/bin/uic logwidget.ui -o ui_logwidget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp qt1.h \
		camera.h \
		ui_qt1.h \
		Resistor.h \
		historyr.h \
		logwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

qt1.o: qt1.cpp qt1.h \
		camera.h \
		ui_qt1.h \
		Resistor.h \
		historyr.h \
		logwidget.h \
		dlinklist.c \
		dlinklist.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qt1.o qt1.cpp

camera.o: camera.cpp camera.h \
		yuv2rgb.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camera.o camera.cpp

historyr.o: historyr.cpp historyr.h \
		ui_historyr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o historyr.o historyr.cpp

logwidget.o: logwidget.cpp logwidget.h \
		ui_logwidget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o logwidget.o logwidget.cpp

moc_qt1.o: moc_qt1.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qt1.o moc_qt1.cpp

moc_historyr.o: moc_historyr.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_historyr.o moc_historyr.cpp

moc_logwidget.o: moc_logwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_logwidget.o moc_logwidget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

