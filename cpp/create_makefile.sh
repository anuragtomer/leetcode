echo "# Compile and run by \"make <program_name>\"" > makefile
echo "# For example, typing \"make parity\" in your terminal will compile and run parity.cc." >> makefile
echo "#" >> makefile
echo "# You could try \"make last\" (or simply \"make\"), this command will compile and run the last modified file." >> makefile
echo "# This comes pretty handy while you are working a problem, and then you want to see the result soon without thinking program name." >> makefile
echo "BUILD_DIR := cpp_build" >> makefile
echo "SRC_DIR := ." >> makefile
echo "TEST_DATA_DIR := ../test_data" >> makefile
echo "" >> makefile
echo "# Modify this line if you want to pass custom arguments" >> makefile
echo "PROGRAM_ARGS := --test-data-dir \$(TEST_DATA_DIR) " >> makefile
echo "" >> makefile
echo "CXX_COMPILER := clang++" >> makefile
echo "CXX_FLAGS := -std=c++17 -pthread -Werror -Wno-unused-variable -Wno-sign-compare" >> makefile
echo "CXX_FLAGS_DEBUG := \$(CXX_FLAGS) -g -O0" >> makefile
echo "" >> makefile
echo "LAST_MODIFIED_CXX_FILE = \$(shell ls -rt \$(SRC_DIR)/*\.cpp | tail -1)" >> makefile
echo "" >> makefile
echo "" >> makefile
echo "# Compile and run the last modified file." >> makefile
echo "last: \$(notdir \$(basename \$(LAST_MODIFIED_CXX_FILE)))" >> makefile
echo "" >> makefile
echo ".PHONY: last" >> makefile
echo "" >> makefile
echo "\$(BUILD_DIR):" >> makefile
echo "	mkdir -p \$(BUILD_DIR)" >> makefile
echo "" >> makefile
echo "" >> makefile
$(ls *.cpp | sort -n -r -o sorted.files)
for file in `cat sorted.files`;
do
    echo "# $file" >> makefile
	echo "" >> makefile
	echo "\$(BUILD_DIR)/$(basename $file .cpp): \$(SRC_DIR)/$file | \$(BUILD_DIR)" >> makefile
	echo "	\$(CXX_COMPILER) \$(CXX_FLAGS_DEBUG) -o \$@ \$<" >> makefile
	echo "$(basename $file .cpp): \$(BUILD_DIR)/$(basename $file .cpp)" >> makefile
	echo "	\$<" >> makefile
	echo "" >> makefile
	echo ".PHONY: $(basename $file .cpp)" >> makefile
	echo "" >> makefile
	echo "" >> makefile
done

echo "all: \\" >> makefile
for file in `cat sorted.files`;
do
    echo "    \$(BUILD_DIR)/$(basename $file .cpp) \\" >> makefile
done

echo "    \$(BUILD_DIR)/none" >> makefile
echo "" >> makefile
echo "" >> makefile
echo "clean:" >> makefile
echo "	rm -r \$(BUILD_DIR)" >> makefile
echo "" >> makefile
echo ".PHONY: all clean" >> makefile

# Delete temporary files
rm sorted.files