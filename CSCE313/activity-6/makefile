CXX=g++
CXXFLAGS=-std=c++17 -g -pedantic -Wall -Wextra -Werror -fsanitize=address,undefined -fno-omit-frame-pointer


SRCS=main.cpp sort.cpp 
BINS=$(patsubst %.cpp,%.exe,$(SRCS))
DEPS=


all: clean $(BINS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.exe: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -o $(patsubst %.exe,%,$@) $^


.PHONY: clean

clean:
	rm -f main
	rm -f sort
	rm -f trace.tst

test: all
	chmod u+x quiz1-tests.sh
	./quiz1-tests.sh