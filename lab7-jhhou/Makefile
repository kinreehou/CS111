CXX = g++
CXXFLAGS = -Wall -Werror  -Wno-self-assign-overloaded -std=c++11

all : test-matrix

test: test-matrix
	./test-matrix

test-matrix: matrix.o testbase.o test-matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf test-matrix *.o *~

.PHONY: all clean test