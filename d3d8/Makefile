CXX = g++ `libds-config --cflags`
OBJS = core.o id3d8.o id3ddevice.o
LIBS = `libds-config --libs`

default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o core 

clean:
	rm -f *~
	rm -f *.o

