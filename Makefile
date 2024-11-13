# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Targets
SOURCES = assignment3A.cpp  # Change this to your actual file name
DEBUG_TARGET = railway_debug
RELEASE_TARGET = optimize

# Debug build
debug: $(SOURCES)
	$(CXX) $(CXXFLAGS) -g -o $(DEBUG_TARGET) $(SOURCES)

# Release build
optimize: $(SOURCES)
	$(CXX) $(CXXFLAGS) -O2 -o $(RELEASE_TARGET) $(SOURCES)

# Build both targets
all: debug optimize

# Clean up binaries
clean:
	rm -f $(DEBUG_TARGET) $(RELEASE_TARGET)
