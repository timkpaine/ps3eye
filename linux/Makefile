
TARGET1 := part1
TARGET2 := part2

CXX = g++

SOURCES1 := ./src/main_part1.cpp
SOURCES2 := ./src/context.cpp ./src/frame_function.cpp ./src/ps3eye.cpp ./src/main_part2.cpp
OBJECTS1 := $(patsubst %.cpp,%.o,$(SOURCES1))
OBJECTS2 := $(patsubst %.cpp,%.o,$(SOURCES2))


SDL_INC=-I/usr/local/include/SDL2
USB_INC=-I/usr/local/include/libusb-1.0

CXXFLAGS := -std=c++11 -g -Wall
CXXFLAGS += -I./include -I./hw/include
CXXFLAGS += $(SDL_INC)
CXXFLAGS += $(USB_INC)


LIBS := -L/usr/local/lib
LIBS += $(shell pkg-config --libs libusb-1.0)
LIBS += $(shell sdl2-config --libs)
LIBS += $(shell pkg-config --libs opencv)

.DEFAULT_TARGET := $(TARGET1)
$(TARGET1): $(OBJECTS1)
	$(CXX) -o $@ $(OBJECTS1) $(LIBS)

$(TARGET2): $(OBJECTS2)
	$(CXX) -o $@ $(OBJECTS2) $(LIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf *.o *~ part1 part2 *.dSYM src/*.o
