# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Executable name
TARGET = poker_simulator

# Source files
SRCS = src/poker.cpp src/Table.cpp src/Card.cpp src/Player.cpp src/PlayerHand.cpp src/FiveCardHand.cpp

# Header files
HEADERS = include/Table.h include/Card.h include/Player.h include/PlayerHand.h include/FiveCardHand.h 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)