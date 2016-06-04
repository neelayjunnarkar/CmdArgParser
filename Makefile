BIN := target
CC := g++
CFLAGS := -std=c++14 -c

SRC_DIR := src
OBJ_DIR := obj
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

INCLUDE_DIRECTORIES :=

.PHONY: all clean

all: $(OBJS)
	$(CC) $(OBJS) -o $(BIN) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $<  -o $@

run: all
	./$(BIN)

clean:
	rm -f $(BIN) $(OBJS)
