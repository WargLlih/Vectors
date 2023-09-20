# Compiler options
CC := g++
CFLAGS := -Wall -Wextra

# Source directory
SRC_DIR := src

# Build directory
BUILD_DIR := build

# Find all .cpp files recursively in the source directory and its subdirectories
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Generate the list of corresponding object files
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Target executable
TARGET := vector.out

# Default rule to build the executable
all: $(TARGET)

# Rule to create the build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# Rule to compile each .cpp file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link the object files and build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean rule to remove object files and the executable
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)