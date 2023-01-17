typecheck: parsetest.o tiger.tab.o lex.yy.o errormsg.o util.o ast.o driver.o
	g++ -o typecheck -g parsetest.o tiger.tab.o lex.yy.o errormsg.o util.o  ast.o driver.o

driver.o: driver.cc driver.hh
	g++ -g -c driver.cc

ast.o: ast.cpp ast.h
	g++ -g -c ast.cpp

parsetest.o: parsetest.c errormsg.h util.h
	g++ -g -c parsetest.c

tiger.tab.o: tiger.tab.cc
	g++ -g -c tiger.tab.cc

tiger.tab.cc: tiger.yy
	bison -dv tiger.yy -Wcounterexamples

tiger.tab.hh: tiger.tab.cc
	echo "tiger.tab.hh was created at the same time as tiger.tab.cc"

errormsg.o: errormsg.c errormsg.h util.h
	g++ -g -c errormsg.c

lex.yy.o: lex.yy.c tiger.tab.hh errormsg.h util.h
	g++ -g -c lex.yy.c

lex.yy.c: tiger.lex
	lex tiger.lex

util.o: util.c util.h
	g++ -g -c util.c

clean: 
	rm -f a.out util.o parsetest.o lex.yy.o errormsg.o tiger.tab.cc tigger.tab.hh tiger.tab.o absyn.o ast.o

