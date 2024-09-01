# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# SDL2 and SDL2_image paths
SDL2_PATH := /opt/homebrew/Cellar/sdl2/2.30.6
SDL2_IMAGE_PATH := /opt/homebrew/Cellar/sdl2_image/2.8.2_1

# SDL2 and SDL2_image flags
SDL_CFLAGS := -I$(SDL2_PATH)/include/SDL2 -I$(SDL2_IMAGE_PATH)/include/SDL2
SDL_LIBS := -L$(SDL2_PATH)/lib -L$(SDL2_IMAGE_PATH)/lib -lSDL2 -lSDL2_image

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
