CXX = g++ `libds-config --cflags`
OBJS = core.o id3d8.o

default: $(OBJS)
	$(CXX) $(OBJS) -o core 

clean:
	rm -f *~
	rm -f *.o

