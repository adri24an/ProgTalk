main: Progtalk

Scanner.cc: Scanner.l Scanner.h
	flex++ -o $@ $<

parse.cc: Parser.y
	bisonc++ $<

Progtalk: parse.o Scanner.o Progtalk.o ListaEventos.o Evento.o
	g++ -o $@ $? -lfl

clean:
	rm -rf *.o *.cc *.ih Parserbase.h
