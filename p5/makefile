CXX		  := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib
LFLAGS	= -lncurses


LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE).out

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE)  $^ -o $@ $(LIBRARIES) $(LFLAGS)

clean:
	-rm $(BIN)/*
