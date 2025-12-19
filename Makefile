.PHONY: all clean

CXXFLAGS += -std=c++20 -Wall -pedantic -Werror

EXECUTABLES=$(basename $(wildcard *.cpp))

all: $(EXECUTABLES)

num_hist.cpp: parser.h
	touch $@

clean:
	rm -f $(EXECUTABLES)


