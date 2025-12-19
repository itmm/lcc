.PHONY: all clean

CXXFLAGS += -Wall -pedantic -Werror

EXECUTABLES=$(basename $(wildcard *.cpp))

all: $(EXECUTABLES)

clean:
	rm -f $(EXECUTABLES)


