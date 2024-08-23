# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# SDL2 flags (adjust paths if necessary)
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs)

# Directories
SRC_DIR := src
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/bin
EXTERNAL_DIR := external

# Find all .c files in the src directory and its subdirectories
SRCS := $(shell find $(SRC_DIR) -name '*.c')

# Generate object file names
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Main target
TARGET := flappy_bird_main

# Include directories
INCLUDES := -I$(SRC_DIR) -I$(EXTERNAL_DIR) $(SDL_CFLAGS)

# Default target
all: $(BIN_DIR)/$(TARGET)

# Link object files to create the executable
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(SDL_LIBS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
