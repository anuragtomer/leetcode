echo "# Compile and run by \"make <program_name>\"" > test_makefile
echo "# For example, typing \"make parity\" in your terminal will compile and run parity.cc." >> test_makefile
echo "#" >> test_makefile
echo "# You could try \"make last\" (or simply \"make\"), this command will compile and run the last modified file." >> test_makefile
echo "# This comes pretty handy while you are working a problem, and then you want to see the result soon without thinking program name." >> test_makefile
echo "BUILD_DIR := cpp_build" >> test_makefile
echo "SRC_DIR := ." >> test_makefile
echo "TEST_DATA_DIR := ../test_data" >> test_makefile
echo "" >> test_makefile
echo "# Modify this line if you want to pass custom arguments" >> test_makefile
echo "PROGRAM_ARGS := --test-data-dir \$(TEST_DATA_DIR) " >> test_makefile
echo "" >> test_makefile
echo "CXX_COMPILER := clang++" >> test_makefile
echo "CXX_FLAGS := -std=c++17 -pthread -Werror -Wno-unused-variable -Wno-sign-compare" >> test_makefile
echo "CXX_FLAGS_DEBUG := \$(CXX_FLAGS) -g -O0" >> test_makefile
echo "" >> test_makefile
echo "LAST_MODIFIED_CXX_FILE = \$(shell ls -rt \$(SRC_DIR)/*\.cpp | tail -1)" >> test_makefile
echo "" >> test_makefile
echo "" >> test_makefile
echo "# Compile and run the last modified file." >> test_makefile
echo "last: \$(notdir \$(basename \$(LAST_MODIFIED_CXX_FILE)))" >> test_makefile
echo "" >> test_makefile
echo ".PHONY: last" >> test_makefile
echo "" >> test_makefile
echo "\$(BUILD_DIR):" >> test_makefile
echo "	mkdir -p \$(BUILD_DIR)" >> test_makefile
echo "" >> test_makefile
echo "" >> test_makefile
$(ls *.cpp | sort -n -r -o sorted.files)
for file in `cat sorted.files`;
do
    echo "# $file" >> test_makefile
	echo "" >> test_makefile
	echo "\$(BUILD_DIR)/$(basename $file .cpp): \$(SRC_DIR)/$file | \$(BUILD_DIR)" >> test_makefile
	echo "	\$(CXX_COMPILER) \$(CXX_FLAGS_DEBUG) -o \$@ \$<" >> test_makefile
	echo "$(basename $file .cpp): \$(BUILD_DIR)/$(basename $file .cpp)" >> test_makefile
	echo "	\$<" >> test_makefile
	echo "" >> test_makefile
	echo ".PHONY: $(basename $file .cpp)" >> test_makefile
	echo "" >> test_makefile
	echo "" >> test_makefile
done

echo "all: \\" >> test_makefile
for file in `cat sorted.files`;
do
    echo "    \$(BUILD_DIR)/$(basename $file .cpp)\\" >> test_makefile
done
echo "    \$(BUILD_DIR)/none" >> test_makefile
echo "" >> test_makefile
echo "" >> test_makefile
echo "clean:" >> test_makefile
echo "	rm -r \$(BUILD_DIR)" >> test_makefile
echo "" >> test_makefile
echo ".PHONY: all clean" >> test_makefile
