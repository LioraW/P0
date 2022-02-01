CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS = -g #$(shell root-config --cflags)
#LDFLAGS=-g $(shell root-config --ldflags)
#LDLIBS=$(shell root-config --libs)

SRCS = main.cpp tree.cpp tree.h node.h
OBJS = $(subst .cc,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o main $(OBJS) $(LDLIBS)

main.o: main.cpp

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) tool
