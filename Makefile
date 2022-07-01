SRC_FILES := $(wildcard *.cpp)
SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.cpp,%.o,$(SRC_FILES))
CPPFLAGS := -std=c++17
SUBDIR_ROOTS := .
DIRS := . $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o *~ core *.out *.dSYM
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS)))
SRC_DIR := .
LAST_MODIFIED_CXX_FILE = $(shell ls -rt $(SRC_DIR)/*/*\.cpp | tail -1)
main.exe: $(OBJ_FILES)
	g++ -o $@ $^

%.o: %.cpp
	g++ $(CPPFLAGS) -c -o $@ $<

# Needs rework for last to work correctly.

last: $(notdir $(LAST_MODIFIED_CXX_FILE))

.PHONY: last

# Use this makefile for cleanup only. Others might not work as expected.

clean:
	rm -rf $(GARBAGE)


