CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = -g -std=c++11

SRCS = main.cpp tree.cpp tree.h node.h
OBJS = $(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o main $(OBJS) $(LDLIBS)

main.o: main.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) main
