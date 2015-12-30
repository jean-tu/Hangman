CXX=g++
CXXFLAGS=-g -Wall 

all: hangman

hangman: hangman.cpp bin/.dirstamp
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ hangman.cpp


bin/.dirstamp:
	mkdir -p  bin
	touch  bin/.dirstamp

.PHONY: clean 
clean: 
	rm hangman
	-@echo "--- All Clean!---"
