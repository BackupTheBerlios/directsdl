# Makefile for ds_dxcore.so
# (C)2004 Sebastian Steinhauer

# the GNU C++ compiler
CXX = g++ `sdl-config --cflags` -O3

# needed libs
LIBS = `sdl-config --libs`

# objects
OBJS = core.o

# the default :)
default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -Wl,--shared -o libds_dxcore.so

install: default
	cp libds_dxcore.so /usr/local/lib/
	
clean:
	rm *.o -f
	rm *.so -f
	rm *~ -f
