CFLAGS	= -Wall -std=c++11 -g -DDEBUG -I ../include
LFLAGS	= -lncurses
CC	    = g++

srcs = $(wildcard src/*.cpp)
objs = $(srcs:.cpp=.o)
deps = $(srcs:.cpp=.d)

a.out: $(objs)
	$(CC) $^ -o $@ $(LFLAGS)



%.o: %.cpp
	$(CC) -MMD -MP $(CFLAGS) -c $< -o $@

.PHONY: clean

# $(RM) is rm -f by default

clean:
	$(RM) $(objs) $(deps) a.out core


-include $(deps)

