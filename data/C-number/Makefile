CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : validator.exec std.exec table.exec
	./validator.exec < c.in
	time ./std.exec < c.in | diff - c.out
	time ./table.exec < c.in | diff - c.out
