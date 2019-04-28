CXX		  := g++
CXX_FLAGS := -Wall -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib
LFLAGS	= -lncurses -pthread


LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE).out

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES) $(LFLAGS)

clean:
	-rm $(BIN)/*
