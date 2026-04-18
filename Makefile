CXX = g++
CXXFLAGS = -std=c++17 -O2 -Iinclude

SRC = src/main.cpp src/matrix.cpp src/systolic.cpp src/pe.cpp src/utils.cpp
OUT = mini_tpu

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)