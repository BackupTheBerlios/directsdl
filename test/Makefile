CXX = g++ `libds-config --cflags`
LIBS = `libds-config --libs`
OBJS = msdn_test.o

default: $(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o msdn_test
clean:
	rm -f msdn_test
