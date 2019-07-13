## Developer: Babak Poursartip
## Latest update:  July 12, 2019

## variables ==================================================================
## Name of the executable
NAME = Geriatrix

## Complier
CC = g++

## Source extension
SEXT = cpp

## Source directory
SDIR = .

## Output directory
ODIR = .

## Library directory
LIBS = -L/usr/local/lib

## Include directory
INC = -I./

## compile option
CFLAGS = -Wall -Wextra -pedantic -std=c++14

## Release option
RFLAGS = -O2

## DO NOT CHANGE ################################################
.PHONY: all clean dep test help

TARGET = $(ODIR)/$(NAME)
SRCS = $(wildcard $(SDIR)/*.$(SEXT))
OBJS = $(SRCS:.$(SEXT)=.o)

all : $(TARGET)

	@echo "creaing the object files ..."
$(TARGET): $(OBJS)
	$(CC) $(LIBS) $(OBJS) -o $(TARGET) 
	# rm $(OBJS) # uncomment if you want to remove the object files 

	@echo "compiling the code ..."
$(OBJS): $(SRCS)
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(RFLAGS) $(INC) -c $(SRCS)

cln:
	@echo "cleaning the folder ..."
	rm $(TARGET)
	rm *.o

test:
	@echo "Sources are: " $(SRCS)
	@echo "Objects are: " $(OBJS)
help:
	@echo "usage:"
	@echo "      make -> build"
	@echo "      make dep -> generates dependencies using gccmakedep"
	@echo "      make cln -> removes objects, executable"
	@echo "      make test -> lists source files"
dep :
	gccmakedep $(INC) $(SRCS)
#################################################################
