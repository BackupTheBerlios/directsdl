# Makefile for ds_winapi.so
# (C)2004 Sebastian Steinhauer

# the GNU C++ compiler
CXX = g++ `sdl-config --cflags` `pkg-config --cflags gtk+-2.0` -O3

# needed libs
LIBS = `sdl-config --libs` `pkg-config --libs gtk+-2.0`

# objects
OBJS = windows.o gtkfunctions.o

# the default :)
default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -Wl,--shared -o libds_winapi.so

install: default
	cp libds_winapi.so /usr/local/lib/
	mkdir -p /usr/local/include/DirectSDL
	cp windows.h /usr/local/include/DirectSDL/
	
clean:
	rm *.o -f
	rm *.so -f
	rm *~ -f
