TARGET := lib/libhw.dylib

# C++ Compiler
CXX := g++ 

# File endings
.SUFFIXES: .hpp .cpp .cc .h .c .o .opp .so

# C++ flags
CXXFLAGS :=
CXXFLAGS += -g -Wall
CXXFLAGS += -fPIC -std=c++11
CXXFLAGS += -I./include

CXX_HEADERS := include/hw1.h
CXX_HEADERS += include/hw2.h
CXX_SOURCES += src/hw2.cpp

CXX_OBJECTS := $(CXX_SOURCES:.cpp=.o)

.DEFAULT_GOAL := $(TARGET)
$(TARGET): $(CXX_OBJECTS)
	mkdir -p lib
	$(CXX) -shared src/*.o -o $(TARGET)

.cpp.o: $(CXX_HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf src/*.o $(TARGET) lib

.PHONY: clean run help
