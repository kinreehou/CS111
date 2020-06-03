CXX = g++
CXXFLAGS = -Wall -Werror -Wno-self-assign-overloaded -std=c++11
TEST_OBJS = rational.o testbase.o test-rational.o

all : test-rational

test: test-rational
	./test-rational

test-rational: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $@ $(LDFLAGS)

doc:
	doxygen

clean:
	rm -rf test-rational *.o *~

.PHONY: all clean test