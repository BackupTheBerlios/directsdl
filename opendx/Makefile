# Makefile for opendx 
# (C)2004 opendx team

SHELL = /bin/bash

# the GNU C++ compiler
CXX = g++ `sdl-config --cflags` `pkg-config --cflags gtk+-2.0` -O3

# needed libs
LIBS = `sdl-config --libs` `pkg-config --libs gtk+-2.0`

# objects
OBJS = notimplemented.o windows.o gtkfunctions.o iunknown.o idirectdraw.o idirectdrawsurface.o tools.o core.o init.o

# the default :)
default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -shared -fPIC -o libopendx.so

install: default
	cp libopendx.so /usr/local/lib/
	mkdir -p /usr/local/include/opendx
	cp *.h /usr/local/include/opendx/
	cp libopendx-config /usr/local/bin/

uninstall:
	rm -rf /usr/local/lib/libopendx.so /usr/local/include/opendx /usr/local/bin/libopendx-config
	
clean:
	rm *.o *.so *~ opendx*.tar.bz2 -f
	rm test/*.o test/*.so test/*~ test/msdn_test -f

snapshot: clean
	rm -rf opendx
	mkdir opendxsnapshot
	cp -r `/bin/ls|grep -v opendxsnapshot` opendxsnapshot/
	mv opendxsnapshot opendx
	tar cfS - -- opendx | bzip2 --best > opendx-`date "+%Y%m%d"`.tar.bz2
	rm -r opendx
