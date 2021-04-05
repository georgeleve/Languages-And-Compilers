Compilers Project CS340 Phase 2
@authors    
Georgios Gerasimos Leventopoulos csd4152     
Konstantinos Anemozalis csd4149  
Theofanis Tsesmetzis csd4142
---------------------------------------------------------------
FOR YACC/BISON

bison --yacc --defines --output=parser.cpp parser.y

flex --outfile=scanner.cpp scanner.l

g++ -o calc scanner.cpp parser.cpp

./calc

---------------------------------------------------------------
TURNIN COMMAND:                 turnin submit2@hy340 <dir>

VERIFY TURNIN:                    ls -l ~hy340/TURNIN/submit2
---------------------------------------------------------------