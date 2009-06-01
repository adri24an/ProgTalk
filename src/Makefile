main: Progtalk

Scanner.cc: Scanner.l Scanner.h
	flex++ -o $@ $<

parse.cc Scanner.h: Parser.y
	bisonc++ $<

Progtalk: parse.o Scanner.o Progtalk.o
	g++ -o $@ $? -lfl

clean:
	rm -rf *.o *.cc *.h *.ih
