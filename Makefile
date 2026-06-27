CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC := $(shell find . -name "*.cpp" \
    ! -name "win32.cpp" \
    ! -name "x11.cpp" \
    ! -name "Platform.cpp")

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    SRC += modules/Window/Platform/sources/x11.cpp
    LIBS = -lX11 -lXrandr -lvulkan
else
    SRC += modules/Window/Platform/sources/win32.cpp
    LIBS =
endif

OBJ := $(SRC:.cpp=.o)
TARGET = a

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all

.PHONY: all clean re