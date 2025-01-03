# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -I"C:/path/to/nlohmann/include"

# Libraries and linker flags
LDFLAGS := -lcurl -lzip -L"C:/path/to/curl/lib" -L"C:/path/to/zip/lib"

# Target and source files
TARGET := check_sdk
SOURCES := check_sdk.cpp

# Executable file extension for Windows
EXECUTABLE := $(TARGET).exe

# Default target
all: $(EXECUTABLE)
	./$(EXECUTABLE)

# Build the target
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

# Clean target
clean:
	del /f $(EXECUTABLE)
