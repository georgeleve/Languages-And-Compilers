# CS340
Compilers Project
Creating a C compiler in C++ for CS340 course at University of Crete.

@authors      Georgios Gerasimos Leventopoulos csd4152     Konstantinos Anemozalis csd4149   Theofanis Tsesmetzis csd4142

How to run it:

make stdout
diavazei apo to input.txt kai grafei sto stdout

make file
diavazei apo to input.txt kai grafei sto output.txt

make clean
diagrafei to scanner kai to scanner.cpp

make
paragei to ektelesimo arxeio scanner


Without Makefile:
flex --outfile scanner.cpp lex.l && g++ -o scanner scanner.cpp && ./scanner input.txt output.txt




TURNIN COMMAND:                 turnin submit2@hy340 <dir>

VERIFY TURNIN:                    ls -l ~hy340/TURNIN/submit1
