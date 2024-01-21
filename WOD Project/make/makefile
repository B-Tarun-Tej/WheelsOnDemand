#*****************************************************************************************************
#                 2023 All copyrights reserved (Vehicle Rental System project)
#      Author      : Tarun Tej Barrenkala
#      FILENAME    : makefile
#      DESCRIPTION : This file contains all the dependecies and compilation commands of the source code
#*****************************************************************************************************/ 

CC := g++
CXXFLAGS := -std=c++11 -Wall -g
INCLUDE_DIR := ./../include
SRC_DIR := ./../src
OBJ_DIR := ./../obj
BIN_DIR := ./../bin

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Target executable
TARGET := $(BIN_DIR)/my_program

# Default target
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $^

# Rule to compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

# Create necessary directories
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Clean up intermediate files and the executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

