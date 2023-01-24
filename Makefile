# Headers
HEADERS += main.h
HEADERS += window.h

# Objects
OBJECTS += main.o
OBJECTS += window.o

# Target
TARGET += $(BIN_DIR)/engine

# Compiler and other variables
CXX = g++
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin
CFLAGS = -g -Wall

LINKING = -ldl -lglfw

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