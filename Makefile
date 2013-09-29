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

DEP=\
	main.o \
	AbstractDevice.o \
	CharacterDevice.o \
	NumericEncoder.o
	

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
	sudo rm -r $(DOCDIR)/html/*
	sudo rm -r $(DOCDIR)/man/*


.PHONY: all
all: $(DEP)
	make quick
	doxygen doxy-1.7.6.1.conf
	rm *.o
	strip $(BINDIR)/$(NAME)

# BUILD OBJECTS --------------------------------------------------------------
main.o: $(SRCDIR)/main.cpp $(SRCDIR)/main.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o main.o $(CXXLIBS)

AbstractDevice.o: $(SRCDIR)/AbstractDevice.cpp $(SRCDIR)/AbstractDevice.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/AbstractDevice.cpp -o AbstractDevice.o $(CXXLIBS)



# CONCRETE IMPLEMENTATIONS ---------------------------------------------------
CharacterDevice.o: $(SRCDIR)/dev/CharacterDevice.cpp $(SRCDIR)/dev/CharacterDevice.h $(SRCDIR)/AbstractDevice.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/dev/CharacterDevice.cpp -o CharacterDevice.o $(CXXLIBS)

NumericEncoder.o: $(SRCDIR)/enc/NumericEncoder.cpp $(SRCDIR)/enc/NumericEncoder.h $(SRCDIR)/AbstractEncoder.h 
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/enc/NumericEncoder.cpp -o NumericEncoder.o $(CXXLIBS)