TARGET=Exec_4
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLADS=$(PTHREAD) -export-dynamic
OBJS=Exec_4.cpp
all:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)