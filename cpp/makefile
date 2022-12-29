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


# 270.palindrome-permutation.cpp

$(BUILD_DIR)/266.palindrome-permutation: $(SRC_DIR)/266.palindrome-permutation.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
266.palindrome-permutation: $(BUILD_DIR)/266.palindrome-permutation
	$<

.PHONY: 266.palindrome-permutation


# 252.meeting-rooms.cpp

$(BUILD_DIR)/252.meeting-rooms: $(SRC_DIR)/252.meeting-rooms.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
252.meeting-rooms: $(BUILD_DIR)/252.meeting-rooms
	$<

.PHONY: 252.meeting-rooms


# 243.shortest-word-distance.cpp

$(BUILD_DIR)/243.shortest-word-distance: $(SRC_DIR)/243.shortest-word-distance.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
243.shortest-word-distance: $(BUILD_DIR)/243.shortest-word-distance
	$<

.PHONY: 243.shortest-word-distance


# 170.two-sum-iii-data-structure-design.cpp

$(BUILD_DIR)/170.two-sum-iii-data-structure-design: $(SRC_DIR)/170.two-sum-iii-data-structure-design.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
170.two-sum-iii-data-structure-design: $(BUILD_DIR)/170.two-sum-iii-data-structure-design
	$<

.PHONY: 170.two-sum-iii-data-structure-design


# 163.missing-ranges.cpp

$(BUILD_DIR)/163.missing-ranges: $(SRC_DIR)/163.missing-ranges.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
163.missing-ranges: $(BUILD_DIR)/163.missing-ranges
	$<

.PHONY: 163.missing-ranges


# 157.read-n-characters-given-read4.cpp

$(BUILD_DIR)/157.read-n-characters-given-read4: $(SRC_DIR)/157.read-n-characters-given-read4.cpp | $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS_DEBUG) -o $@ $<
157.read-n-characters-given-read4: $(BUILD_DIR)/157.read-n-characters-given-read4
	$<

.PHONY: 157.read-n-characters-given-read4


all: \
    $(BUILD_DIR)/422.valid-word-square \
	$(BUILD_DIR)/359.logger-rate-limiter \
	$(BUILD_DIR)/346.moving-average-from-data-stream \
	$(BUILD_DIR)/270.closest-binary-search-tree-value \
	$(BUILD_DIR)/266.palindrome-permutation \
	$(BUILD_DIR)/252.meeting-rooms \
	$(BUILD_DIR)/243.shortest-word-distance \
	$(BUILD_DIR)/170.two-sum-iii-data-structure-design \
	$(BUILD_DIR)/163.missing-ranges \
	$(BUILD_DIR)/157.read-n-characters-given-read4


clean:
	rm -r $(BUILD_DIR)

.PHONY: all clean
