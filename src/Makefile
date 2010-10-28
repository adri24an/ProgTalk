CPPFLAGS=-g -Wall -Wextra

main: Progtalk

rebuild: clean main

Scanner.cc: Scanner.l Scanner.h
	flex++ -o $@ $<

parse.cc: Parser.y
	bisonc++ -V $<

Progtalk: parse.o Scanner.o Progtalk.o Timestamp.o MSC.o Instance.o Message.o Event.o Timeref.o Timestg.o Absolute.o Relative.o Sending.o Receipt.o MSCVisitor.o PrettyPrinting.o TimeChecker.o
	g++ -o $@ $? -lfl

clean:
	rm -rf *.o parse.cc *.ih Parserbase.h Progtalk
