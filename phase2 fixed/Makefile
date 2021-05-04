all:	scanner.cpp parser.cpp
	g++ -g -o calc scanner.cpp parser.cpp

scanner.cpp:	scanner.l
	flex --outfile=scanner.cpp scanner.l
	
parser.cpp:		parser.y
	bison -v --yacc --defines --output=parser.cpp parser.y
	 
clean:	parser.output parser.cpp parser.hpp calc scanner.cpp
	rm -f scanner.hpp parser.output parser.cpp parser.hpp calc scanner.cpp