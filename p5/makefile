CFLAGS	= -Wall -std=c++17 -g -DDEBUG -I ../include
LFLAGS	= -lncurses
CC	    = g++
BIN		=bin
OBJ=$(BIN)
SRC=src

srcs = $(wildcard src/*.cpp)
objs = $(srcs:%.cpp=%.o)
#objs:=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(srcs))
deps = $(srcs:.cpp=.d)

bin/a.out:$(objs)
	$(CC) $^ -o $@ $(LFLAGS)

bin/%.o:%.cpp

bin/%.o:%.cpp
	$(CC) -MMD -MP $(CFLAGS) -c $< -o $@

.PHONY: clean

# $(RM) is rm -f by default

clean:
	$(RM) $(objs) $(deps) bin/a.out core


-include $(deps)

