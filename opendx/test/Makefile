CXX = g++ `libsdldx-config --cflags`
LIBS = `libsdldx-config --libs`
OBJS = msdn_test.o

default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o msdn_test
clean:
	rm -f msdn_test
	rm -f *.o
	rm -f *~
