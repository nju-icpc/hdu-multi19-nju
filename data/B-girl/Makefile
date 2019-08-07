CXX = g++
CXXFLAGS = -O2 -Wall -ggdb -std=c++11

.DEFAULT_GOAL = test
.PHONY: test

%.exec : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

test : validator.exec std.exec zyb.exec
	./validator.exec < b.in
	time ./std.exec < b.in | diff - b.out
	time ./zyb.exec < b.in | diff - b.out
