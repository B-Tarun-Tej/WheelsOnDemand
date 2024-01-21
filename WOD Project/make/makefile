CC := g++
CXXFLAGS := -std=c++11 -Wall -g
INCLUDE_DIR := ./../include
SRC_DIR := ./../src
OBJ_DIR := ./../obj
BIN_DIR := ./../bin
TEST_DIR := ./../test

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))

# Target executables
TARGET := $(BIN_DIR)/my_program
TEST_TARGET := $(BIN_DIR)/test_program

# Default target
all: $(TARGET)

# Rule to link the main executable
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

# Rule to compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<


# Rule to link the test executable
test: $(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^


# Rule to compile test source files to object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Clean rule
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

