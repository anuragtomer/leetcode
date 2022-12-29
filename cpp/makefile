# Compile and run by "make <program_name>"
# For example, typing "make parity" in your terminal will compile and run parity.cc.
#
# You could try "make last" (or simply "make"), this command will compile and run the last modified file.
# This comes pretty handy while you are working a problem, and then you want to see the result soon without thinking program name.
BUILD_DIR := cpp_build
SRC_DIR := .
TEST_DATA_DIR := ../test_data

# Modify this line if you want to pass custom arguments
PROGRAM_ARGS := --test-data-dir $(TEST_DATA_DIR) 

CXX_COMPILER := clang++
CXX_FLAGS := -std=c++17 -pthread -Werror -Wno-unused-variable -Wno-sign-compare
CXX_FLAGS_DEBUG := $(CXX_FLAGS) -g -O0

LAST_MODIFIED_CXX_FILE = $(shell ls -rt $(SRC_DIR)/*\.cpp | tail -1)


# Compile and run the last modified file.
last: $(notdir $(basename $(LAST_MODIFIED_CXX_FILE)))

.PHONY: last

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


# 422.valid-word-square.cpp

$(BUILD_DIR)/422.valid-word-square: $(SRC_DIR)/422.valid-word-square.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
422.valid-word-square: $(BUILD_DIR)/422.valid-word-square
	$<

.PHONY: 422.valid-word-square


# 359.logger-rate-limiter.cpp

$(BUILD_DIR)/359.logger-rate-limiter: $(SRC_DIR)/359.logger-rate-limiter.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
359.logger-rate-limiter: $(BUILD_DIR)/359.logger-rate-limiter
	$<

.PHONY: 359.logger-rate-limiter


# 346.moving-average-from-data-stream.cpp

$(BUILD_DIR)/346.moving-average-from-data-stream: $(SRC_DIR)/346.moving-average-from-data-stream.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
346.moving-average-from-data-stream: $(BUILD_DIR)/346.moving-average-from-data-stream
	$<

.PHONY: 346.moving-average-from-data-stream


# 270.closest-binary-search-tree-value.cpp

$(BUILD_DIR)/270.closest-binary-search-tree-value: $(SRC_DIR)/270.closest-binary-search-tree-value.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
270.closest-binary-search-tree-value: $(BUILD_DIR)/270.closest-binary-search-tree-value
	$<

.PHONY: 270.closest-binary-search-tree-value


all: \
    $(BUILD_DIR)/422.valid-word-square \
	$(BUILD_DIR)/359.logger-rate-limiter \
	$(BUILD_DIR)/346.moving-average-from-data-stream \
	$(BUILD_DIR)/270.closest-binary-search-tree-value


clean:
	rm -r $(BUILD_DIR)

.PHONY: all clean
