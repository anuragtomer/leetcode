SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.cpp,%.o,$(SRC_FILES))
CPPFLAGS := -std=c++14

main.exe: $(OBJ_FILES)
		g++ -o $@ $^

%.o: %.cpp
		g++ $(CPPFLAGS) -c -o $@ $<

clean:
	    rm *.exe
	    rm *.o
