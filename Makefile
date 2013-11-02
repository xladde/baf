#
# Makefile for BAF prototype
#
# author: 	t.j.
# version:	2013-09
#
# To compile with c++ 11

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

SRCDIR=./src
BINDIR=./bin
DOCDIR=./doc
DEVDIR=$(SRCDIR)/dev
ENCDIR=$(SRCDIR)/enc

DEP=\
	main.o \
	AbstractDevice.o \
	AbstractEncoder.o \
	CharacterDevice.o \
	NumericEncoder.o \
	XDevice.o\
	shared.o
	

# BUILD OPTIONS --------------------------------------------------------------
.PHONY: quick
quick: $(DEP)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(NAME) $(DEP) $(CXXLIBS) 

.PHONY: tex
tex: $(DOCDIR)/tex/index.tex
	pdflatex --file-line-error -output-directory=$(DOCDIR)/tex/ $(DOCDIR)/tex/index.tex
	pdflatex -output-directory=$(DOCDIR)/tex/ $(DOCDIR)/tex/index.tex
	rm texput.log

.PHONY: documentation
documentation:
	doxygen doxy-1.7.6.1.conf

.PHONY: clean
clean:
	clear
	sudo rm *.o
	sudo rm -r $(DOCDIR)/srcdoc/*
#	sudo rm -r $(DOCDIR)/man/*


.PHONY: all
all: $(DEP)
	make quick
	doxygen doxy-1.7.6.1.conf
	rm *.o
	strip $(BINDIR)/$(NAME)

# BUILD OBJECTS --------------------------------------------------------------
main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o main.o $(CXXLIBS)

AbstractDevice.o: $(DEVDIR)/AbstractDevice.cpp $(DEVDIR)/AbstractDevice.h 
	$(CXX) $(CXXFLAGS) -c $(DEVDIR)/AbstractDevice.cpp -o AbstractDevice.o $(CXXLIBS)

AbstractEncoder.o: $(ENCDIR)/AbstractEncoder.cpp $(ENCDIR)/AbstractEncoder.h 
	$(CXX) $(CXXFLAGS) -c $(ENCDIR)/AbstractEncoder.cpp -o AbstractEncoder.o $(CXXLIBS)


# CONCRETE IMPLEMENTATIONS ---------------------------------------------------
## DEVICES
CharacterDevice.o: $(DEVDIR)/CharacterDevice.cpp $(DEVDIR)/CharacterDevice.h $(DEVDIR)/AbstractDevice.h 
	$(CXX) $(CXXFLAGS) -c $(DEVDIR)/CharacterDevice.cpp -o CharacterDevice.o $(CXXLIBS)

XDevice.o: $(DEVDIR)/XDevice.cpp $(DEVDIR)/XDevice.h $(DEVDIR)/CharacterDevice.h $(ENCDIR)/NumericEncoder.h
	$(CXX) $(CXXFLAGS) -c $(DEVDIR)/XDevice.cpp -o XDevice.o $(CXXLIBS)

## ENCODER
NumericEncoder.o: $(ENCDIR)/NumericEncoder.cpp $(ENCDIR)/NumericEncoder.h $(ENCDIR)/AbstractEncoder.h 
	$(CXX) $(CXXFLAGS) -c $(ENCDIR)/NumericEncoder.cpp -o NumericEncoder.o $(CXXLIBS)

# SHARED LIBRARIES -----------------------------------------------------------
shared.o: $(SRCDIR)/shared.cpp $(SRCDIR)/shared.h
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/shared.cpp -o shared.o $(CXXLIBS)