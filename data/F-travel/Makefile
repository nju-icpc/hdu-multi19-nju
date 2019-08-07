CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : validator.exec std.exec
	./validator.exec < f.in
	ulimit -s unlimited && time ./std.exec < f.in | diff - f.out
