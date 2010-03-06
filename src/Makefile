main: Progtalk

Scanner.cc: Scanner.l Scanner.h
	flex++ -o $@ $<

parse.cc: Parser.y
	bisonc++ $<

Progtalk: parse.o Scanner.o Progtalk.o Timestamp.o
	g++ -o $@ $? -lfl

clean:
	rm -rf *.o parse.cc *.ih Parserbase.h
