all:
	flex --outfile=scanner.cpp lex.l
	g++ -o scanner scanner.cpp
stdout:
	flex --outfile=scanner.cpp lex.l
	g++ -o scanner scanner.cpp
	./scanner input.txt
file:
	flex --outfile=scanner.cpp lex.l
	g++ -o scanner scanner.cpp
	./scanner input.txt output.txt
clean:
	rm -rf scanner.cpp
	rm -rf scanner