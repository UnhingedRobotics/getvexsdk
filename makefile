# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -fPIC
LDFLAGS = -lcurl -lzip

# Targets
TARGET = libcheck_sdk.so
SOURCES = check_sdk.cpp
HEADERS = check_sdk.hpp

# Build the shared library
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -shared -o $(TARGET) $(SOURCES) $(LDFLAGS)

# Clean up build artifacts
clean:
	rm -f $(TARGET)
