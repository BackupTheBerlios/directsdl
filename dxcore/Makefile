# Makefile for ds_dxcore.so
# (C)2004 Sebastian Steinhauer

# the GNU C++ compiler
CXX = g++ `sdl-config --cflags` `pkg-config --cflags gtk+-2.0` -O3 -I/usr/local/include/DirectSDL/

# needed libs
LIBS = `sdl-config --libs` `pkg-config --libs gtk+-2.0`

# objects
OBJS = core.o

# the default :)
default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -Wl,--shared -o libds_dxcore.so

install: default
	cp libds_dxcore.so /usr/local/lib/
	cp libds-config /usr/local/bin/
	
clean:
	rm *.o -f
	rm *.so -f
	rm *~ -f
