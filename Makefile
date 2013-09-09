#
# Makefile for BAF prototype
#
# author: 	t.j.
# version:	2013-09
#

# BUILD CONFIGURATIONS -------------------------------------------------------
NAME=baf

CXX=g++

CXXFLAGS=\
	-Wall\
	-ggdb

CXXLIBS=\
	-lpthread\
	-lstdc++\
	-std=c++0x
LXX=ld

SRCDIR=./src
BINDIR=./bin
DOCDIR=./doc

DEP=\
	main.o \
	Controller.o \
	AbstractDriver.o \
	AbstractProtocol.o \
	AbstractDevice.o 

# BUILD OPTIONS --------------------------------------------------------------
.PHONY: quick
quick: $(DEP)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(NAME) $(DEP) $(CXXLIBS) 

.PHONY: documentation
documentation:
	doxygen doxy-1.7.6.1.conf

.PHONY: clean
clean:
	clear
	sudo rm *.o

.PHONY: all
all: $(DEP)
	make quick
	doxygen doxy-1.7.6.1.conf
	rm *.o
	strip $(BINDIR)/$(NAME)

# BUILD OBJECTS --------------------------------------------------------------
main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o main.o $(CXXLIBS)

Controller.o: $(SRCDIR)/Controller.cpp $(SRCDIR)/Controller.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Controller.cpp -o Controller.o $(CXXLIBS)

# Core and abstract objects		
AbstractDriver.o: $(SRCDIR)/AbstractDriver.cpp $(SRCDIR)/AbstractDriver.h\
	$(SRCDIR)/AbstractDevice.h $(SRCDIR)/Controller.h  $(SRCDIR)/AbstractProtocol.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/AbstractDriver.cpp -o AbstractDriver.o $(CXXLIBS)

AbstractDevice.o: $(SRCDIR)/AbstractDevice.cpp $(SRCDIR)/AbstractDevice.h\
	$(SRCDIR)/AbstractDriver.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/AbstractDevice.cpp -o AbstractDevice.o $(CXXLIBS)

AbstractProtocol.o: $(SRCDIR)/AbstractProtocol.cpp $(SRCDIR)/AbstractProtocol.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/AbstractProtocol.cpp -o AbstractProtocol.o $(CXXLIBS)

# CONCRETE IMPLEMENTATIONS ---------------------------------------------------
