# Makefile for daxpy_loop

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -fopenmp
LDFLAGS = -fopenmp

# Source and object files
SRC = daxy_loop.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = daxy_loop

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

# Compiling
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Cleaning
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets
.PHONY: all clean
