CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC := $(shell find . -name "*.cpp")
OBJ := $(SRC:.cpp=.o)

TARGET = a

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all

.PHONY: all clean re