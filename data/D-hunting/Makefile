CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : validator.exec std.exec csy.exec spj-hduoj.exec
	./validator.exec < d.in
	time ./std.exec < d.in | ./spj-hduoj.exec d.in | diff - d.out
	time ./csy.exec < d.in | ./spj-hduoj.exec d.in | diff - d.out
