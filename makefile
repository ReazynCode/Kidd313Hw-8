# --- HW#8/makefile ------------------------------------------
CXXFLAGS = -std=c++17 -O2   
CFLAGS   = -std=c99   -O2

.PHONY: all cpp c clean
all: cpp c

cpp:              
	$(CXX) $(CXXFLAGS) Matrix.cpp main.cpp -o test_cpp

c:              
	$(CC)  $(CFLAGS)  matrix.c main.c  -o test_c

clean:
	rm -f test_cpp test_c

