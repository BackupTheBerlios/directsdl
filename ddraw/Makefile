# Makefile for ds_ddraw.so
# (C)2004 Sebastian Steinhauer

# the GNU C++ compiler
CXX = g++ `sdl-config --cflags` -O3 -I/usr/local/include/DirectSDL/

# needed libs
LIBS = `sdl-config --libs`

# objects
OBJS = iunknown.o idirectdraw.o idirectdrawsurface.o tools.o core.o

# the default :)
default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -Wl,--shared,-s -o libds_ddraw.so

install: default
	cp libds_ddraw.so /usr/local/lib/
	mkdir /usr/local/include/DirectSDL -p
	cp *.h /usr/local/include/DirectSDL/
	
clean:
	rm *.o -f
	rm *.so -f
	rm *~ -f
