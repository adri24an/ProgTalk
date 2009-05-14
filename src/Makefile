main: programa

lex.yy.cc: scanner.l
	flex $<

lex.yy.o: lex.yy.cc
	g++ -c $<

y.tab.c: parser.y
	bison -d $< -o $@

y.tab.o: y.tab.c
	gcc -c $<

programa: y.tab.o lex.yy.o
	gcc -o $@ $< -lfl

clean:
	rm -rf *.o y.tab.* lex.yy.*

