all: compile

compile: prog

prog: main.cpp
	mpicxx -std=c++11 $(CXXFLAGS) -I.. $< -o $@

clean:
	rm -f prog
