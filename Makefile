.PHONY: all clean

CXXFLAGS += -std=c++20 -Wall -pedantic -Werror

EXECUTABLES=$(basename $(wildcard *.cpp))

all: $(EXECUTABLES)

clean:
	rm -f $(EXECUTABLES)


