# Headers
HEADERS += window.h
HEADERS += inputManager.h
HEADERS += vector2.h
HEADERS += vector3.h
HEADERS += vector4.h
HEADERS += triangle.h
HEADERS += glad.h
HEADERS += khrplatform.h
HEADERS += shader.h
HEADERS += shaderProgram.h
HEADERS += ioManager.h

# Objects
OBJECTS += main.o
OBJECTS += window.o
OBJECTS += inputManager.o
OBJECTS += triangle.o
OBJECTS += glad.o
OBJECTS += shader.o
OBJECTS += shaderProgram.o
OBJECTS += ioManager.o

# Target
TARGET += $(BIN_DIR)/engine

# Compiler and other variables
CXX = g++
CC = gcc
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin
CFLAGS = -g -Wall

LINKING = -ldl -lglfw -lglut -lGL

# Default Target
all: $(BIN_DIR) $(TARGET)

# Build
%.o : %.cpp $(HEADERS)
	$(CXX) -c $(CFLAGS) $<

# Binaries
$(TARGET) : $(OBJECTS)
	$(CXX) $(CFLAGS) -o $@ $(OBJECTS) $(LINKING)
	$(RM_DIR) $(OBJECTS)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

.PHONY: clean
clean :
	$(RM_DIR) $(BIN_DIR) $(OBJECTS)