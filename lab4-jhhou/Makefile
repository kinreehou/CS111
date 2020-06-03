CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
CONVERT_OBJS = units.o convert.o
TEST_OBJS = units.o testbase.o hw3testunits.o

all : convert hw3testunits 

convert: $(CONVERT_OBJS)
	$(CXX) $(CXXFLAGS) $(CONVERT_OBJS) -o $@ $(LDFLAGS)


hw3testunits: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $@ $(LDFLAGS)

test: hw3testunits
	./hw3testunits

doc:
	doxygen

clean:
	rm -rf convert hw3testunits docs *.o *~

.PHONY: all test doc clean