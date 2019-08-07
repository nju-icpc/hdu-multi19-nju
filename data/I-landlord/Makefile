CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : mk.exec validator.exec std.exec std-csy.exec
	./mk.exec | diff - i.in
	./validator.exec < i.in
	time ./std.exec < i.in | diff - i.out
	time ./std-csy.exec < i.in | diff - i.out
