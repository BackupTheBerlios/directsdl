CXX = g++ `sdl-config --cflags` -O3 -I/usr/local/include/DirectSDL/
LIBS = `sdl-config --libs` -lds_winapi -lds_dxcore -lds_ddraw
OBJS = msdn_test.o

default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o msdn_test -Wl,-static
	
