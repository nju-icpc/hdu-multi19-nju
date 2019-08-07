CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : validator.exec std.exec
	./validator.exec < g.in
	time ./std.exec < g.in | diff - g.out
