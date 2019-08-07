CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : validator.exec std.exec
	./validator.exec < h.in
	time ./std.exec < h.in | diff - h.out
	time ./std.exec < h.in | diff - h.out
	time ./std.exec < h.in | diff - h.out
