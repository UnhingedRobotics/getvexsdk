CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -I/usr/include/nlohmann
LDFLAGS := -lcurl -lzip

TARGET := check_sdk
SOURCES := check_sdk.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

