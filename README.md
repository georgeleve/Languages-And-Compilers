# CS340
Compilers Project
Creating a C compiler in C++ for CS340 course at University of Crete.

@authors      Georgios Gerasimos Leventopoulos     Konstantinos Anemozalis    Theofanis Tsesmetzis

How to run it:

1st command: flex --outfile scanner.cpp lex.l

2nd command: g++ -o scanner scanner.cpp

3rd command: ./scanner

flex --outfile scanner.cpp lex.l && g++ -o scanner scanner.cpp

full crap:
flex --outfile scanner.cpp lex.l && g++ -o scanner scanner.cpp && ./scanner input.txt output.txt

TO DO:
1) Sto gamo header file to type na to kanete enum. done
2) Na oloklirosete ola ta vector pushback  done
3) NA KRATISETE BACKUP TA PROTA 2 
4) HANDLE TA COMMENTS
5) HANDLE TA STRINGS
6) O LEVE NA FTIAKSEI TIN MAIN ANTHROPINI
7)O KWSTAS NA MATHEI TO ARGV 2

PROERETIKO) AN SAS VGEI na kanete to token output stream overload gia na to tiponoume xoris karkino (SPOUTSAMAS)


na ftiaksoume to ident