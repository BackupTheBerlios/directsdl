# Makefile for sdldx
# (C)2004 sdldx team

SHELL = /bin/bash

# the GNU C++ compiler
CXX = g++ `sdl-config --cflags` `pkg-config --cflags gtk+-2.0` -O3

# needed libs
LIBS = `sdl-config --libs` `pkg-config --libs gtk+-2.0`

# objects
OBJS = notimplemented.o windows.o gtkfunctions.o iunknown.o idirectdraw.o idirectdrawsurface.o tools.o core.o init.o

# the default :)
default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -shared -fPIC -o libsdldx.so

install: default
	cp libsdldx.so /usr/local/lib/
	mkdir -p /usr/local/include/sdldx
	cp *.h /usr/local/include/sdldx/
	cp libsdldx-config /usr/local/bin/

uninstall:
	rm -rf /usr/local/lib/libsdldx.so /usr/local/include/sdldx /usr/local/bin/libsdldx-config
	
clean:
	rm *.o *.so *~ sdldx*.tar.bz2 -f
	rm test/*.o test/*.so test/*~ test/msdn_test -f

snapshot: clean
	rm -rf sdldx
	mkdir sdldxsnapshot
	cp -r `/bin/ls|grep -v sdldxsnapshot` sdldxsnapshot/
	mv sdldxsnapshot sdldx
	tar cfS - -- sdldx | bzip2 --best > sdldx-`date "+%Y%m%d"`.tar.bz2
	rm -r sdldx
