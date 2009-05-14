main: programa

lex.yy.c: scanner.l
	flex $<

lex.yy.o: lex.yy.c
	gcc -c $<

parser.c: parser.y
	bison -d $< -o $@

parser.o: parser.c
	gcc -c $<

programa: parser.o lex.yy.o
	gcc -o $@ $< -lfl

clean:
	rm -rf *.o parser.c parser.o lex.yy.*